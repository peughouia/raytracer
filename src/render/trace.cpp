#include "render/trace.h"

Colour trace(const Ray& ray, const Sphere& sphere, const Light& light) {
    auto hit = sphere.hit(ray);
    if (hit.has_value()) {
        math::Vector toLight = (light.position() - hit->point).normalised();
        return hit->material.shade(hit->normal, toLight);
    }
    return Colour(0, 0, 0);
}

Colour trace(const Ray& ray, const Sphere& sphere) {
    auto hit = sphere.hit(ray);
    if (hit.has_value()) {
        return hit->material.colour();
    }
    return Colour(0, 0, 0);
}
