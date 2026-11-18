#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_approx.hpp>
#include "math/vector.h"

TEST_CASE("Vector addition", "[vector][math]") {
    math::Vector v1(3, 4, 0);
    math::Vector v2(4, -3, 0);
    math::Vector result = v1 + v2;

    REQUIRE(result.x() == 7);
    REQUIRE(result.y() == 1);
    REQUIRE(result.z() == 0);
}

TEST_CASE("Vector addition tests z component", "[vector][math]") {
    math::Vector v1(3, 4, 1);
    math::Vector v2(4, -3, 2);
    math::Vector result = v1 + v2;

    REQUIRE(result.x() == 7);
    REQUIRE(result.y() == 1);
    REQUIRE(result.z() == 3);
}

TEST_CASE("Vector subtraction", "[vector][math]") {
    math::Vector v1(-1.0, 4.0, 0.0);
    math::Vector v2(-5.0, 2.0, 1.0);
    math::Vector result = v1.subtract(v2);

    REQUIRE(result.x() == Catch::Approx(4.0));
    REQUIRE(result.y() == Catch::Approx(2.0));
    REQUIRE(result.z() == Catch::Approx(-1.0));
}
