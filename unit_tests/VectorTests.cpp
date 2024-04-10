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

    SECTION("Copy constructor") {
        Vector<int> v = Vector<int>(3, 1, {4, 5, 6});
        Vector<int> b = v;
        REQUIRE(b == Vector<int>(3, 1, {4, 5, 6}));
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

    SECTION("Checking empty function") {
        Vector<double> e = Vector<double>(1, 3, {0.009, 0.002, 0.000001});
        REQUIRE_FALSE(e.isEmpty());
        REQUIRE(e.isEmpty(0.01));

    }

    SECTION("Checking accessor operators") {
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

    SECTION("Checking function application") {
        v.apply([](float x){return std::sin(x);});
        REQUIRE_THAT(v(0,0), Catch::Matchers::WithinRel(0.808496, default_margin));
        REQUIRE_THAT(v(0,1), Catch::Matchers::WithinRel(0.0415807, default_margin));
        REQUIRE_THAT(v(0,2), Catch::Matchers::WithinRel(-0.75876, default_margin));
        REQUIRE_THAT(v(0,3), Catch::Matchers::WithinRel(-0.753379, default_margin));
    }

    SECTION("Checking inline scalar operators") {
        v += 2.0;
        REQUIRE_THAT(v(0,0), Catch::Matchers::WithinRel(4.2, default_margin));
        REQUIRE_THAT(v(0,1), Catch::Matchers::WithinRel(5.1, default_margin));
        REQUIRE_THAT(v(0,2), Catch::Matchers::WithinRel(6.003, default_margin));
        REQUIRE_THAT(v(0,3), Catch::Matchers::WithinRel(7.43, default_margin));
    }

    SECTION("Checking returning scalar operators") {
        Vector<float> b = v - 3.0;
        REQUIRE_THAT(b(0,0), Catch::Matchers::WithinRel(-0.8, default_margin));
        REQUIRE_THAT(b(0,1), Catch::Matchers::WithinRel(0.1, default_margin));
        REQUIRE_THAT(b(0,2), Catch::Matchers::WithinRel(1.003, default_margin));
        REQUIRE_THAT(b(0,3), Catch::Matchers::WithinRel(2.43, default_margin));

        REQUIRE_THROWS([&](){
            Vector<float> c = v / 0;
        }());
    }

}

TEST_CASE("Testing Vector class utilities") {
    using namespace Meltrix;

    SECTION("Zero initialiser") {
        Vector<int> m = Vector<int>::Zero(1,2);
        REQUIRE(m(0,0) == 0);
        REQUIRE(m(0,1) == 0);
    }

    SECTION("Zero initialiser") {
        Vector<int> m = Vector<int>::One(2,1);
        REQUIRE(m(0,0) == 1);
        REQUIRE(m(1,0) == 1);
    }

}
