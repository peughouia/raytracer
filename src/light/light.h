#pragma once

#include "math/vector.h"
#include "colour/colour.h"

class Light {
public:
    Light(const math::Vector& position, const Colour& colour);

    const math::Vector& position() const;
    const Colour& colour() const;

private:
    math::Vector _position;
    Colour _colour;
};
