#pragma once

#include "colour/colour.h"
#include "math/vector.h"

class Material {
public:
    explicit Material(const Colour& colour);
    virtual ~Material() = default;

    const Colour& colour() const;

    // Expects normal and toLight to be unit vectors.
    Colour shade(const math::Vector& normal, const math::Vector& toLight) const;

private:
    Colour _colour;
};
