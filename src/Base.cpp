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

    // Accessors
    template <typename T>
    T& Base<T>::operator()(short _row, short _column) {
        if (_row > m_Rows || _row < 0 || _column > m_Columns || _column < 0) {
            throw std::out_of_range("Provided dimensions are out of range");
        }
        return m_Data[_row * m_Rows + _column];
    }

    template <typename T>
    const T& Base<T>::operator()(short _row, short _column) const {
        if (_row > m_Rows || _row < 0 || _column > m_Columns || _column < 0) {
            throw std::out_of_range("Provided dimensions are out of range");
        }
        return m_Data[_row * m_Rows + _column];
    }

}


// Explicit instantiation as a workaround for breaking the definitions up
template class Meltrix::Base<int>;
template class Meltrix::Base<float>;
template class Meltrix::Base<double>;
