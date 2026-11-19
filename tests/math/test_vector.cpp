#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_approx.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>
#include "math/vector.h"
#include "test_helpers.h"

using Catch::Matchers::WithinAbs;

TEST_CASE("Vector addition", "[vector][math]") {
    math::Vector v1(3, 4, 0);
    math::Vector v2(4, -3, 0);
    math::Vector result = v1 + v2;

    requireVectorsEqual(result, math::Vector(7, 1, 0));
}

TEST_CASE("Vector addition in 3D", "[vector][math]") {
    math::Vector v1(3, 4, 1);
    math::Vector v2(4, -3, 2);
    math::Vector result = v1 + v2;

    requireVectorsEqual(result, math::Vector(7, 1, 3));
}

TEST_CASE("Vector subtraction", "[vector][math]") {
    math::Vector v1(4, 5, 0);
    math::Vector v2(1, 1, 0);
    math::Vector result1 = v1 - v2;

    requireVectorsEqual(result1, math::Vector(3, 4, 0));

    math::Vector v3(4, 5, 6);
    math::Vector v4(1, 1, 2);
    math::Vector result2 = v3 - v4;

    requireVectorsEqual(result2, math::Vector(3, 4, 4));
}

TEST_CASE("Vector scalar multiplication", "[vector][math]") {
    math::Vector v(3, -4, 1);
    math::Vector result = 2.0 * v;

    requireVectorsEqual(result, math::Vector(6, -8, 2));
}

TEST_CASE("Vector scalar division", "[vector][math]") {
    math::Vector v(6, -8, 2);
    math::Vector result = v / 2.0;

    requireVectorsEqual(result, math::Vector(3, -4, 1));
}

TEST_CASE("Ray equation O + t * D", "[vector][math]") {
    math::Vector O(0, 8, 0);
    math::Vector D(3, -4, 0);
    double t = 2;
    math::Vector result = O + t * D;

    requireVectorsEqual(result, math::Vector(6, 0, 0));
}

TEST_CASE("Vector dot product", "[vector][math]") {
    REQUIRE(math::Vector(3, 4, 0).dot(math::Vector(4, 3, 0)) == 24);
    REQUIRE(math::Vector(3, 4, 0).dot(math::Vector(4, -3, 0)) == 0);
    REQUIRE(math::Vector(3, 4, 12).dot(math::Vector(4, 3, 1)) == 36);
}

TEST_CASE("Vector length", "[vector][math]") {
    REQUIRE(math::Vector(3, -4, 0).length() == 5);
    REQUIRE(math::Vector(3, 4, 12).length() == 13);
}

TEST_CASE("Vector normalisation", "[vector][math]") {
    math::Vector v(3, 4, 0);
    requireVectorsEqual(v.normalised(), math::Vector(3.0 / 5.0, 4.0 / 5.0, 0.0));

    math::Vector result = math::Vector(3, -4, 0).normalised();

    requireVectorsEqual(result, math::Vector(0.6, -0.8, 0));

    REQUIRE_THAT(math::Vector(3, 4, 12).normalised().length(), WithinAbs(1.0, tolerance));
}
