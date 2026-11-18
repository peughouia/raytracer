#pragma once

namespace math {

class Vector {
public:
    Vector();
    Vector(double x, double y, double z);

    double x() const;
    double y() const;
    double z() const;

    Vector operator+(const Vector& other) const;
    Vector operator-(const Vector& other) const;

    double dot(const Vector& other) const;
    double length() const;
    Vector normalised() const;

private:
    double _x;
    double _y;
    double _z;
};

Vector operator*(double t, const Vector& v);

} // namespace math

namespace raytracer {
using math::Vector;
using math::operator*;
}
