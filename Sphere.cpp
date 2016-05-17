#include "Sphere.hpp"
#include <math.h>
Sphere::Sphere(){}

//set sphere with vector center, and double radius
void Sphere::set(Vector ctr, double radius){
    this->ctr = ctr;
    this->radius = radius;
}

// calculate intersection point. if there is at least one intersection point,
//returns 1. returns 0 otherwise.
bool Sphere::intersect_sphere (RAY_T ray, double &t, Vector &int_pt, Vector &normal) {
	//initialize variables
    double A,B,C;
    
    //constants of the equation
    A = 1;
    B = 2.0 * (ray.dir.dot(ray.origin-ctr));
    C = pow((ray.origin-ctr).length(),2) - pow(radius,2);
	
	//discriminant. >0 if theres intersect point. <=0 if none.
    double deter = pow(B,2) - 4 * A * C;

    //if determinant < 0, return 0. otherwise, calculate t and return 1.
    if (deter <= 0) return 0;
    else {
    	t = (-B - sqrt(deter)) / (2 * A);
    	int_pt = ray.origin + ray.dir * t;
    	normal = (int_pt - ctr)/radius;
    	return 1;
    }

}
