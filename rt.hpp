#ifndef RT_H
#define RT_H

#include "Vector.hpp"

//set RAY TYPE, COLOR TYPE
typedef struct
{
    Vector origin;
    Vector dir;
}RAY_T;

typedef struct
{
    double R;
    double G;
    double B;
}COLOR_T;
#endif // RT_H
