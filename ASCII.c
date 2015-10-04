/*Emily Koh
FCI
Lab 2 Part 3 */

#include <stdio.h>
#include <math.h>

int main (void) {
    //declare function
    printf ("A plot of y = 10(cos(x)+3) from x=0 to 20.0\n");
    
    //declare variables
    double x, y;
    
    printf("   X     Y   \n");
    
    //declare variables
    double min = 40.0;
    double max = 0.0;
    double maxX = 0.0;
    double minX = 0.0;
    
    //evaluate function with x incrementing at 0.2
    for (x = 0.0; x <= 20.0; x += 0.2) {
        y = 10*(cos(x)+3);
        
        if (y >=0) {
            printf("%2.2lf", x);
            printf("    %0.2lf    ", y);
         
        //set maximum
        if ( y >= max) {
            max = y;
            maxX = x;
        } 
        
        //set minimum
        if ( y <= min && y >= 0.0) {
            min = y;
            minX = x;
        }           
            
            //print out # characters
            for (int counter = 0; counter < round(y); counter ++) {
                printf("#");
            }
          
        }
        printf("\n");    

    }
    
    //print out maximum and minimum values
    printf("The maximum of %lf was at x = %lf\n", max, maxX);
    printf("The minimum of %lf was at x = %lf", min, minX);   
        
 
    
    return 0;
}
