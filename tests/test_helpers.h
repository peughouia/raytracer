#pragma once

#include "math/vector.h"
#include "colour/colour.h"

extern const double tolerance;

void requireVectorsEqual(const math::Vector& actual, const math::Vector& expected);
void requireColoursEqual(const Colour& actual, const Colour& expected);
