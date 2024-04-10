//
// Created by Eryk Majoch on 10/04/2024.
//

#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>
#include "meltrix/Vector.h"

#include <utility>
#include <cmath>

const double default_margin = 0.001;

TEST_CASE("Vector class initialisation", "[Vector]") {
    using namespace Meltrix;

    SECTION("Rows and columns constructor") {
        REQUIRE_NOTHROW([&](){
            Vector<float> v = Vector<float>(1,2);
        }());
    }

    SECTION("Rows, columns and data constructor") {
        REQUIRE_NOTHROW([&](){
            Vector<int> v = Vector<int>(3, 1, {4, 5, 6});
        }());
    }

    SECTION("Invalid size initialisation") {
        REQUIRE_THROWS([&](){
            Vector<double> v = Vector<double>(2, 3);
        }());
    }

}

TEST_CASE("Vector class base utilities", "[Vector]") {
    using namespace Meltrix;
    Vector<float> v = Vector<float>(1, 4,
        {2.2, 3.1, 4.003, 5.43}
    );

    SECTION("Checking rows and columns") {
        short rows = v.rows();
        short columns = v.columns();
        REQUIRE(rows == 1);
        REQUIRE(columns == 4);
    }

    SECTION("Checking accessor operation") {
        float f = v(0, 1);
        REQUIRE_THAT(f, Catch::Matchers::WithinRel(3.1, default_margin));

        v(0,0) = 1.0;
        float g = v(0,0);
        REQUIRE_THAT(g, Catch::Matchers::WithinRel(1.0, default_margin));
    }

    SECTION("Checking comparison operators") {
        Vector<float> t = Vector<float>(1,4, {2.2, 3.1, 4.003, 5.43});
        REQUIRE(v == t);
        REQUIRE_FALSE(v != t);
    }

    SECTION("Checking shape function") {
        std::pair<short, short> s = std::make_pair(1, 4);
        REQUIRE(s == v.shape());
    }

}
