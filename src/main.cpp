#include "math/vector.h"
#include "colour/colour.h"
#include "geometry/sphere.h"
#include "render/camera.h"
#include "image/image.h"
#include "output/png_saver.h"
#include "material/material.h"
#include <iostream>
#include <string>

using math::Vector;

int main() {
    Camera camera(Vector(0, 0, -1), Vector(0, 0, 0), 2.0);
    Sphere sphere(Vector(0, 0, 9), 5.0, Material(Colour(1, 0, 0)));
    Vector toLight = Vector(-1, 1, -1).normalised();

    Image image = camera.render(sphere, toLight, 400, 300);

    const std::string path = "image.png";
    PngSaver saver;
    saver.save(image, path);

    std::cout << path << "\n";

    return 0;
}
