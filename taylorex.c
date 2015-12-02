#include <stdio.h>
#include <math.h>

double myexp(double x);

int main(void) {
    printf("%lf\n", myexp(5));
   
    return 0;
}

double myexp(double x) {
	double i, sum = 1, value = 1;
	
	for (i=1; i<=4; i++) {
		value = value*(x/i);
		sum = sum+value;
	}
	
	return sum;
}
