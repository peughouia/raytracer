#include <catch2/catch_test_macros.hpp>
#include "material/flat_shader.h"
#include "colour/colour.h"
#include "test_helpers.h"

TEST_CASE("FlatShader returns constant colour", "[material][flat_shader]") {
    Colour colour(1.0, 0.5, 0.0);
    FlatShader shader(colour);

    requireColoursEqual(shader.shade(), colour);
}
