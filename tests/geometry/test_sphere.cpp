#include <catch2/catch_test_macros.hpp>
#include "geometry/sphere.h"
#include "material/flat_shader.h"
#include "ray/ray.h"
#include "colour/colour.h"
#include "test_helpers.h"

using math::Vector;

TEST_CASE("Sphere ray intersection", "[geometry][sphere]") {
    Ray ray(Vector(0, 0, -1), Vector(0, 0, 1));
    FlatShader red(Colour(1, 0, 0));

    SECTION("Ray hits sphere centered at (0, 0, 9)") {
        Sphere sphere(Vector(0, 0, 9), 5.0, red);
        REQUIRE(sphere.isHitBy(ray));
    }

    SECTION("Ray hits sphere centered at (3, 0, 9)") {
        Sphere sphere(Vector(3, 0, 9), 5.0, red);
        REQUIRE(sphere.isHitBy(ray));
    }

    SECTION("Ray misses sphere centered at (6, 0, 9)") {
        Sphere sphere(Vector(6, 0, 9), 5.0, red);
        REQUIRE_FALSE(sphere.isHitBy(ray));
    }

    SECTION("Ray misses sphere centered at (0, 0, -11)") {
        Sphere sphere(Vector(0, 0, -11), 5.0, red);
        REQUIRE_FALSE(sphere.isHitBy(ray));
    }
}

TEST_CASE("Sphere material accessor", "[geometry][sphere]") {
    Colour blue(0, 0, 1);
    FlatShader shader(blue);
    Sphere sphere(Vector(0, 0, 9), 5.0, shader);

    requireColoursEqual(sphere.material().shade(), blue);
}
