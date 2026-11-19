#pragma once

#include "colour/colour.h"

class Material {
public:
    virtual ~Material() = default;

    virtual Colour shade() const = 0;
};
