#include <catch2/catch_test_macros.hpp>
#include "render/trace.h"
#include "material/material.h"
#include "colour/colour.h"
#include "light/light.h"
#include "test_helpers.h"

using math::Vector;

TEST_CASE("Trace ray against sphere", "[render][trace]") {
    Ray ray(Vector(0, 0, -1), Vector(0, 0, 1));
    Colour red(1, 0, 0);

    SECTION("Sphere centered at (0, 0, 9) gives red") {
        Sphere sphere(Vector(0, 0, 9), 5.0, Material(red));
        requireColoursEqual(trace(ray, sphere), red);
    }

    SECTION("Sphere centered at (6, 0, 9) gives black") {
        Sphere sphere(Vector(6, 0, 9), 5.0, Material(red));
        requireColoursEqual(trace(ray, sphere), Colour(0, 0, 0));
    }

    SECTION("Material sphere with light facing the hit point") {
        Sphere sphere(Vector(0, 0, 9), 5.0, Material(red));
        // Hit point is (0, 0, 4), normal is (0, 0, -1). Light in front of hit point at (0, 0, -1):
        Light light(Vector(0, 0, -1), Colour(1, 1, 1));

        requireColoursEqual(trace(ray, sphere, light), red);
    }

    SECTION("Material sphere with light behind the surface gives black") {
        Sphere sphere(Vector(0, 0, 9), 5.0, Material(red));
        // Light behind surface at (0, 0, 10):
        Light light(Vector(0, 0, 10), Colour(1, 1, 1));

        requireColoursEqual(trace(ray, sphere, light), Colour(0, 0, 0));
    }
}
