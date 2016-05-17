#ifndef LIGHT_H
#define LIGHT_H

#include "Vector.hpp"
#include "rt.hpp"

// Light class with private variable loc(location), illuminate and constructor
class Light
{
    public:
        Light();
        Light(double x, double y, double z);
        COLOR_T illuminate(RAY_T ray, COLOR_T surface_color, Vector int_pt, Vector normal);

    private:
        Vector loc;
};

#endif // LIGHT_H
