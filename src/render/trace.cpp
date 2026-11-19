#include "render/trace.h"

Colour trace(const Ray& ray, const Scene& scene) {
    auto hit = scene.nearestHit(ray);
    if (hit.has_value()) {
        return hit->material.shade(hit->normal, scene.toLight());
    }
    return Colour(0, 0, 0);
}
