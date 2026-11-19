#include "ray/ray.h"

using math::Vector;

Ray::Ray(const Vector& origin, const Vector& direction)
    : _origin(origin), _direction(direction) {}

const Vector& Ray::origin() const {
    return _origin;
}

const Vector& Ray::direction() const {
    return _direction;
}
