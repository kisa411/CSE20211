#include <stdio.h>
#include <math.h>
#include "gfx.h"


int main () {
	char userInput; 
	int i, sideLength;
	double theta, dtheta, numberSides;
	double x, y;
	double x_new, y_new;

	gfx_open(500,500,"Symbol_Emily_Koh");

	//gfx_xpos(); gets x coordinates of mouse pointer
	//gfx_ypos(); gets y coordinates of mouse pointer

	while (1) {
		gfx_event_waiting();
			if (gfx_event_waiting() == True) {
				userInput = gfx_wait();
			}
		
		if (userInput == 1) {
			//if user clicks mouse button 1 then display blue square
			gfx_color(0, 0, 255); //dictates color as blue
			x = gfx_xpos();
			y = gfx_ypos();
			gfx_line(x-50, y-50, x-50, y+50);
			gfx_line(x-50, y-50, x+50, y-50);
			gfx_line(x+50, y-50, x+50, y+50);
			gfx_line(x+50, y+50, x-50, y+50);
		} else if (userInput == 't') {
			//if user types in t then display green triangle
			gfx_color(0, 255, 0); //dictates color as green
			x = gfx_xpos();
			y = gfx_ypos();
			gfx_line(x-50, y-50, x+50, y-50);
			gfx_line(x-50, y-50, x, y+50);
			gfx_line(x, y+50, x+50, y-50);
		} else if (userInput == 'c') {
			//if user types in c then display white circle
			gfx_color(255, 255, 255); //dictates color as white
			x = gfx_xpos();
			y = gfx_ypos();
			gfx_circle(x, y, 50); //circle centered at x, y, and with radius 50
		} else if (userInput >= '3' && userInput <= '9') {
			//if user types in numbers 3~9, display purple polygon with that many sides

			sideLength = 30;

			numberSides = userInput - '0'; //makes numberSides = number of polygon sides

			dtheta = (2*M_PI/numberSides); //calculate the angle at which line will rotate
			theta = 0;

 			gfx_color(171, 92, 223); //dictates color as purple
			x = gfx_xpos();
			y = gfx_ypos();

			x = x + (sideLength/2); //to center polygon, shift polygon by this x and the following y value
			y = y + (sideLength/(2*tan(M_PI/numberSides))); //apothem - perpendicular y distance

			for (i = 0; i < numberSides; i++) {
				theta += dtheta;
				x_new = x + sideLength*cos(theta);
				y_new = y - sideLength*sin(theta);
				gfx_line(x, y, x_new, y_new); 
				gfx_flush();
				x = x_new;
				y = y_new;
			} userInput = '0';
		} else if (userInput == 'q') {
			//if user types in q then quit program
			break;
		}
	}

	// gcc symbol.c gfx_mac.o -lX11 -lm -I/opt/X11/include/ -L/opt/X11/lib/ -o symbol

	return 0;
}

