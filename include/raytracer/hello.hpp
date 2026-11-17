#pragma once

#include <string>

namespace raytracer {

/// Returns a welcoming greeting message.
std::string get_greeting(const std::string& name = "World");

/// Returns the current raytracer project version and build target info.
std::string get_project_info();

/// A basic 3D vector to showcase raytracer math and TDD workflows.
struct Vec3 {
    double x{0.0};
    double y{0.0};
    double z{0.0};

    constexpr Vec3() = default;
    constexpr Vec3(double x_, double y_, double z_) : x(x_), y(y_), z(z_) {}

    constexpr Vec3 operator+(const Vec3& other) const {
        return {x + other.x, y + other.y, z + other.z};
    }

    constexpr Vec3 operator-(const Vec3& other) const {
        return {x - other.x, y - other.y, z - other.z};
    }

    constexpr Vec3 operator*(double scalar) const {
        return {x * scalar, y * scalar, z * scalar};
    }

    constexpr double dot(const Vec3& other) const {
        return x * other.x + y * other.y + z * other.z;
    }

    bool operator==(const Vec3& other) const = default;
};

} // namespace raytracer
