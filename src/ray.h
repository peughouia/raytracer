#pragma once

#include "math/vector.h"

using math::Vector;

class Ray {
public:
    Ray(const Vector& origin, const Vector& direction);

    const Vector& origin() const;
    const Vector& direction() const;

private:
    Vector _origin;
    Vector _direction;
};
