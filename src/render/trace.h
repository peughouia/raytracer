#pragma once

#include "ray/ray.h"
#include "geometry/sphere.h"
#include "colour/colour.h"
#include "light/light.h"

Colour trace(const Ray& ray, const Sphere& sphere, const Light& light);
Colour trace(const Ray& ray, const Sphere& sphere);
