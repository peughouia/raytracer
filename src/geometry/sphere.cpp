#include "geometry/sphere.h"
#include <cmath>
#include <algorithm>

using math::Vector;

Sphere::Sphere(const Vector& centre, double radius, const Material& material)
    : _centre(centre), _radius(radius), _material(material) {}

const Colour& Sphere::colour() const {
    return _material.colour();
}

const Material& Sphere::material() const {
    return _material;
}

std::optional<HitInfo> Sphere::hit(const Ray& ray) const {
    Vector O = ray.origin();
    Vector D = ray.direction();
    Vector C = _centre;

    Vector L = O - C;
    double a = D.dot(D);
    double b = 2.0 * D.dot(L);
    double c = L.dot(L) - _radius * _radius;
    double discriminant = b * b - 4.0 * a * c;

    if (discriminant < 0.0) {
        return std::nullopt;
    }

    double sqrtDiscriminant = std::sqrt(discriminant);
    double t1 = (-b - sqrtDiscriminant) / (2.0 * a);
    double t2 = (-b + sqrtDiscriminant) / (2.0 * a);

    double t = -1.0;
    if (t1 > 0.0 && t2 > 0.0) {
        t = std::min(t1, t2);
    } else if (t1 > 0.0) {
        t = t1;
    } else if (t2 > 0.0) {
        t = t2;
    } else {
        return std::nullopt;
    }

    Vector hitPoint = ray.at(t);
    Vector normal = (hitPoint - _centre) / _radius;

    return HitInfo(hitPoint, normal, _material);
}

bool Sphere::isHitBy(const Ray& ray) const {
    return hit(ray).has_value();
}
