#include "rt.hpp"
#include "obj.hpp"
#include "Light.hpp"
#include <iostream>

void read_objs (OBJ_T **list) {
	//declare variables, set *list to null
    double x,y,z,r,R,G,B;
    Vector ctr;
    OBJ_T *node;
    *list = NULL;
    
    while(std::cin >> x >> y >> z >> r >> R >> G >> B){
    	//assign memory space to node
        node = new OBJ_T;
        //assign variables of node to the inputs.
        ctr.set(x,y,z);
        node->sphere.set(ctr,r);
        node->color = (COLOR_T) { .R = R, .G = G, .B = B};

        //new.next points to list, and list points to new. then go back to
        //beginning of while loop
        node->next = *list;
        *list = node;

    }
}

COLOR_T trace (RAY_T ray, OBJ_T *list, Light light) {
	//declare variables, initialize some of them
    Vector closest_int_pt,closest_normal,int_pt,normal;
    double t,min_t;
    min_t = 1000;
    COLOR_T color;
    color = (COLOR_T) { .R = 0, .G = 0, .B = 0};
    OBJ_T *closest_obj;
    closest_obj = NULL;
    OBJ_T *obj;
    
    //traverse through the object linked list, find the closest object
    for (obj = list; obj != NULL;obj = obj->next){
        if(obj->sphere.intersect_sphere(ray,t,int_pt,normal)) {
            if(t<min_t){
                closest_obj = obj;
                closest_int_pt = int_pt;
                closest_normal = normal;
                min_t = t;
            }
        }
    }
	
	//set color according to the light and illumiinate
    if(closest_obj != NULL) {
        color = light.illuminate(ray,closest_obj->color,closest_int_pt,closest_normal);
    }
    return color;
}

int main() {
	//declare variables, initialize them.
	int i,j;
    RAY_T ray;
    OBJ_T *node;
    read_objs(&node);
    COLOR_T pixel = (COLOR_T) { .R = 1, .G = 1, .B = 1};
    std::cout << ("P6\n 1000 1000\n 255\n");
    Light light = Light(5.0,10.0,0);
	
	//traverse through each pixel points in the image
    for ( i = 0; i < 1000; i++) {
        for ( j = 0; j < 1000; j++ ) {
        	//set ray for each pixels
            ray.origin.set(0,0,0);
            ray.dir.set(-0.5 + j / 1000.0, 0.5 - i / 1000.0, 1);
            ray.dir.normalize();
			
			//set color for the pixel
            pixel = trace(ray,node,light);
			
			//cap color
            if (pixel.R > 1.0) pixel.R = 1.0;
            if (pixel.G > 1.0) pixel.G = 1.0;
            if (pixel.B > 1.0) pixel.B = 1.0;
            
			//print pixels
            std::cout<<(unsigned char)(pixel.R * 255)
                       <<(unsigned char)(pixel.G * 255)
                       <<(unsigned char)(pixel.B * 255);
        }
    }
    //free memory space allocated to node
    delete(node);
    return 0;
}
