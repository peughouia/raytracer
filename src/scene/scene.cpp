#include "scene/scene.h"

using math::Vector;

Scene::Scene(const Vector& toLight)
    : _toLight(toLight) {}

const Vector& Scene::toLight() const {
    return _toLight;
}

void Scene::add(std::unique_ptr<Shape> shape) {
    _shapes.push_back(std::move(shape));
}

std::optional<Hit> Scene::nearestHit(const Ray& ray) const {
    std::optional<Hit> closestHit = std::nullopt;

    for (const auto& shape : _shapes) {
        auto currentHit = shape->hit(ray);
        if (currentHit.has_value()) {
            if (!closestHit.has_value() || currentHit->t < closestHit->t) {
                closestHit = currentHit;
            }
        }
    }

    return closestHit;
}
