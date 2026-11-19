#pragma once

#include "math/vector.h"
#include "ray/ray.h"
#include "geometry/sphere.h"
#include "image/image.h"

class Camera {
public:
    Camera(const math::Vector& eye, const math::Vector& screenCentre, double screenWidth);

    Ray rayThroughCentre() const;
    Ray rayThroughPixel(int column, int row, int width, int height) const;
    Image render(const Sphere& sphere, int width, int height) const;

private:
    math::Vector _eye;
    math::Vector _screenCentre;
    double _screenWidth;
};
