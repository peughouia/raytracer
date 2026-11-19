#pragma once

#include "math/vector.h"
#include "colour/colour.h"
#include "ray/ray.h"

class Sphere {
public:
    Sphere(const math::Vector& centre, double radius, const Colour& colour);

    const Colour& colour() const;

    bool isHitBy(const Ray& ray) const;

private:
    math::Vector _centre;
    double _radius;
    Colour _colour;
};
