#pragma once

#include "math/vector.h"
#include "ray/ray.h"

class Camera {
public:
    Camera(const math::Vector& eye, const math::Vector& screenCentre);

    Ray rayThroughCentre() const;

private:
    math::Vector _eye;
    math::Vector _screenCentre;
};
