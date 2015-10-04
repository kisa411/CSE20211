#include <stdio.h>
#include <math.h>
#include "polarfn.h"

//write out function for calculating hypotenuse
double hypotenuse (double a, double b) {
    double r;
    
    r = sqrt((a*a)+(b*b));
    return r;
}

//write out function for converting cartesian to polar 
double conversion (double x, double y) {
    double angle;
    
    angle = atan(y/x);
    if (x < 0.0 && y > 0.0) {
        angle += (M_PI/2);
    } else if (x < 0.0 && y < 0.0) {
        angle += (M_PI);
    } else if (x > 0.0 && y < 0.0) {
        angle += ((3*M_PI)/2);
    } else {
	angle = angle;
    }
    return angle;
}
