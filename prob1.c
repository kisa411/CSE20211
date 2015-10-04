
/* Emily Koh
FCI
Lab 3 Part 1 - simple function */

#include <stdio.h>

//function declaration
int getgcd(int a, int b);

//main function
int main (void)
{
    int a, b;
    
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);
    
    printf("The greatest common denominator between the two integers is: %d\n", getgcd(a, b));
    
    return 0;
}

//gcd function 
int getgcd (int a, int b)
{
    int c;
    while ( a != 0 ) {
        c = a; a = b%a;  b = c;
    }
    
    return b;
}

