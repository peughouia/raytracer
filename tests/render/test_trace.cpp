#include <catch2/catch_test_macros.hpp>
#include <memory>
#include "render/trace.h"
#include "scene/scene.h"
#include "geometry/sphere.h"
#include "material/material.h"
#include "colour/colour.h"
#include "math/vector.h"
#include "test_helpers.h"

using math::Vector;

TEST_CASE("Trace ray against scene", "[render][trace]") {
    Ray ray(Vector(0, 0, -1), Vector(0, 0, 1));
    Colour red(1, 0, 0);

    SECTION("centre (0, 0, 9), toLight (0, 0, -1), the sun behind the eye: (1, 0, 0)") {
        Scene scene(Vector(0, 0, -1));
        scene.add(std::make_unique<Sphere>(Vector(0, 0, 9), 5.0, Material(red)));
        requireColoursEqual(trace(ray, scene), Colour(1, 0, 0));
    }

    SECTION("centre (0, 0, 9), toLight (0.6, 0, -0.8): (0.8, 0, 0)") {
        Scene scene(Vector(0.6, 0, -0.8));
        scene.add(std::make_unique<Sphere>(Vector(0, 0, 9), 5.0, Material(red)));
        requireColoursEqual(trace(ray, scene), Colour(0.8, 0, 0));
    }

    SECTION("centre (3, 0, 9), toLight (0, 0, -1): (0.8, 0, 0)") {
        Scene scene(Vector(0, 0, -1));
        scene.add(std::make_unique<Sphere>(Vector(3, 0, 9), 5.0, Material(red)));
        requireColoursEqual(trace(ray, scene), Colour(0.8, 0, 0));
    }

    SECTION("centre (6, 0, 9): black") {
        Scene scene(Vector(0, 0, -1));
        scene.add(std::make_unique<Sphere>(Vector(6, 0, 9), 5.0, Material(red)));
        requireColoursEqual(trace(ray, scene), Colour(0, 0, 0));
    }
}
