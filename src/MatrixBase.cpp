#include "MatrixBase.h"

namespace meltrix {

    Matrix::Matrix(int rows, int cols)
    {
        if (rows <= 0 || cols <= 0) {
            throw std::invalid_argument("Matrix dimensions must be greater than 0");
        }
        m_Rows = rows;
        m_Cols = cols;
        m_Data.resize(rows * cols);
    }

    Matrix::Matrix(int rows, int cols, const double& value)
    {
        if (rows <= 0 || cols <= 0) {
            throw std::invalid_argument("Matrix dimensions must be greater than 0");
        }
        m_Rows = rows;
        m_Cols = cols;
        m_Data.resize(rows * cols, value);
    }

    Matrix::Matrix(int rows, int cols, const std::vector<double>& data)
    {
        if (rows <= 0 || cols <= 0) {
            throw std::invalid_argument("Matrix dimensions must be greater than 0");
        }
        if (data.size() != (rows * cols)) {
            throw std::invalid_argument("Data size must match matrix dimensions");
        }
        m_Rows = rows;
        m_Cols = cols;
        m_Data = data;
    }

    Matrix::Matrix(const Matrix& other)
    {
        m_Rows = other.m_Rows;
        m_Cols = other.m_Cols;
        m_Data = other.m_Data;
    }

    // ============================= //
    // ===== MATRIX COMPARISON ===== //
    // ============================= //

    bool Matrix::operator==(const Matrix &other) const {
        return m_Rows == other.m_Rows && m_Cols == other.m_Cols && m_Data == other.m_Data;
    }

    bool Matrix::operator!=(const Matrix &other) const {
        return !(m_Rows == other.m_Rows && m_Cols == other.m_Cols && m_Data == other.m_Data);
    }

    // ============================= //
    // ===== SCALAR OPERATIONS ===== //
    // ============================= //

    Matrix Matrix::operator+(const double &scalar) const
    {
        std::vector<double> newData = std::vector<double>(m_Rows * m_Cols);
        std::transform(m_Data.begin(), m_Data.end(), newData.begin(), [&](double n){return n + scalar;});
        return Matrix{m_Rows, m_Cols, newData};
    }

    Matrix Matrix::operator-(const double &scalar) const
    {
        std::vector<double> newData = std::vector<double>(m_Rows * m_Cols);
        std::transform(m_Data.begin(), m_Data.end(), newData.begin(), [&](double n){return n - scalar;});
        return Matrix{m_Rows, m_Cols, newData};
    }

    Matrix Matrix::operator*(const double &scalar) const
    {
        std::vector<double> newData = std::vector<double>(m_Rows * m_Cols);
        std::transform(m_Data.begin(), m_Data.end(), newData.begin(), [&](double n){return n * scalar;});
        return Matrix{m_Rows, m_Cols, newData};
    }

    Matrix Matrix::operator/(const double &scalar) const
    {
        if (scalar == 0) {
            throw std::invalid_argument("Cannot divide elements by 0");
        }
        std::vector<double> newData = std::vector<double>(m_Rows * m_Cols);
        std::transform(m_Data.begin(), m_Data.end(), newData.begin(), [&](double n){return n / scalar;});
        return Matrix{m_Rows, m_Cols, newData};
    }

    void Matrix::operator+=(const double &scalar)
    {
        std::transform(m_Data.begin(), m_Data.end(), m_Data.begin(), [&](double n){return n + scalar;});
    }

    void Matrix::operator-=(const double &scalar)
    {
        std::transform(m_Data.begin(), m_Data.end(), m_Data.begin(), [&](double n){return n - scalar;});
    }

    void Matrix::operator*=(const double &scalar)
    {
        std::transform(m_Data.begin(), m_Data.end(), m_Data.begin(), [&](double n){return n * scalar;});
    }

    void Matrix::operator/=(const double &scalar)
    {
        if (scalar == 0) {
            throw std::invalid_argument("Cannot divide elements by 0");
        }
        std::transform(m_Data.begin(), m_Data.end(), m_Data.begin(), [&](double n){return n / scalar;});
    }

    // ============================= //
    // ===== MATRIX OPERATIONS ===== //
    // ============================= //

    Matrix Matrix::operator+(const Matrix &other) const
    {
        if (m_Rows != other.m_Rows || m_Cols != other.m_Cols) {
            throw std::invalid_argument("Matrix dimensions must match");
        }
        std::vector<double> newData = std::vector<double>(m_Rows * m_Cols);
        for (int i = 0; i < m_Data.size(); i++) {
            newData.push_back(m_Data[i] + other.m_Data[i]);
        }
        return Matrix{m_Rows, m_Cols, newData};
    }

    Matrix Matrix::operator-(const Matrix &other) const
    {
        if (m_Rows != other.m_Rows || m_Cols != other.m_Cols) {
            throw std::invalid_argument("Matrix dimensions must match");
        }
        std::vector<double> newData = std::vector<double>(m_Rows * m_Cols);
        for (int i = 0; i < m_Data.size(); i++) {
            newData.push_back(m_Data[i] - other.m_Data[i]);
        }
        return Matrix{m_Rows, m_Cols, newData};
    }

    void Matrix::operator+=(const Matrix &other)
    {
        if (m_Rows != other.m_Rows || m_Cols != other.m_Cols) {
            throw std::invalid_argument("Matrix dimensions must match");
        }
        for (int i = 0; i < m_Data.size(); i++) {
            m_Data[i] += other.m_Data[i];
        }
    }

