#ifndef VECTOR_H
#define VECTOR_H


class Vector
{
    public:
    
    	//all its prototype methods, including operator overloading.
        Vector(void);
        Vector(double x, double y, double z);
        void set(double x, double y, double z);
        
        double dot(Vector v);
        void normalize(void);
        
        Vector add(Vector v);
        Vector operator+(Vector v);
        Vector subtract(Vector v);
        Vector operator-(Vector v);
        Vector mult(Vector v);
        Vector operator*(Vector v);
        Vector scal_mult(double s);
        Vector operator*(double s);
        Vector scal_divide(double s);
        Vector operator/(double s);

        double sum_components(void);
        double length(void);
		
    private:
    	//private variables x,y,z for its direction & magnitude.
        double x;
        double y;
        double z;
};

#endif // VECTOR_H
