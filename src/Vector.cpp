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
    Vector<T> Vector<T>::operator+(T scalar) const {
        Vector<T> result(*this);
        result += scalar;
        return result;
    }

    template <typename T>
    Vector<T> Vector<T>::operator-(T scalar) const {
        Vector<T> result(*this);
        result -= scalar;
        return result;
    }

    template <typename T>
    Vector<T> Vector<T>::operator*(T scalar) const {
        Vector<T> result(*this);
        result *= scalar;
        return result;
    }

    template <typename T>
    Vector<T> Vector<T>::operator/(T scalar) const {
        Vector<T> result(*this);
        result /= scalar;
        return result;
    }


}


// Explicit instantiation as a workaround for breaking up the definitions
template class Meltrix::Vector<int>;
template class Meltrix::Vector<float>;
template class Meltrix::Vector<double>;
