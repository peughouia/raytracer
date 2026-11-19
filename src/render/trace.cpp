#include "render/trace.h"

Colour trace(const Ray& ray, const Sphere& sphere, const math::Vector& toLight) {
    auto hit = sphere.hit(ray);
    if (hit.has_value()) {
        return hit->material.shade(hit->normal, toLight);
    }
    return Colour(0, 0, 0);
}
