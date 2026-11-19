#include <catch2/catch_test_macros.hpp>
#include "geometry/ray.h"
#include "test_helpers.h"

using math::Vector;

TEST_CASE("Ray components", "[geometry][ray]") {
    Vector origin(1, 2, 3);
    Vector direction(3, 4, 0);
    Ray ray(origin, direction);

    requireVectorsEqual(ray.origin(), Vector(1, 2, 3));
    requireVectorsEqual(ray.direction(), Vector(3, 4, 0));
}
