#pragma once

#include "ray/ray.h"
#include "geometry/sphere.h"
#include "colour/colour.h"

Colour trace(const Ray& ray, const Sphere& sphere);
