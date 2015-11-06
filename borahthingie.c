#include <stdio.h>
#include <stdlib.h> //for rand()
#include <unistd.h> //for 'usleep function'
#include "gfx2.h"
#include <math.h>

//functions
void drawCircle();


int main() {
	int i, dx = 0, dy = 0;
	char c;

	gfx_open(600, 600, "Emily Carnival");
	gfx_clear_color(225, 205, 230);

	do {
		drawCircle();


		gfx_event_waiting();
		if (gfx_event_waiting()) {
			c = gfx_wait();
		}
	} while (c != 'q');

	return 0;
}

void drawCircle() {
	int i, j, x, y;
	int xc = 310, yc = 310;
	double angle;


	while (1) {


		for (angle=0; angle<(2*M_PI); angle+=0.1) {
			for (i=150; i<155; i++) {
				gfx_color(150, 180, 250);
				x = 10*cos(angle) + (xc);
				y = 10*sin(angle) + (yc);
				gfx_circle(x, y, i); //draw main circle
			}

			gfx_color(0, 205, 0);
			x = 150*cos(angle+1) + (xc);	//car 1 green
			y = 150*sin(angle+2) + (yc);
			gfx_circle(x, y, 30);
			gfx_color(0, 0, 0);
			gfx_line() //

			gfx_color(205, 0, 0);
			x = 150*cos(angle+2) + xc;	//car 2 red
			y = 150*sin(langle+3) + (yc);
			gfx_circle(x, y, 30);

			gfx_color(0, 128, 255);
			x = 150*cos(angle+3) + (xc);	//car 3 sky blue
			y = 150*sin(angle+4) + (yc);
			gfx_circle(x, y, 30);



			// gfx_fill_arc(x, y, 30, 30, 0, 360); //can't use gfx_fill_arc <?>
			gfx_flush();
			usleep(20000);
			gfx_clear();
		}
	}
}