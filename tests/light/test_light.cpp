#include <catch2/catch_test_macros.hpp>
#include "light/light.h"
#include "math/vector.h"
#include "colour/colour.h"
#include "test_helpers.h"

using math::Vector;

TEST_CASE("Light position and colour accessors", "[light]") {
    Vector pos(1.0, 2.0, 3.0);
    Colour col(1.0, 0.8, 0.6);

    Light light(pos, col);

    requireVectorsEqual(light.position(), pos);
    requireColoursEqual(light.colour(), col);
}
