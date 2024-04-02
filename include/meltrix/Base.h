//
// Created by Eryk Majoch on 02/04/2024.
//

#pragma once

#include <vector>
#include <utility>
#include <exception>
#include <iostream>

namespace Meltrix {

    template <typename T>
    class Base {
    public:
        static_assert(std::is_arithmetic<T>::value, "Elements must be of arithmetic type");

        // Constructors
        Base() = default;

        // Common interfaces
        short rows();
        short columns();

        // Accessors
        T& operator()(short _row, short _column);
        const T& operator()(short _row, short _column) const;

        // Destructor
        virtual ~Base() = default;

    protected:
        short m_Rows = 0;
        short m_Columns = 0;
        std::vector<T> m_Data = {};
    };

}
