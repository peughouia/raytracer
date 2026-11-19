#include "render/camera.h"

using math::Vector;

Camera::Camera(const Vector& eye, const Vector& screenCentre, double screenWidth)
    : _eye(eye), _screenCentre(screenCentre), _screenWidth(screenWidth) {}

Ray Camera::rayThroughCentre() const {
    return Ray(_eye, _screenCentre - _eye);
}

Ray Camera::rayThroughPixel(int column, int row, int width, int height) const {
    double pixelSize = _screenWidth / width;
    double x = (column + 0.5 - width / 2) * pixelSize;
    double y = (row + 0.5 - height / 2.0) * pixelSize;
    Vector pixelCentre = _screenCentre + Vector(x, y, 0);
    return Ray(_eye, pixelCentre - _eye);
}
