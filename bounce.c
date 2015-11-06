#include <stdio.h>
#include <stdlib.h> //for rand()
#include <unistd.h> //for 'usleep function'
#include "gfx.h"

int main() {
	double x, y, dx, dy;
	char c = '0';

	gfx_open(500,500,"Bounce_Emily_Koh"); //open graphics window

	//do random direction 
	do {
		gfx_color(143, 160, 215);

		gfx_circle(x, y, 20); //draw circle while changing its coordinates by specified random amount
		x += dx;
		y += dy;

		gfx_flush(); //after you draw everything you want, ensures that it makes it show onto the screen

		usleep(5000); //makes image stay on screen for specified milliseconds

		gfx_clear(); //clear screen of previous animations

		if (x > 480) { //x-boundaries of graphics window
			x = 480;
			dx = -dx; //re-set location of circle
		} else if (x < 20) {
			x = 20;
			dx = -dx;
		} else if (y > 480) {
			y = 480;
			dy = -dy;
		} else if (y < 20) { //y-boundaries of graphics window
			y = 20;
			dy = -dy;
		}	

		if (c == 1) {
			x = gfx_xpos(); //get mouse location
			y = gfx_ypos(); //get mouse location

			dx = rand()%3; //randomly changes speed of circle
			dy = rand()%3; //randomly changes speed of circle

			c = '0';	
		}	

		if (gfx_event_waiting()) {
			c = gfx_wait(); //repeat loop until user clicks mouse
		}	
	} while (c != 'q'); //do-while 


	// gcc bounce.c gfx_mac.o -lX11 -lm -I/opt/X11/include/ -L/opt/X11/lib/ -o bounce
	return 0;
}

