#include <catch2/catch_test_macros.hpp>
#include "render/trace.h"
#include "geometry/sphere.h"
#include "material/material.h"
#include "colour/colour.h"
#include "math/vector.h"
#include "test_helpers.h"

using math::Vector;

TEST_CASE("Trace ray against sphere", "[render][trace]") {
    Ray ray(Vector(0, 0, -1), Vector(0, 0, 1));
    Colour red(1, 0, 0);

    SECTION("centre (0, 0, 9), toLight (0, 0, -1), the sun behind the eye: (1, 0, 0)") {
        Sphere sphere(Vector(0, 0, 9), 5.0, Material(red));
        requireColoursEqual(trace(ray, sphere, Vector(0, 0, -1)), Colour(1, 0, 0));
    }

    SECTION("centre (0, 0, 9), toLight (0.6, 0, -0.8): (0.8, 0, 0)") {
        Sphere sphere(Vector(0, 0, 9), 5.0, Material(red));
        requireColoursEqual(trace(ray, sphere, Vector(0.6, 0, -0.8)), Colour(0.8, 0, 0));
    }

    SECTION("centre (3, 0, 9), toLight (0, 0, -1): (0.8, 0, 0)") {
        Sphere sphere(Vector(3, 0, 9), 5.0, Material(red));
        requireColoursEqual(trace(ray, sphere, Vector(0, 0, -1)), Colour(0.8, 0, 0));
    }

    SECTION("centre (6, 0, 9): black") {
        Sphere sphere(Vector(6, 0, 9), 5.0, Material(red));
        requireColoursEqual(trace(ray, sphere, Vector(0, 0, -1)), Colour(0, 0, 0));
    }
}