    void Matrix::operator-=(const Matrix &other)
    {
        if (m_Rows != other.m_Rows || m_Cols != other.m_Cols) {
            throw std::invalid_argument("Matrix dimensions must match");
        }
        for (int i = 0; i < m_Data.size(); i++) {
            m_Data[i] -= other.m_Data[i];
        }
    }

    // ============================= //
    // ===== ACCESSOR METHODS ====== //
    // ============================= //

    double& Matrix::operator()(int row, int col)
    {
        if (row < 0 || row >= m_Rows || col < 0 || col >= m_Cols) {
            throw std::invalid_argument("Index out of bounds");
        }
        return m_Data[row * m_Cols + col];
    }

    Matrix Matrix::getRow(int row)
    {
        if (row < 0 || row >= m_Rows) {
            throw std::invalid_argument("Index out of bounds");
        }
        std::vector<double> newData = std::vector<double>(m_Cols);
        for (int i = 0; i < m_Cols; i++) {
            newData.push_back(m_Data[row * m_Cols + i]);
        }
        return Matrix{1, m_Cols, newData};
    }

    Matrix Matrix::getCol(int col)
    {
        if (col < 0 || col >= m_Cols) {
            throw std::invalid_argument("Index out of bounds");
        }
        std::vector<double> newData = std::vector<double>(m_Rows);
        for (int i = 0; i < m_Rows; i++) {
            newData.push_back(m_Data[i * m_Cols + col]);
        }
        return Matrix{m_Rows, 1, newData};
    }

    Matrix Matrix::getSubMatrix(int row, int col)
    {
        if (row < 0 || row > m_Rows || col < 0 || col > m_Cols) {
            throw std::invalid_argument("Index out of bounds");
        }
        if (m_Rows == 1 || m_Cols == 1) {
            throw std::invalid_argument("Cannot get sub-matrix from current matrix");
        }
        std::vector<double> newData = {};
        for (int i = 0; i < m_Rows; i++) {
            for (int j = 0; j < m_Cols; j++) {
                if (i == row || j == col) {
                    continue;
                } else {
                    newData.push_back(m_Data[i * m_Cols + j]);
                }
            }
        }
        return Matrix{m_Rows - 1, m_Cols - 1, newData};
    }

    // ============================= //
    // ===== MATRIX FUNCTIONS ====== //
    // ============================= //

    Matrix Matrix::dot(Matrix& other)
    {
        if (m_Cols != other.m_Rows) {
            throw std::invalid_argument("Matrix dimensions must match");
        }
//        Matrix result(m_Rows, other.m_Cols);
        std::vector<double> newData = {};
        for (int i = 0; i < m_Rows; i++) {
            for (int j = 0; j < other.m_Cols; j++) {
                double sum = 0;
                for (int k = 0; k < m_Cols; k++) {
                    sum += m_Data[i * m_Cols + k] * other.m_Data[k * other.m_Cols + j];
                }
//                result(i, j) = sum;
                newData.push_back(sum);
            }
        }
        return Matrix{m_Rows, other.m_Cols, newData};
    }

    void Matrix::apply(const std::function<double(double)>& func) {
        std::transform(m_Data.begin(), m_Data.end(), m_Data.begin(), func);
    }

    void Matrix::transpose()
    {
        std::vector<double> newData = {};
        for (int col = 0; col < m_Cols; col++) {
            for (int row = 0; row < m_Rows; row++) {
                newData.push_back(m_Data[row * m_Cols + col]);
            }
        }
        std::swap(m_Rows, m_Cols);
        m_Data = newData;
    }

    double Matrix::determinant()
    {
        if (m_Rows != m_Cols) {
            throw std::invalid_argument("Matrix must be square");
        }
        double det = 0.0;
        switch (m_Rows) {
            case 1:
                det = m_Data[0];
                break;
            case 2:
                det = m_Data[0] * m_Data[3] - m_Data[1] * m_Data[2];
                break;
            default:
                for (int i = 0; i < m_Rows; i++) {
                    Matrix sub = getSubMatrix(0, i);
                    det += pow(-1, i) * m_Data[i] * sub.determinant();
                }
                break;
        }
        return det;
    }

    // ============================= //
    // ===== UTILITY FUNCTIONS ===== //
    // ============================= //

    void Matrix::print() const
    {
        int maxLen = 0;
        for (double x : m_Data) {
            std::string str = std::to_string(x);
            str.erase ( str.find_last_not_of('0') + 1, std::string::npos );
            str.erase ( str.find_last_not_of('.') + 1, std::string::npos );
            int len = static_cast<int>(str.length());
            maxLen = std::max(maxLen, len);
        }
        std::cout << "┌ " << std::setw(maxLen * m_Cols + m_Cols - 1) << " " << " ┐\n";
        for (int i = 0; i < m_Rows; i++) {
            std::cout << "│ ";
            for (int j = 0; j < m_Cols; j++) {
                std::cout << std::setw(maxLen) << m_Data[i * m_Cols + j] << " ";
            }
            std::cout << "│\n";
        }
        std::cout << "└ " << std::setw(maxLen * m_Cols + m_Cols - 1) << " " << " ┘\n";
    }

    std::pair<int, int> Matrix::shape()
    {
        return std::pair{m_Rows, m_Cols};
    }

} // meltrix