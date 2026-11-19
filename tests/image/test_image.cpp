#include <catch2/catch_test_macros.hpp>
#include "image/image.h"
#include "test_helpers.h"

TEST_CASE("Image dimensions and pixel access", "[image]") {
    Image image(5, 3);

    SECTION("Width is 5 and height is 3") {
        REQUIRE(image.width() == 5);
        REQUIRE(image.height() == 3);
    }

    SECTION("Every pixel is initially black") {
        for (int row = 0; row < image.height(); ++row) {
            for (int col = 0; col < image.width(); ++col) {
                requireColoursEqual(image.pixel(col, row), Colour(0, 0, 0));
            }
        }
    }

    SECTION("After setting pixel (4, 0) to red, that pixel is red and all others are black") {
        Colour red(1, 0, 0);
        image.setPixel(4, 0, red);

        for (int row = 0; row < image.height(); ++row) {
            for (int col = 0; col < image.width(); ++col) {
                if (col == 4 && row == 0) {
                    requireColoursEqual(image.pixel(col, row), red);
                } else {
                    requireColoursEqual(image.pixel(col, row), Colour(0, 0, 0));
                }
            }
        }
    }
}
