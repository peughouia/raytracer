#pragma once

#include <optional>
#include "math/vector.h"
#include "ray/ray.h"
#include "material/material.h"
#include "geometry/hit.h"
#include "geometry/shape.h"

class Sphere : public Shape {
public:
    Sphere(const math::Vector& centre, double radius, const Material& material);

    const Material& material() const;

    std::optional<Hit> hit(const Ray& ray) const override;

private:
    math::Vector _centre;
    double _radius;
    Material _material;
};
