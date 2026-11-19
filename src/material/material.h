#pragma once

#include "colour/colour.h"
#include "math/vector.h"

class Material {
public:
    explicit Material(const Colour& colour);
    virtual ~Material() = default;

    const Colour& colour() const;
    Colour shade(const math::Vector& normal, const math::Vector& toLight) const;

private:
    Colour _colour;
};
