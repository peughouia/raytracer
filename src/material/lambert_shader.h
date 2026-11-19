#pragma once

#include "material/material.h"

class LambertShader : public Material {
public:
    explicit LambertShader(const Colour& colour);

    Colour shade() const;
};
