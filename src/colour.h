#pragma once

class Colour {
public:
    Colour(double r, double g, double b);

    double r() const;
    double g() const;
    double b() const;

private:
    double _r;
    double _g;
    double _b;
};
