#include "math/vector.h"
#include "colour/colour.h"
#include "ray/ray.h"
#include "geometry/sphere.h"
#include "render/camera.h"
#include <iostream>

using math::Vector;

int main() {
    Camera camera(Vector(0, 0, -1), Vector(0, 0, 0));
    Sphere sphere(Vector(0, 0, 9), 5.0, Colour(1, 0, 0));

    Ray ray = camera.rayThroughCentre();

    Colour pixelColour(0, 0, 0);
    if (sphere.isHitBy(ray)) {
        pixelColour = sphere.colour();
    }

    std::cout << "(" << pixelColour.r() << ", " << pixelColour.g() << ", " << pixelColour.b() << ")\n";

    return 0;
}
