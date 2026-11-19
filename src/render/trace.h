#pragma once

#include "ray/ray.h"
#include "scene/scene.h"
#include "colour/colour.h"

Colour trace(const Ray& ray, const Scene& scene);
