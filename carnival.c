#include <stdio.h>
#include <stdlib.h> //for rand()
#include <unistd.h> //for 'usleep function'
#include "gfx2.h"
#include <math.h>

//functions
void drawCircle(void);
void circlePosition(void);


int main() {
	int i, dx = 0, dy = 0;
	char c;

	gfx_open(600, 600, "Emily Carnival");
	gfx_clear_color(225, 205, 230);

	do {
		drawCircle();
		// circlePosition();

		gfx_event_waiting();
		if (gfx_event_waiting()) {
			c = gfx_wait();
		}
	} while (c != 'q');

	return 0;
}

void drawCircle(void) {
	int i, j, x, y, mainx, mainy, dx = 1;
	int xc = 310, yc = 310;
	double angle = 0;


	while (1) {
		//create circle with randomized colors
		xc = xc + dx;
		angle += 0.1;
		if (angle >= 2*M_PI) {
			angle = angle - 2*M_PI;
		}

		printf("dx is :%d and xc is: %d\n", dx, xc);
		
		if (xc >= 415) { //x-boundaries of graphics window
			xc = 415;
			dx = -dx; //re-set location of circle
		} else if (xc <= 185) {
			xc = 185;
			dx = -dx;
		}

		for (i=150; i<155; i++) {
			gfx_color(150, 180, 250);
			x = 30*cos(angle) + (xc);
			y = 30*sin(angle) + (yc);
			gfx_circle(x, y, i); //draw main circle
			mainx = x;
			mainy = y;
		}

		gfx_color(0, 205, 0);
		x = 30*cos(angle+1) + (mainx-120);	//car 1 green
		y = 30*sin(angle+1) + (mainy-70);
		gfx_circle(x, y, 30);
		gfx_color(0, 0, 0);
		gfx_line((mainx-120), (mainy-70), (mainx-120+dx), (mainy-70)); //line 1
		

		gfx_color(205, 0, 0);
		x = 30*cos(-angle+1) + mainx;	//car 2 red
		y = 30*sin(-angle+1) + (mainy-150);
		gfx_circle(x, y, 30);
		gfx_color(0, 0, 0);
		gfx_line((mainx), (mainy-150), (mainx+dx), (mainy-150));  //line 2
		

		gfx_color(0, 128, 255);
		x = 30*cos(angle+2) + (mainx+120);	//car 3 sky blue
		y = 30*sin(angle+2) + (mainy-70);
		gfx_circle(x, y, 30);
		gfx_color(0, 0, 0);
		gfx_line((mainx+120), (mainy-70), (mainx+120+dx), (mainy-70));  //line 3
		

		gfx_color(255, 153, 51);
		x = 30*cos(angle+1) + (mainx+120);	//car 4 orange
		y = 30*sin(angle+1) + (mainy+70);
		gfx_circle(x, y, 30);
		gfx_color(0, 0, 0);
		gfx_line((mainx+120), (mainy+70), (mainx+120+dx), (mainy+70));  //line 4
		

		gfx_color(204, 0, 102);
		x = 30*cos(angle+2) + mainx;	//car 5 rose
		y = 30*sin(angle+2) + (mainy+150);
		gfx_color(0, 0, 0);
		gfx_line((mainx), (mainy+150), (mainx+dx), (mainy+150));  //line 5
		gfx_circle(x, y, 30);

		gfx_color(0, 0, 205);
		x = 30*cos(-angle+1) + (mainx-120);	//car 6 blue
		y = 30*sin(-angle+1) + (mainy+70);
		gfx_circle(x, y, 30);
		gfx_color(0, 0, 0);
		gfx_line((mainx-120), (mainy+70), (mainx-120+dx), (mainy+70));  //line 6
	

		// gfx_fill_arc(x, y, 30, 30, 0, 360); //can't use gfx_fill_arc <?>
		gfx_flush();
		usleep(25000);
		gfx_clear();
	}
	
}





