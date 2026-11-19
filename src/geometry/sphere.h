#pragma once

#include "math/vector.h"
#include "ray/ray.h"
#include "material/material.h"

class Sphere {
public:
    Sphere(const math::Vector& centre, double radius, const Material& material);

    const Material& material() const;

    bool isHitBy(const Ray& ray) const;

private:
    math::Vector _centre;
    double _radius;
    const Material& _material;
};
