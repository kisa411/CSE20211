#include <stdio.h>
#include <math.h>

double myexp(double x);

int main()
{
	double i, x;
	
    //ask user for value of x
	printf("Give me a number:");
	scanf("%lf", &x);

    //print approximation 
	printf("%.3lf\n", myexp(x));	


    //print exp function
    printf("Using math library function, sum is %.3lf\n", exp(x));
    
	return 0;
}

double myexp(double x) {

    double sum = 1, i, value = 1;

    
    //add the consecutive values to sum
	for (i = 1; i < 12; i++) {
		value = value * (x/i);
		sum += value;
	}

	return sum;
}



