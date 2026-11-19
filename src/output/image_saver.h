#pragma once

#include "image/image.h"
#include <string>

class ImageSaver {
public:
    virtual ~ImageSaver() = default;

    virtual void save(const Image& image, const std::string& path) const = 0;
};
