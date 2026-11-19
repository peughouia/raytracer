#include <catch2/catch_test_macros.hpp>
#include "ray/ray.h"
#include "test_helpers.h"

using math::Vector;

TEST_CASE("Ray components", "[ray]") {
    Vector origin(1, 2, 3);
    Vector direction(3, 4, 0);
    Ray ray(origin, direction);

    requireVectorsEqual(ray.origin(), Vector(1, 2, 3));
    requireVectorsEqual(ray.direction(), Vector(3, 4, 0));
}

TEST_CASE("Ray point at distance t", "[ray]") {
    Vector origin(0, 8, 0);
    Vector direction(3, -4, 0);
    Ray ray(origin, direction);

    requireVectorsEqual(ray.at(0.0), Vector(0, 8, 0));
    requireVectorsEqual(ray.at(2.0), Vector(6, 0, 0));
}
