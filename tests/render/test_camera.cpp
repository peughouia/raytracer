#include <catch2/catch_test_macros.hpp>
#include "render/camera.h"
#include "geometry/sphere.h"
#include "image/image.h"
#include "colour/colour.h"
#include "test_helpers.h"

using math::Vector;

TEST_CASE("Camera ray through centre", "[render][camera]") {
    SECTION("Camera at (0, 0, -1) facing (0, 0, 0)") {
        Camera camera(Vector(0, 0, -1), Vector(0, 0, 0), 2.0);
        Ray ray = camera.rayThroughCentre();

        requireVectorsEqual(ray.origin(), Vector(0, 0, -1));
        requireVectorsEqual(ray.direction(), Vector(0, 0, 1));
    }

    SECTION("Camera at (1, 2, -1) facing (4, 6, -1)") {
        Camera camera(Vector(1, 2, -1), Vector(4, 6, -1), 2.0);
        Ray ray = camera.rayThroughCentre();

        requireVectorsEqual(ray.origin(), Vector(1, 2, -1));
        requireVectorsEqual(ray.direction(), Vector(3, 4, 0));
    }
}

TEST_CASE("Camera ray through pixel", "[render][camera]") {
    Camera camera(Vector(0, 0, -1), Vector(0, 0, 0), 5.0);
    int width = 5;
    int height = 3;

    SECTION("Pixel (2, 1) in the centre has direction (0, 0, 1)") {
        Ray ray = camera.rayThroughPixel(2, 1, width, height);
        requireVectorsEqual(ray.origin(), Vector(0, 0, -1));
        requireVectorsEqual(ray.direction(), Vector(0, 0, 1));
    }

    SECTION("Pixel (4, 0) top right has direction (2, 1, 1)") {
        Ray ray = camera.rayThroughPixel(4, 0, width, height);
        requireVectorsEqual(ray.origin(), Vector(0, 0, -1));
        requireVectorsEqual(ray.direction(), Vector(2, 1, 1));
    }

    SECTION("Pixel (0, 2) bottom left has direction (-2, -1, 1)") {
        Ray ray = camera.rayThroughPixel(0, 2, width, height);
        requireVectorsEqual(ray.origin(), Vector(0, 0, -1));
        requireVectorsEqual(ray.direction(), Vector(-2, -1, 1));
    }
}

TEST_CASE("Camera render image of sphere", "[render][camera]") {
    Camera camera(Vector(0, 0, -1), Vector(0, 0, 0), 5.0);
    Colour red(1, 0, 0);
    Colour black(0, 0, 0);
    Sphere sphere(Vector(0, 0, 6), 5.0, red);

    Image image = camera.render(sphere, 5, 3);

    REQUIRE(image.width() == 5);
    REQUIRE(image.height() == 3);

    for (int row = 0; row < image.height(); ++row) {
        for (int col = 0; col < image.width(); ++col) {
            bool isRed = (col == 2 && row == 0) ||
                         (col == 1 && row == 1) ||
                         (col == 2 && row == 1) ||
                         (col == 3 && row == 1) ||
                         (col == 2 && row == 2);

            if (isRed) {
                requireColoursEqual(image.pixel(col, row), red);
            } else {
                requireColoursEqual(image.pixel(col, row), black);
            }
        }
    }
}
