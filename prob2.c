/* Emily Koh
FCI
Lab 3 Part 2 - quadrants and polar coordinates*/

#include <stdio.h>
#include <math.h>

//declare function prototype for converting from cartesian to polar
double hypotenuse (double a, double b);
double conversion (double x, double y);

int main (void)
{
    double x, y;
    double angle = conversion(x,y);
    
    //ask user for cartesian coordinates
    printf("What are the cartesian coordinates? (x,y)");
    scanf("(%lf, %lf)", &x, &y);
    
    //convert cartesian coordinates into r and angle (call on function conversion)
    printf("The polar radius is %.2lf and the polar angle is %.1lf radians.\n", hypotenuse(x, y), conversi$
    

    //define pi (M_PI = pi)    
    
    //if-elif statements about which quadrant the point is in
    if (x > 0.0 && y > 0.0) {
        printf("The point is in quadrant 1.");
    } else if (angle == 0 && hypotenuse == 0) {
        printf("The point is on the origin.");
    } else if (x < 0.0 && y > 0.0) {
        printf("The point is in quadrant 2.");
    } else if (x < 0.0 && y > 0.0) {
        printf("The point is in quadrant 3.");
    } else {
	printf("The point is in quadrant 4.");
    }
    printf("\n");
      
    //if-elif statements about specific cases (on x-axis, y-axis, origin)
    if (x > 0 && y == 0) {
        printf("The point is on the x-axis.");
    } else if (x == 0 && y > 0) {
        printf("The point is on the y-axis.");
    } else if (x < 0 && y ==0) {
        printf("The point is on the x-axis.");
    } else if (x == 0 && y < 0.) {
        printf("The point is on the y-axis.");
    } else if (x == 0. && y == 0.) {
        printf("The point is on the origin.");
    }  
    printf("\n");
    
    return 0;
}


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
