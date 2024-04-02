//
// Created by Eryk Majoch on 02/04/2024.
//

#include "meltrix/Base.h"

namespace Meltrix {

    template <typename T>
    short Base<T>::rows() {
        return m_Rows;
    }

    template <typename T>
    short Base<T>::columns() {
        return m_Columns;
    }

}


// Explicit instantiation as a workaround for breaking the definitions up
template class Meltrix::Base<int>;
template class Meltrix::Base<float>;
template class Meltrix::Base<double>;
