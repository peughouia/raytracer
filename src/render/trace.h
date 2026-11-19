#pragma once

#include "ray/ray.h"
#include "geometry/sphere.h"
#include "colour/colour.h"
#include "math/vector.h"

Colour trace(const Ray& ray, const Sphere& sphere, const math::Vector& toLight);
