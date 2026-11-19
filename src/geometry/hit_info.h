#pragma once

#include "math/vector.h"
#include "material/material.h"

struct HitInfo {
    math::Vector point;
    math::Vector normal;
    const Material& material;

    HitInfo(const math::Vector& p, const math::Vector& n, const Material& m)
        : point(p), normal(n), material(m) {}
};
