//
// Created by Eryk Majoch on 10/04/2024.
//

#pragma once

#include "Base.h"

namespace Meltrix {

    template <typename T>
    class Vector : public Base<T> {
    public:
        static_assert(std::is_arithmetic<T>::value, "Elements must be of arithmetic type");

        // Constructors
        Vector() = default;
        Vector(short rows, short columns);
        Vector(short rows, short columns, std::vector<T> data);

        // Special initialisers
        static Vector<T> Zero(short rows, short columns);
        static Vector<T> One(short rows, short columns);

        // Scalar operations
        Vector<T> operator+(T scalar) const;
        Vector<T> operator-(T scalar) const;
        Vector<T> operator*(T scalar) const;
        Vector<T> operator/(T scalar) const;

        // Destructor
        ~Vector() override = default;

    };

}
