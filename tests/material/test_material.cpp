#include <catch2/catch_test_macros.hpp>
#include "material/material.h"
#include "colour/colour.h"
#include "math/vector.h"
#include "test_helpers.h"

using math::Vector;

TEST_CASE("Material colour", "[material]") {
    Colour orange(1, 0.5, 0);
    Material material(orange);

    requireColoursEqual(material.colour(), orange);
}

TEST_CASE("Material shade", "[material]") {
    Colour orange(1, 0.5, 0);
    Material material(orange);
    Vector normal(0, 0, -1);

    SECTION("toLight (0, 0, -1): the whole colour") {
        requireColoursEqual(material.shade(normal, Vector(0, 0, -1)), Colour(1, 0.5, 0));
    }

    SECTION("toLight (0.6, 0, -0.8): (0.8, 0.4, 0)") {
        requireColoursEqual(material.shade(normal, Vector(0.6, 0, -0.8)), Colour(0.8, 0.4, 0));
    }

    SECTION("toLight (1, 0, 0): black") {
        requireColoursEqual(material.shade(normal, Vector(1, 0, 0)), Colour(0, 0, 0));
    }

    SECTION("toLight (0, 0, 1): black, not negative") {
        requireColoursEqual(material.shade(normal, Vector(0, 0, 1)), Colour(0, 0, 0));
    }
}
