#include <catch2/catch_test_macros.hpp>
#include "render/trace.h"
#include "test_helpers.h"

using math::Vector;

TEST_CASE("Trace ray against sphere", "[render][trace]") {
    Ray ray(Vector(0, 0, -1), Vector(0, 0, 1));
    Colour red(1, 0, 0);

    SECTION("Sphere centered at (0, 0, 9) gives red") {
        Sphere sphere(Vector(0, 0, 9), 5.0, red);
        requireColoursEqual(trace(ray, sphere), red);
    }

    SECTION("Sphere centered at (6, 0, 9) gives black") {
        Sphere sphere(Vector(6, 0, 9), 5.0, red);
        requireColoursEqual(trace(ray, sphere), Colour(0, 0, 0));
    }
}
