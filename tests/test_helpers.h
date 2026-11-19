#pragma once

#include "math/vector.h"

extern const double tolerance;

void requireVectorsEqual(const math::Vector& actual, const math::Vector& expected);
