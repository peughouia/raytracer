#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>
#include "colour/colour.h"
#include "test_helpers.h"

using Catch::Matchers::WithinAbs;

TEST_CASE("Colour components", "[colour]") {
    Colour c(1, 0.5, 0);

    REQUIRE_THAT(c.r(), WithinAbs(1.0, tolerance));
    REQUIRE_THAT(c.g(), WithinAbs(0.5, tolerance));
    REQUIRE_THAT(c.b(), WithinAbs(0.0, tolerance));
}

TEST_CASE("Colour scalar multiplication", "[colour]") {
    requireColoursEqual(0.5 * Colour(1, 0.5, 0), Colour(0.5, 0.25, 0));
}
