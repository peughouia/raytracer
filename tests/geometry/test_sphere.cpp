#include <catch2/catch_test_macros.hpp>
#include "geometry/sphere.h"
#include "material/material.h"
#include "ray/ray.h"
#include "colour/colour.h"
#include "test_helpers.h"

using math::Vector;

TEST_CASE("Sphere ray intersection", "[geometry][sphere]") {
    Ray ray(Vector(0, 0, -1), Vector(0, 0, 1));
    Colour red(1, 0, 0);

    SECTION("Ray hits sphere centered at (0, 0, 9)") {
        Sphere sphere(Vector(0, 0, 9), 5.0, Material(red));
        REQUIRE(sphere.isHitBy(ray));
    }

    SECTION("Ray hits sphere centered at (3, 0, 9)") {
        Sphere sphere(Vector(3, 0, 9), 5.0, Material(red));
        REQUIRE(sphere.isHitBy(ray));
    }

    SECTION("Ray origin inside sphere centered at (0, 0, 2) hits closest non-negative exit point") {
        Sphere sphere(Vector(0, 0, 2), 5.0, Material(red));
        REQUIRE(sphere.isHitBy(ray));
    }

    SECTION("Ray misses sphere centered at (6, 0, 9)") {
        Sphere sphere(Vector(6, 0, 9), 5.0, Material(red));
        REQUIRE_FALSE(sphere.isHitBy(ray));
    }

    SECTION("Ray misses sphere behind camera centered at (0, 0, -11)") {
        Sphere sphere(Vector(0, 0, -11), 5.0, Material(red));
        REQUIRE_FALSE(sphere.isHitBy(ray));
    }
}

TEST_CASE("Sphere colour accessor", "[geometry][sphere]") {
    Colour blue(0, 0, 1);
    Sphere sphere(Vector(0, 0, 9), 5.0, Material(blue));

    requireColoursEqual(sphere.colour(), blue);
}
