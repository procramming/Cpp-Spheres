#include "Vector.hpp"
#include <math.h>

// Vector class method definitions

//constructor with no input
Vector::Vector(){}

//constructor with directions
Vector::Vector(double x, double y, double z){
    set(x,y,z);
}

//setting a vector into a direction
void Vector::set(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

//dot product of two vectors
double Vector::dot(Vector v){
    double dp = x * v.x + y * v.y + z * v.z;
    return dp;
}

//normalizing a vector to length of 1
void Vector::normalize(void) {
    Vector result;
    double length = sqrt( pow(x,2) + pow(y, 2) + pow(z , 2.0) );
    this->set(x / length, y / length, z / length);
}

//adding two vectors
Vector Vector::add(Vector v){
    Vector rv;
    rv.x = x + v.x;
    rv.y = y + v.y;
    rv.z = z + v.z;
    return rv;
}
Vector Vector::operator+(Vector v){return this->add(v);}

//substracting input vector from a vector
Vector Vector::subtract(Vector v){
    Vector rv;
    rv.x = x - v.x;
    rv.y = y - v.y;
    rv.z = z - v.z;
    return rv;
}

Vector Vector::operator-(Vector v){return this->subtract(v);}

//multiplying vectors
Vector Vector::mult(Vector v){
    Vector rv;
    rv.x = x * v.x;
    rv.y = y * v.y;
    rv.z = z * v.z;
    return rv;
}
Vector Vector::operator*(Vector v){return this->mult(v);}

//scalar multiplying a vector
Vector Vector::scal_mult(double s){
    Vector rv;
    rv.x = x * s;
    rv.y = y * s;
    rv.z = z * s;
    return rv;
}
Vector Vector::operator*(double s){return this->scal_mult(s);}

//scalar dividing a vector
Vector Vector::scal_divide(double s){
    Vector rv;
    rv.x = x / s;
    rv.y = y / s;
    rv.z = z / s;
    return rv;
}
Vector Vector::operator/(double s){return this->scal_divide(s);}

//returns sum of its x,y,z components
double Vector::sum_components(void){
    return this->x + this->y + this->z;
}

//returns the length of the vector
double Vector::length(void){
    double len;
    len = pow(this->x,2) + pow(this->y,2) + pow(this->z,2);
    len = sqrt(len);
    return len;
}
