#include <catch2/catch_test_macros.hpp>
#include "output/png_saver.h"
#include "image/image.h"
#include "colour/colour.h"
#include <lodepng.h>
#include <vector>
#include <string>
#include <cstdio>

TEST_CASE("PngSaver saves image as PNG", "[output][png_saver]") {
    Image image(2, 2);
    image.setPixel(1, 0, Colour(1.0, 0.5, 0.0));

    const std::string path = "test_output.png";

    PngSaver saver;
    saver.save(image, path);

    std::vector<unsigned char> pixels;
    unsigned int width = 0;
    unsigned int height = 0;
    unsigned int error = lodepng::decode(pixels, width, height, path, LCT_RGB);

    std::remove(path.c_str());

    REQUIRE(error == 0);
    REQUIRE(width == 2);
    REQUIRE(height == 2);
    REQUIRE(pixels.size() == 12);

    std::vector<int> expected = {
        0, 0, 0,
        255, 128, 0,
        0, 0, 0,
        0, 0, 0
    };

    for (std::size_t i = 0; i < 12; ++i) {
        REQUIRE(static_cast<int>(pixels[i]) == expected[i]);
    }
}
