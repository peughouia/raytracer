#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>
#include "geometry/plane.h"
#include "geometry/hit.h"
#include "material/material.h"
#include "ray/ray.h"
#include "colour/colour.h"
#include "math/vector.h"
#include "test_helpers.h"

using math::Vector;
using Catch::Matchers::WithinAbs;

TEST_CASE("Plane ray intersection", "[geometry][plane]") {
    Colour green(0, 1, 0);

    SECTION("the floor: point (0, 0, 0), normal (0, 1, 0), ray from (0, 8, 0) with direction (3, -4, 0)") {
        Plane plane(Vector(0, 0, 0), Vector(0, 1, 0), Material(green));
        Ray ray(Vector(0, 8, 0), Vector(3, -4, 0));

        auto hit = plane.hit(ray);
        REQUIRE(hit.has_value());
        REQUIRE_THAT(hit->t, WithinAbs(2.0, tolerance));
        requireVectorsEqual(hit->point, Vector(6, 0, 0));
        requireVectorsEqual(hit->normal, Vector(0, 1, 0));
        requireColoursEqual(hit->material.colour(), green);
    }

    SECTION("the line 3x + 4y = 24: point (8, 0, 0), normal (3, 4, 0), ray from (-8, 0, 0) with direction (4, 3, 0)") {
        Plane plane(Vector(8, 0, 0), Vector(3, 4, 0), Material(green));
        Ray ray(Vector(-8, 0, 0), Vector(4, 3, 0));

        auto hit = plane.hit(ray);
        REQUIRE(hit.has_value());
        REQUIRE_THAT(hit->t, WithinAbs(2.0, tolerance));
        requireVectorsEqual(hit->point, Vector(0, 6, 0));
        requireVectorsEqual(hit->normal, Vector(0.6, 0.8, 0));
    }

    SECTION("the floor, with the direction (5, 0, 0): nothing, it's parallel") {
        Plane plane(Vector(0, 0, 0), Vector(0, 1, 0), Material(green));
        Ray ray(Vector(0, 8, 0), Vector(5, 0, 0));

        auto hit = plane.hit(ray);
        REQUIRE_FALSE(hit.has_value());
    }

    SECTION("the floor, with the direction (3, 4, 0): nothing, it's behind") {
        Plane plane(Vector(0, 0, 0), Vector(0, 1, 0), Material(green));
        Ray ray(Vector(0, 8, 0), Vector(3, 4, 0));

        auto hit = plane.hit(ray);
        REQUIRE_FALSE(hit.has_value());
    }
}
