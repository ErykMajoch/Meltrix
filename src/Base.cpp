//
// Created by Eryk Majoch on 02/04/2024.
//

#include "meltrix/Base.h"

namespace Meltrix {

    // Common interfaces
    template <typename T>
    short Base<T>::rows() {
        return m_Rows;
    }

    template <typename T>
    short Base<T>::columns() {
        return m_Columns;
    }

    template <typename T>
    bool Base<T>::isEmpty(double delta) {
        std::vector<T> dataCopy = m_Data;
        return std::all_of(dataCopy.begin(), dataCopy.end(),
           [delta](T i) {return std::abs(i) < delta;}
        );
    }

    // Accessors
    template <typename T>
    T& Base<T>::operator()(short _row, short _column) {
        if (_row > m_Rows || _row < 0 || _column > m_Columns || _column < 0) {
            throw std::out_of_range("Provided dimensions are out of range");
        }
        return m_Data[m_Columns * _row + _column];
    }

    template <typename T>
    const T& Base<T>::operator()(short _row, short _column) const {
        if (_row > m_Rows || _row < 0 || _column > m_Columns || _column < 0) {
            throw std::out_of_range("Provided dimensions are out of range");
        }
        return m_Data[m_Columns * _row + _column];
    }

    // Utility
    template <typename T>
    std::pair<short,short> Base<T>::shape() {
        return std::make_pair(m_Rows,m_Columns);
    }

    template <typename T>
    void Base<T>::print(int precision) const {
        // Determine the maximum width required for each column
        std::vector<int> columnWidths(m_Columns, 0);
        for (short row = 0; row < m_Rows; row += 1) {
            for (short col = 0; col < m_Columns; col += 1) {
                std::stringstream ss;
                ss << std::fixed << std::setprecision(precision) << this->operator()(row,col);
                columnWidths[col] = std::max(columnWidths[col], static_cast<int>(ss.str().length()));
            }
        }

        // Add extra space for the first column
        columnWidths.front() += 1;

        // Print the opening bracket and the first row
        std::cout << "⎡ ";
        for (short col = 0; col < m_Columns; col += 1) {
            std::cout << std::setw(columnWidths[col]) << std::fixed << std::setprecision(precision) << m_Data[col];
            if (col != m_Columns - 1) {
                std::cout << "  ";
            }
        }
        std::cout << "  ⎤" << std::endl;

        // Print the remaining rows
        for (short row = 1; row < m_Rows - 1; row += 1) {
            std::cout << "⎢ ";
            for (short col = 0; col < m_Columns; col += 1) {
                std::cout << std::setw(columnWidths[col]) << std::fixed << std::setprecision(precision) << this->operator()(row,col);
                if (col != m_Columns - 1) {
                    std::cout << "  ";
                }
            }
            std::cout << "  ⎥" << std::endl;
        }

        // Print the closing bracket
        std::cout << "⎣ ";
        for (short col = 0; col < m_Columns; col += 1) {
            std::cout << std::setw(columnWidths[col]) << std::fixed << std::setprecision(precision) << this->operator()(m_Rows - 1,col);
            if (col != m_Columns - 1) {
                std::cout << "  ";
            }
        }
        std::cout << "  ⎦" << std::endl;
    }

}

// Explicit instantiation as a workaround for breaking up the definitions
template class Meltrix::Base<int>;
template class Meltrix::Base<float>;
template class Meltrix::Base<double>;
