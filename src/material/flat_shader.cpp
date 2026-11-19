#include "material/flat_shader.h"

FlatShader::FlatShader(const Colour& colour)
    : _colour(colour) {}

Colour FlatShader::shade() const {
    return _colour;
}
