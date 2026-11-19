#include "material/lambert_shader.h"

LambertShader::LambertShader(const Colour& colour)
    : Material(colour) {}

Colour LambertShader::shade() const {
    return colour();
}
