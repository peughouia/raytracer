#include "sphere.h"

Sphere::Sphere(const Vector& centre, double radius, const Colour& colour)
    : _centre(centre), _radius(radius), _colour(colour) {}

const Colour& Sphere::colour() const {
    return _colour;
}

bool Sphere::isHitBy(const Ray& ray) const {
    Vector O = ray.origin();
    Vector D = ray.direction();
    Vector C = _centre;

    Vector L = O - C;
    double a = D.dot(D);
    double b = 2.0 * D.dot(L);
    double c = L.dot(L) - _radius * _radius;
    double discriminant = b * b - 4.0 * a * c;

    return discriminant >= 0.0;
}
