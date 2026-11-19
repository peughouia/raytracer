#pragma once

#include <optional>
#include "math/vector.h"
#include "ray/ray.h"
#include "material/material.h"
#include "geometry/hit.h"

class Sphere {
public:
    Sphere(const math::Vector& centre, double radius, const Material& material);

    const Colour& colour() const;
    const Material& material() const;

    std::optional<Hit> hit(const Ray& ray) const;
    bool isHitBy(const Ray& ray) const;

private:
    math::Vector _centre;
    double _radius;
    Material _material;
};
