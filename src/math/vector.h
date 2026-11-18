#pragma once

namespace math {

class Vector {
public:
    // Default constructor: creates a vector initialized to (0, 0, 0)
    Vector();

    // Constructor: creates a vector with given x, y, z coordinates
    Vector(double x, double y, double z);

    // Component accessors (no "get" prefix)
    double x() const;
    double y() const;
    double z() const;

    Vector operator+(const Vector& other) const;

    // Subtracts another vector from this vector and returns the resulting vector
    Vector subtract(const Vector& other) const;

private:
    double _x;
    double _y;
    double _z;
};

} // namespace math

namespace raytracer {
using math::Vector;
}
