#pragma once

#include "math/vector.h"

class Ray {
public:
    Ray(const math::Vector& origin, const math::Vector& direction);

    const math::Vector& origin() const;
    const math::Vector& direction() const;

private:
    math::Vector _origin;
    math::Vector _direction;
};
