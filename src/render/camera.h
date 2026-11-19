#pragma once

#include "math/vector.h"
#include "ray/ray.h"

class Camera {
public:
    Camera(const math::Vector& eye, const math::Vector& screenCentre, double screenWidth);

    Ray rayThroughCentre() const;
    Ray rayThroughPixel(int column, int row, int width, int height) const;

private:
    math::Vector _eye;
    math::Vector _screenCentre;
    double _screenWidth;
};
