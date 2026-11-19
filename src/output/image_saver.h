#pragma once

#include "image/image.h"
#include <string>

class ImageSaver {
public:
    virtual ~ImageSaver() = default;

    // Writes the whole image to path, or throws a std::runtime_error.
    virtual void save(const Image& image, const std::string& path) const = 0;
};
