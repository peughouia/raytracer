#include "render/camera.h"
#include "render/trace.h"

using math::Vector;

Camera::Camera(const Vector& eye, const Vector& screenCentre, double screenWidth)
    : _eye(eye), _screenCentre(screenCentre), _screenWidth(screenWidth) {}

Ray Camera::rayThroughPixel(int column, int row, int width, int height) const {
    double pixelSize = _screenWidth / width;
    double x = (column + 0.5 - width / 2.0) * pixelSize;
    double y = (height / 2.0 - row - 0.5) * pixelSize;
    Vector pixelCentre = _screenCentre + Vector(x, y, 0);
    return Ray(_eye, pixelCentre - _eye);
}

Image Camera::render(const Sphere& sphere, const Vector& toLight, int width, int height) const {
    Image image(width, height);
    for (int row = 0; row < height; ++row) {
        for (int column = 0; column < width; ++column) {
            Ray ray = rayThroughPixel(column, row, width, height);
            image.setPixel(column, row, trace(ray, sphere, toLight));
        }
    }
    return image;
}
