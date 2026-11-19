#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>
#include <memory>
#include "scene/scene.h"
#include "geometry/sphere.h"
#include "geometry/plane.h"
#include "material/material.h"
#include "colour/colour.h"
#include "ray/ray.h"
#include "math/vector.h"
#include "test_helpers.h"

using math::Vector;
using Catch::Matchers::WithinAbs;

TEST_CASE("Scene toLight accessor", "[scene]") {
    Vector toLight(0.6, 0, -0.8);
    Scene scene(toLight);

    requireVectorsEqual(scene.toLight(), toLight);
}

TEST_CASE("Scene nearest hit", "[scene]") {
    Vector toLight(0, 0, -1);
    Ray ray(Vector(0, 0, -1), Vector(0, 0, 1));
    Colour red(1, 0, 0);
    Colour blue(0, 0, 1);

    SECTION("the sphere, then a blue plane through (0, 0, 2) with normal (0, 0, -1): the hit is the plane's, at t = 3") {
        Scene scene(toLight);
        scene.add(std::make_unique<Sphere>(Vector(0, 0, 9), 5.0, Material(red)));
        scene.add(std::make_unique<Plane>(Vector(0, 0, 2), Vector(0, 0, -1), Material(blue)));

        auto hit = scene.nearestHit(ray);
        REQUIRE(hit.has_value());
        REQUIRE_THAT(hit->t, WithinAbs(3.0, tolerance));
        requireColoursEqual(hit->material.colour(), blue);
    }

    SECTION("the sphere, then a blue plane through (0, 0, 20) with normal (0, 0, -1): the hit is the sphere's, at t = 5") {
        Scene scene(toLight);
        scene.add(std::make_unique<Sphere>(Vector(0, 0, 9), 5.0, Material(red)));
        scene.add(std::make_unique<Plane>(Vector(0, 0, 20), Vector(0, 0, -1), Material(blue)));

        auto hit = scene.nearestHit(ray);
        REQUIRE(hit.has_value());
        REQUIRE_THAT(hit->t, WithinAbs(5.0, tolerance));
        requireColoursEqual(hit->material.colour(), red);
    }

    SECTION("only a sphere with centre (6, 0, 9): nothing") {
        Scene scene(toLight);
        scene.add(std::make_unique<Sphere>(Vector(6, 0, 9), 5.0, Material(red)));

        auto hit = scene.nearestHit(ray);
        REQUIRE_FALSE(hit.has_value());
    }
}
