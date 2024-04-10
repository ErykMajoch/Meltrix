//
// Created by Eryk Majoch on 02/04/2024.
//

#pragma once

#include <vector>
#include <utility>
#include <exception>
#include <algorithm>
#include <functional>
#include <iostream>
#include <iomanip>
#include <sstream>

namespace Meltrix {

    template <typename T>
    class Base {
    public:
        static_assert(std::is_arithmetic<T>::value, "Elements must be of arithmetic type");

        // Constructors
        Base() = default;
        Base(const Base<T>& other);

        // Common interfaces
        short rows();
        short columns();
        bool isEmpty(double delta = 0.001);

        void apply(std::function<T(T)> func);

        // Accessors
        T& operator()(short _row, short _column);
        const T& operator()(short _row, short _column) const;

        // Comparison operators
        bool operator==(const Base& other);
        bool operator!=(const Base& other);

        // Scalar operations
        void operator+=(T scalar);
        void operator-=(T scalar);
        void operator*=(T scalar);
        void operator/=(T scalar);

        // Utility
        std::pair<short, short> shape();
        void print(int precision = 5) const;

        // Destructor
        virtual ~Base() = default;

    protected:
        short m_Rows = 0;
        short m_Columns = 0;
        std::vector<T> m_Data = {};
    };

}
