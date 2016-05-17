#ifndef OBJ_HPP_INCLUDED
#define OBJ_HPP_INCLUDED

#include "rt.hpp"
#include "Sphere.hpp"

//set OBJECT TYPE
typedef struct OBJ {
        Sphere sphere;
        COLOR_T color;
        struct OBJ *next;
}OBJ_T;

#endif // OBJ_HPP_INCLUDED
