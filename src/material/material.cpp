#include "material/material.h"
#include <algorithm>

using math::Vector;

Material::Material(const Colour& colour)
    : _colour(colour) {}

const Colour& Material::colour() const {
    return _colour;
}

Colour Material::shade(const Vector& normal, const Vector& toLight) const {
    double brightness = std::max(0.0, normal.dot(toLight));
    return brightness * _colour;
}
