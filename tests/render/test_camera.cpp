#include <catch2/catch_test_macros.hpp>
#include "render/camera.h"
#include "test_helpers.h"

using math::Vector;

TEST_CASE("Camera ray through centre", "[render][camera]") {
    SECTION("Camera at (0, 0, -1) facing (0, 0, 0)") {
        Camera camera(Vector(0, 0, -1), Vector(0, 0, 0));
        Ray ray = camera.rayThroughCentre();

        requireVectorsEqual(ray.origin(), Vector(0, 0, -1));
        requireVectorsEqual(ray.direction(), Vector(0, 0, 1));
    }

    SECTION("Camera at (1, 2, -1) facing (4, 6, -1)") {
        Camera camera(Vector(1, 2, -1), Vector(4, 6, -1));
        Ray ray = camera.rayThroughCentre();

        requireVectorsEqual(ray.origin(), Vector(1, 2, -1));
        requireVectorsEqual(ray.direction(), Vector(3, 4, 0));
    }
}
