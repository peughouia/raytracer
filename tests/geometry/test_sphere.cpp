#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>
#include "geometry/sphere.h"
#include "geometry/hit.h"
#include "material/material.h"
#include "ray/ray.h"
#include "colour/colour.h"
#include "test_helpers.h"

using math::Vector;
using Catch::Matchers::WithinAbs;

TEST_CASE("Sphere hit", "[geometry][sphere]") {
    Ray ray(Vector(0, 0, -1), Vector(0, 0, 1));
    Colour red(1, 0, 0);

    SECTION("centre (0, 0, 9): t = 5, point (0, 0, 4), normal (0, 0, -1), and the material's colour is red") {
        Sphere sphere(Vector(0, 0, 9), 5.0, Material(red));
        auto hit = sphere.hit(ray);
        REQUIRE(hit.has_value());
        REQUIRE_THAT(hit->t, WithinAbs(5.0, tolerance));
        requireVectorsEqual(hit->point, Vector(0, 0, 4));
        requireVectorsEqual(hit->normal, Vector(0, 0, -1));
        requireColoursEqual(hit->material.colour(), red);
    }

    SECTION("centre (3, 0, 9): t = 6, point (0, 0, 5), normal (-0.6, 0, -0.8)") {
        Sphere sphere(Vector(3, 0, 9), 5.0, Material(red));
        auto hit = sphere.hit(ray);
        REQUIRE(hit.has_value());
        REQUIRE_THAT(hit->t, WithinAbs(6.0, tolerance));
        requireVectorsEqual(hit->point, Vector(0, 0, 5));
        requireVectorsEqual(hit->normal, Vector(-0.6, 0, -0.8));
    }

    SECTION("centre (6, 0, 9): nothing") {
        Sphere sphere(Vector(6, 0, 9), 5.0, Material(red));
        auto hit = sphere.hit(ray);
        REQUIRE_FALSE(hit.has_value());
    }

    SECTION("centre (0, 0, 1), around the eye: t = 7, point (0, 0, 6), normal (0, 0, 1)") {
        Sphere sphere(Vector(0, 0, 1), 5.0, Material(red));
        auto hit = sphere.hit(ray);
        REQUIRE(hit.has_value());
        REQUIRE_THAT(hit->t, WithinAbs(7.0, tolerance));
        requireVectorsEqual(hit->point, Vector(0, 0, 6));
        requireVectorsEqual(hit->normal, Vector(0, 0, 1));
    }

    SECTION("centre (0, 0, -11), behind the eye: nothing") {
        Sphere sphere(Vector(0, 0, -11), 5.0, Material(red));
        auto hit = sphere.hit(ray);
        REQUIRE_FALSE(hit.has_value());
    }
}
