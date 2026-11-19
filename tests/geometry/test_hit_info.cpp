#include <catch2/catch_test_macros.hpp>
#include "geometry/hit_info.h"
#include "material/material.h"
#include "colour/colour.h"
#include "test_helpers.h"

using math::Vector;

TEST_CASE("HitInfo fields", "[geometry][hit_info]") {
    Vector point(1.0, 2.0, 3.0);
    Vector normal(0.0, 0.0, 1.0);
    Colour colour(0.5, 0.5, 0.5);
    Material material(colour);

    HitInfo hit(point, normal, material);

    requireVectorsEqual(hit.point, point);
    requireVectorsEqual(hit.normal, normal);
    requireColoursEqual(hit.material.colour(), colour);
}
