#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "gfx4.h"

void circularlace(int x1, int y1, int radius, int R, int G, int B);

int main() {
	int i;
	int x, y, R, G, B, radius;
	char c;

	gfx_open(700, 700, "Emily Gallery of Fractals");

	for (i=0; i<=16; i++) {
		x = (rand()%500)+100;
		y = (rand()%500)+100;
		radius = rand()%80;
		R = rand()%200;
		G = rand()%200;
		B = rand()%200;
		circularlace(x, y, radius, R, G, B);
	}

	while(1){
		gfx_event_waiting();
		if (gfx_event_waiting()) {
			c = gfx_wait();
			if (c == 'q') break;
		}
	}
	
	return 0;
}

//Circular Lace
void circularlace(int x1, int y1, int radius, int R, int G, int B) {
	int x2, y2;

	//Base case
	if (radius <= 2) return;
	//draw the circles
	gfx_color(R, G, B);
	gfx_circle(x1, y1, radius);

	x2 = (cos(M_PI/3))*radius;
	y2 = (sin(M_PI/3))*radius;

	//new radius
	int radius2 = radius/4;


	//Recursive calls
	circularlace(x1+radius, y1, radius2, R, G, B); //circle 1 - starting from x=0
	circularlace((x1+x2), (y1-y2), radius2, R, G, B); //circle 2
	circularlace((x1-x2), (y1-y2), radius2, R, G, B); //circle 3
	circularlace(x1-radius, y1, radius2, R, G, B); //circle 4
	circularlace((x1-x2), (y1+y2), radius2, R, G, B); //circle 5
	circularlace((x1+x2), (y1+y2), radius2, R, G, B); //circle 6
}
