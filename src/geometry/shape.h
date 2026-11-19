#pragma once

#include <optional>
#include "ray/ray.h"
#include "geometry/hit.h"

class Shape {
public:
    virtual ~Shape() = default;

    // Its nearest hit in front of the ray's origin, with t > 0 and a unit normal, or nothing.
    virtual std::optional<Hit> hit(const Ray& ray) const = 0;
};
