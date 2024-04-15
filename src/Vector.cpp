//
// Created by Eryk Majoch on 10/04/2024.
//

#include "meltrix/Vector.h"

namespace Meltrix {

    // Constructors
    template <typename T>
    Vector<T>::Vector(short rows, short columns) {
        if (!(rows == 1 || columns == 1)) {
            throw std::invalid_argument("A Vector object must be one dimensional");
        }
        this->m_Rows = rows;
        this->m_Columns = columns;
        this->m_Data.resize(rows * columns);
    }

    template <typename T>
    Vector<T>::Vector(short rows, short columns, std::vector<T> data) {
        if (!(rows == 1 || columns == 1)) {
            throw std::invalid_argument("A Vector object must be one dimensional");
        }
        this->m_Rows = rows;
        this->m_Columns = columns;
        this->m_Data = data;
    }

    // Special initialisers
    template <typename T>
    Vector<T> Vector<T>::Zero(short rows, short columns) {
        Vector<T> result(rows, columns);
        std::fill(result.m_Data.begin(), result.m_Data.end(), static_cast<T>(0));
        return result;
    }

    template <typename T>
    Vector<T> Vector<T>::One(short rows, short columns) {
        Vector<T> result(rows, columns);
        std::fill(result.m_Data.begin(), result.m_Data.end(), static_cast<T>(1));
        return result;
    }

    // Scalar operations
    template <typename T>
    void Vector<T>::operator+=(T scalar) {
        Base<T>::operator+=(scalar);
    }

    template <typename T>
    void Vector<T>::operator-=(T scalar) {
        Base<T>::operator-=(scalar);
    }

    template <typename T>
    void Vector<T>::operator*=(T scalar) {
        Base<T>::operator*=(scalar);
    }

    template <typename T>
    void Vector<T>::operator/=(T scalar) {
        Base<T>::operator/=(scalar);
    }

    template <typename T>
    Vector<T> Vector<T>::operator+(T scalar) const {
        Vector<T> result(*this);
        result.operator+(scalar);
        return result;
    }

    template <typename T>
    Vector<T> Vector<T>::operator-(T scalar) const {
        Vector<T> result(*this);
        result.operator-=(scalar);
        return result;
    }

    template <typename T>
    Vector<T> Vector<T>::operator*(T scalar) const {
        Vector<T> result(*this);
        result.operator*=(scalar);
        return result;
    }

    template <typename T>
    Vector<T> Vector<T>::operator/(T scalar) const {
        Vector<T> result(*this);
        result.operator/=(scalar);
        return result;
    }

    // Vector operations
    template <typename T>
    Vector<T> Vector<T>::operator+(const Vector<T>& other) {
        if (!(this->m_Rows == other.m_Rows && this->m_Columns == other.m_Columns)) {
            throw std::invalid_argument("Vector dimensions don't match");
        }
        Vector<T> result(*this);
        for (int i = 0; i < this->m_Data.size(); i++) {
            result.m_Data[i] += other.m_Data[i];
        }
        return result;
    }

    template <typename T>
    Vector<T> Vector<T>::operator-(const Vector<T>& other) {
        if (!(this->m_Rows == other.m_Rows && this->m_Columns == other.m_Columns)) {
            throw std::invalid_argument("Vector dimensions don't match");
        }
        Vector<T> result(*this);
        for (int i = 0; i < this->m_Data.size(); i++) {
            result.m_Data[i] -= other.m_Data[i];
        }
        return result;
    }

    template <typename T>
    void Vector<T>::operator+=(const Vector<T> &other) {
        if (!(this->m_Rows == other.m_Rows && this->m_Columns == other.m_Columns)) {
            throw std::invalid_argument("Vector dimensions don't match");
        }
        for (int i = 0; i < this->m_Data.size(); i++) {
            this->m_Data[i] += other.m_Data[i];
        }
    }

    template <typename T>
    void Vector<T>::operator-=(const Vector<T> &other) {
        if (!(this->m_Rows == other.m_Rows && this->m_Columns == other.m_Columns)) {
            throw std::invalid_argument("Vector dimensions don't match");
        }
        for (int i = 0; i < this->m_Data.size(); i++) {
            this->m_Data[i] -= other.m_Data[i];
        }
    }

}

// Explicit instantiation as a workaround for breaking up the definitions
template class Meltrix::Vector<int>;
template class Meltrix::Vector<float>;
template class Meltrix::Vector<double>;
