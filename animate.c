//make juggler 

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h> //for 'usleep function'
#include "gfx.h"


void drawPerson(void);

int main () {
	int x, y, dx, dy, radius = 100;
	double pi, i = 0.07;
	char c;

	pi = M_PI;

	gfx_open(500,500,"Rotating Animation Emily");

	printf("To speed up display press f key; to slow down display press s key.\n");

	while (1) {
			drawPerson();

			x = radius*cos(i) + 250;
			y = radius*sin(i) + 150;
			gfx_color(0, 0, 255);
			gfx_circle(x, y, 20); //ball 1 (blue)
		
			x = radius*cos(i+1.5) + 250;
			y = radius*sin(i+1.5) + 150;
			gfx_color(0, 255, 0);
			gfx_circle(x, y, 20); //ball 2 (green)

			x = radius*cos(i+3.) + 250;
			y = radius*sin(i+3.) + 150;
			gfx_color(255, 0, 0);
			gfx_circle(x, y, 20); //ball 3 (red)
			

			gfx_flush();
			usleep(10000);
			gfx_clear();
			

			if (gfx_event_waiting()) {
				c = gfx_wait();
				if (c =='s') { //slows down juggling
					i-=0.1;
				} else if (c =='f') { //speeds  juggling
					i+=0.1;
				} else if (c =='q') {
					break;
				}
			}

			i+= 0.01;
		}

	
	

	return 0;
}

void drawPerson(){

	//make body - half circle
	gfx_color(204, 0, 102);
	gfx_circle(250, 550, 100);
	usleep(500);

	//make head
	gfx_color(255, 255, 0);
	gfx_circle(250, 400, 50);
	usleep(500);
	//make face
	gfx_point(225, 400); //eye
	usleep(500);
	gfx_point(275, 400); //eye
	usleep(500);

	//make arms
	gfx_line(200, 460, 150, 370);
	gfx_line(300, 460, 350, 370);

	usleep(500);
}

