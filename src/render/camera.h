#pragma once

#include "math/vector.h"
#include "geometry/ray.h"

using math::Vector;

class Camera {
public:
    Camera(const Vector& eye, const Vector& screenCentre);

    Ray rayThroughCentre() const;

private:
    Vector _eye;
    Vector _screenCentre;
};
