#ifndef SPHERE_H
#define SPHERE_H

#include "Vector.hpp"
#include "rt.hpp"

//set Sphere class and its private variables, public method prototypes.
class Sphere
{
    public:
        Sphere();
        void set(Vector ctr, double radius);
        bool intersect_sphere(RAY_T ray, double &t, Vector &int_pt, Vector &normal);
        
    private:
        Vector ctr;
        double radius;
};

#endif // SPHERE_H
