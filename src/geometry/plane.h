#pragma once

#include <optional>
#include "math/vector.h"
#include "ray/ray.h"
#include "material/material.h"
#include "geometry/shape.h"
#include "geometry/hit.h"

class Plane : public Shape {
public:
    Plane(const math::Vector& point, const math::Vector& normal, const Material& material);

    std::optional<Hit> hit(const Ray& ray) const override;

private:
    math::Vector _point;
    math::Vector _normal;
    Material _material;
};
