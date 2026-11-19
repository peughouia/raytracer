#include <catch2/catch_test_macros.hpp>
#include "material/lambert_shader.h"
#include "colour/colour.h"
#include "test_helpers.h"

TEST_CASE("LambertShader returns colour", "[material][lambert_shader]") {
    Colour colour(1.0, 0.5, 0.0);
    LambertShader shader(colour);

    requireColoursEqual(shader.shade(), colour);
    requireColoursEqual(shader.colour(), colour);
}
