#include "Light.hpp"
#include <math.h>

//constructor without any variables
Light::Light() {
}

//constructor
Light::Light(double x, double y, double z){
    loc.set(x,y,z);
}

COLOR_T Light::illuminate(RAY_T ray, COLOR_T surface_color, Vector int_pt, Vector normal){
    COLOR_T col;
    //ambient
    col.R = surface_color.R * 0.1;
    col.G = surface_color.G * 0.1;
    col.B = surface_color.B * 0.1;

    //diffuse
    double dot;
    Vector L;
    L = loc - int_pt;
    L.normalize();
    dot = L.dot(normal);
    if (dot > 0) {
        col.R += dot * surface_color.R;
        col.G += dot * surface_color.G;
        col.B += dot * surface_color.B;


    //specular
        Vector R;
        R = L - normal * dot * 2.0;
        R.normalize();
        double dot2 = R.dot(ray.dir);
        if (dot2 > 0) {
            col.R += pow(dot2,200);
            col.G += pow(dot2,200);
            col.B += pow(dot2,200);
        }
    }
    return col;
}
