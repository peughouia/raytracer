#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>
#include "render/trace.h"
#include "test_helpers.h"

using math::Vector;
using Catch::Matchers::WithinAbs;

TEST_CASE("Trace ray against sphere", "[render][trace]") {
    Ray ray(Vector(0, 0, -1), Vector(0, 0, 1));
    Colour red(1, 0, 0);

    SECTION("Sphere centered at (0, 0, 9) gives red") {
        Sphere sphere(Vector(0, 0, 9), 5.0, red);
        Colour result = trace(ray, sphere);

        REQUIRE_THAT(result.r(), WithinAbs(1.0, tolerance));
        REQUIRE_THAT(result.g(), WithinAbs(0.0, tolerance));
        REQUIRE_THAT(result.b(), WithinAbs(0.0, tolerance));
    }

    SECTION("Sphere centered at (6, 0, 9) gives black") {
        Sphere sphere(Vector(6, 0, 9), 5.0, red);
        Colour result = trace(ray, sphere);

        REQUIRE_THAT(result.r(), WithinAbs(0.0, tolerance));
        REQUIRE_THAT(result.g(), WithinAbs(0.0, tolerance));
        REQUIRE_THAT(result.b(), WithinAbs(0.0, tolerance));
    }
}
