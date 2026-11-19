#pragma once

#include "math/vector.h"
#include "material/material.h"

struct Hit {
    double t;
    math::Vector point;
    math::Vector normal;
    Material material;
};
