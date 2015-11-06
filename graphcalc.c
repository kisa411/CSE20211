#include <stdio.h>
#include <stdlib.h> //for rand()
#include <unistd.h> //for 'usleep function'
#include "gfx2.h"
#include <math.h>
#include <string.h>


//1. need to figure out how to compute Taylor series approximation
//2. need to figure out how to draw axes


long double computeY(int i, long double x); //function to compute y-coordinates given x-coordinates
void plot(int i); //function to plot x,y coordinates
void drawAxes(void); //function to draw axes
char *num2str(int n); //converts numbers into strings
long double factorial(int i);

int main() {
	int y;
	char c;
	int terms = 1, x; //terms = # of terms

	gfx_open(600, 600, "Emily Graphing Calculator");

	printf("Press + key to increase the number of terms, press - key to decrease the number of terms\n");

	while (1) {
		gfx_color(255, 255, 255); //set color of curve
		plot(terms); //default number of terms is 1
		drawAxes();

		if (gfx_event_waiting()) {
			c = gfx_wait();
			if (c == '=') { 
				gfx_clear(); //clear screen before drawing new function
				terms++;
			} else if (c == '-') { 
				gfx_clear(); //clear screen before drawing new function
				terms--;
				if (terms <=0) {
					printf("The number of terms cannot be lower than 0."); //ensure number of terms is always greater than or equal to 0
					terms=1;
				}
			} else if (c == 'q') {
				break;
			}
		}

	printf("The number of terms is: %d\n", terms);
	}

	return 0;
}

long double computeY(int terms, long double x) { //function to compute the y-value for given x of Taylor Series approximation
	long double value, sum = 0, num, dem, number; //i = number of terms
	int i;

	for (i=1; i<=terms; i++) {
		if (i%2 == 0) {
			num = pow(x, (2*i-1));
			dem = factorial(2*i-1);
			number = -(num/dem);
		} else {
			num = pow(x, (2*i-1));
			dem = factorial(2*i-1);
			number = (num/dem);
		} sum = sum + number;
	} 
	

	return sum; 
}

long double factorial(int i) { //calculates factorial
	int number;
	long double total = 1; 

	for (number = 1; number <= i; number++) {
		total = total*number;
	}

	return total;

}

void plot(int terms) {
	long double x, y;
	int pixx, pixy;

	for (pixx=1; pixx<=600; pixx++) { //plot the x- and y-coordinates from the range x(1-600)
		x = ((long double)pixx-301)/30;
		y = computeY(terms, x);
		pixy = -((y*30)-301);
		gfx_flush();
		gfx_point(pixx, pixy);
	}	
}



void drawAxes() { //function to draw the axes
	int x, y, number;
	char* numberString;

	gfx_color(50, 100, 150); //set color of axes

	//draw x-axis
	gfx_line(1, 300, 620, 300);

	//draw y-axis
	gfx_line(300, 1, 300, 620);
	
	//label x-axis
	x = 1;
	y = 310;
	while (x <= 600) {
		number = -10;
		while (x <= 310) {
			numberString = num2str(number);
			gfx_text(x, y, numberString); //will print [-10, 0]
			gfx_text(x, 305, "|");
			x+=30;
			// printf("1. %d\n", number);
			number++;
		}  
		number = 1;
		while (x > 310 && x <= 620) {
			numberString = num2str(number);
			gfx_text(x, y, numberString); //will print [1, 10]
			gfx_text(x, 305, "|");
			x+=30;
			// printf("2. %d\n", number);
			number++;	
		}

	}

	//label y-axis
	x = 310;
	y = 13;
	number = 10;
	while (y <= 600) {
		while (y <= 310) {
			numberString = num2str(number);
			gfx_text(x, y, numberString); //will print [10, 0]
			gfx_text(295, y, "-");
			y+=29;
			// printf("3. %d\n", number);
			number--;
		} while (y > 310 && y <= 600) {
			numberString = num2str(number);
			gfx_text(x, y, numberString); //will print [1, -10]
			gfx_text(300, y, "-");
			y+=29;
			// printf("4. %d\n", number);
			number--;
		}

	}
}

char *num2str(int n) {
	static char a[10], *p = a;
	snprintf(p, 10, "%d", n);
	return p;
}


