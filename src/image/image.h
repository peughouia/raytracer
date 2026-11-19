#pragma once

#include "colour/colour.h"
#include <vector>

class Image {
public:
    Image(int width, int height);

    int width() const;
    int height() const;

    Colour pixel(int column, int row) const;
    void setPixel(int column, int row, const Colour& colour);

private:
    int _width;
    int _height;
    std::vector<Colour> _pixels;
};
