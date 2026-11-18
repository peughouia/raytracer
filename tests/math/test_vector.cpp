#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_approx.hpp>
#include "math/vector.hpp"

TEST_CASE("Vector addition", "[vector][math]") {
    // (1, 2, 3) added to (4, 5, 6) should equal (5, 7, 9)
    math::Vector v1(1.0, 2.0, 3.0);
    math::Vector v2(4.0, 5.0, 6.0);
    math::Vector result = v1.add(v2);

    REQUIRE(result.x() == Catch::Approx(5.0));
    REQUIRE(result.y() == Catch::Approx(7.0));
    REQUIRE(result.z() == Catch::Approx(9.0));
}

TEST_CASE("Vector subtraction", "[vector][math]") {
    // (-1, 4, 0) minus (-5, 2, 1) should equal (4, 2, -1)
    math::Vector v1(-1.0, 4.0, 0.0);
    math::Vector v2(-5.0, 2.0, 1.0);
    math::Vector result = v1.subtract(v2);

    REQUIRE(result.x() == Catch::Approx(4.0));
    REQUIRE(result.y() == Catch::Approx(2.0));
    REQUIRE(result.z() == Catch::Approx(-1.0));
}
