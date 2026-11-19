#pragma once

#include <vector>
#include <memory>
#include <optional>
#include "math/vector.h"
#include "ray/ray.h"
#include "geometry/shape.h"
#include "geometry/hit.h"

class Scene {
public:
    explicit Scene(const math::Vector& toLight);

    const math::Vector& toLight() const;

    void add(std::unique_ptr<Shape> shape);
    std::optional<Hit> nearestHit(const Ray& ray) const;

private:
    math::Vector _toLight;
    std::vector<std::unique_ptr<Shape>> _shapes;
};
