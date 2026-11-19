#include "output/png_saver.h"
#include <lodepng.h>
#include <cmath>
#include <stdexcept>
#include <vector>

static unsigned char toByte(double value) {
    return static_cast<unsigned char>(std::round(value * 255.0));
}

void PngSaver::save(const Image& image, const std::string& path) const {
    std::vector<unsigned char> bytes;
    bytes.reserve(static_cast<std::size_t>(image.width() * image.height() * 3));

    for (int row = 0; row < image.height(); ++row) {
        for (int col = 0; col < image.width(); ++col) {
            Colour c = image.pixel(col, row);
            bytes.push_back(toByte(c.r()));
            bytes.push_back(toByte(c.g()));
            bytes.push_back(toByte(c.b()));
        }
    }

    unsigned int error = lodepng::encode(
        path,
        bytes,
        static_cast<unsigned int>(image.width()),
        static_cast<unsigned int>(image.height()),
        LCT_RGB
    );

    if (error != 0) {
        throw std::runtime_error(lodepng_error_text(error));
    }
}
