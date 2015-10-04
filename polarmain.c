#include <stdio.h>
#include <math.h>
#include "polarfn.h"

int main (void)
{
    double x, y;
    double angle = conversion(x,y);
    
    //ask user for cartesian coordinates
    printf("What are the cartesian coordinates? (x,y)");
    scanf("(%lf, %lf)", &x, &y);
    
    //convert cartesian coordinates into r and angle (call on function conversion)
    printf("The polar radius is %.2lf and the polar angle is %.1lf radians.\n", hypotenuse(x, y), conversion (x, y));
    

    //define pi (M_PI = pi)    
    
    //if-elif statements about which quadrant the point is in
    if (x > 0.0 && y > 0.0) {
        printf("The point is in quadrant 1.");
    } else if (angle == 0 && hypotenuse == 0) {
        printf("The point is on the origin.");
    } else if (x < 0.0 && y > 0.0) {
        printf("The point is in quadrant 2.");
    } else if (x < 0.0 && y < 0.0) {
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