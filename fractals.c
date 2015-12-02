#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "gfx4.h"


//function prototypes//
void mytriangledrawingfunction(int x1, int y1, int x2, int y2, int x3, int y3);
void mysquaredrawingfunction(int x1,int y1,int x2,int y2,int x3,int y3, int x4, int y4);
void sierpinski(int x1, int y1, int x2, int y2, int x3, int y3);
void shrinking(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int change);
void spiralsquares(int x1, int y1, int w, double angle);
void circularlace(int x1, int y1, int radius);
void snowflake(int x1, int y1, int r);
void tree(int x1, int y1, int r, double angle);
void fern(int x1, int y1, int r, double angle);
///////////////////////


int main () {
int userInput, loop = 1;
char c;

	gfx_open(600, 600, "Emily Fractals"); //open window

	printf("Which fractal would you like to draw?\n1. Sierpinski Triangle \n2. Shrinking Squares \n3. Spiral Squares\n4. Circular Lace\n5. Snowflake\n6. Tree\n7. Fern\n8. Quit");

	while (loop) {		

		gfx_event_waiting();
		if (gfx_event_waiting()) {
			c = gfx_wait();
			switch (c) {
				case '1': //Sierpinski Triangle
					gfx_clear();
					sierpinski(80, 80, 520, 80, 300, 520);
					gfx_flush();
					break;
				case '2': //Shrinking Squares
					gfx_clear();
					shrinking(100, 100, 500, 100, 500, 500, 100, 500, 300);
					gfx_flush();
					break;
				case '3': //Spiral Squares
					gfx_clear();
					spiralsquares(300, 300, 5, M_PI/5); 
					gfx_flush();
					break;
				case '4': //Circular Lace
					gfx_clear();
					circularlace(300, 300, 200); 
					gfx_flush();
					break;
				case '5': //Snowflake
					gfx_clear();
					snowflake(300, 300, 150);
					gfx_flush();
					break;
				case '6': //Tree
					gfx_clear();
					tree(300, 600, 150, (M_PI/2));
					gfx_flush();
					break;
				case '7': //Fern
					gfx_clear();
					fern(300, 600, 400, (M_PI/2));
					gfx_flush();
					break;
				case '8':
					loop = 0;
			}
		}
	}

	return 0;

}

//triangle drawing function
void mytriangledrawingfunction(int x1,int y1,int x2,int y2,int x3,int y3) {
	gfx_line(x1, y1, x2, y2);
	gfx_line(x2, y2, x3, y3);
	gfx_line(x1, y1, x3, y3);
}

//square drawing function
void mysquaredrawingfunction(int x1,int y1,int x2,int y2,int x3,int y3, int x4, int y4) {
	gfx_line(x1, y1, x2, y2);
	gfx_line(x2, y2, x3, y3);
	gfx_line(x3, y3, x4, y4);
	gfx_line(x4, y4, x1, y1);
}


//Sierpinski Triangle
void sierpinski(int x1, int y1, int x2, int y2, int x3, int y3) {
   //Base case
   if( abs(x2-x1) <= 2 ) return;

   //Draw the triangle
   mytriangledrawingfunction(x1, y1, x2, y2, x3, y3 );

   //Recursive calls
   sierpinski( x1, y1, (x1+x2)/2, (y1+y2)/2, (x1+x3)/2, (y1+y3)/2 );
   sierpinski( (x1+x2)/2, (y1+y2)/2, x2, y2, (x2+x3)/2, (y2+y3)/2 );
   sierpinski( (x1+x3)/2, (y1+y3)/2, (x2+x3)/2, (y2+y3)/2, x3, y3 );
}

//Shrinking Squares
void shrinking(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int change) {
	//Base case
	if (abs(x2-x1) <= 20) return;

	//draw the square
	mysquaredrawingfunction(x1, y1, x2, y2, x3, y3, x4, y4);

	//shrinking factor
	change = 0.5*change;
	
	//Recursive calls
	shrinking((x1-change), (y1-change), (x1+change), (y1-change), (x1+change), (y1+change), (x1-change), (y1+change), change);
	shrinking((x2-change), (y2-change), (x2+change), (y2-change), (x2+change), (y2+change), (x2-change), (y2+change), change);
	shrinking((x3-change), (y3-change), (x3+change), (y3-change), (x3+change), (y3+change), (x3-change), (y3+change), change);
	shrinking((x4-change), (y4-change), (x4+change), (y4-change), (x4+change), (y4+change), (x4-change), (y4+change), change);

}

//Spiral Squares
void spiralsquares(int x1, int y1, int w, double angle) {
	//Base case
	if ((w) >= 400) return;

	//draw the square
	gfx_rectangle(x1, y1, w, w);

	//Reassign coordinates
	angle = angle+M_PI/5;

	x1 = x1 + (3*w*cos(angle));  
	y1 = y1 + (3*w*sin(angle));

	//Recursive calls
	spiralsquares(x1, y1, 1.5*w, angle);
}

//Circular Lace
void circularlace(int x1, int y1, int radius) {
	int x2, y2;

	//Base case
	if (radius <= 2) return;
	//draw the circles
	gfx_circle(x1, y1, radius);

	x2 = (cos(M_PI/3))*radius;
	y2 = (sin(M_PI/3))*radius;

	//new radius
	int radius2 = radius/4;


	//Recursive calls
	circularlace(x1+radius, y1, radius2); //circle 1 - starting from x=0
	circularlace((x1+x2), (y1-y2), radius2); //circle 2
	circularlace((x1-x2), (y1-y2), radius2); //circle 3
	circularlace(x1-radius, y1, radius2); //circle 4
	circularlace((x1-x2), (y1+y2), radius2); //circle 5
	circularlace((x1+x2), (y1+y2), radius2); //circle 6
}


//Snowflake
void snowflake(int x1, int y1, int r) { //r = radius
	int i;

	//Base case
	if (r <= 2) return; //if length of line is less than 5 px
	double angle = (2*M_PI/5);
	//draw the line
	for (i=1; i<=5; i++){ 
		gfx_line(x1, y1, (x1+(r*sin(i*angle))), (y1+(r*cos(i*angle)))); 

		//recursive calls
		snowflake((x1+(r*sin(i*angle))), (y1+(r*cos(i*angle))), 0.25*r);
	}

}

//Tree
void tree(int x1, int y1, int r, double angle) { //r = radius
	double dt = M_PI/6; //angle to change by

	//Base case
	if (r <= 2) return; //if length of line is less than 5 px

	//draw the line
    gfx_line(x1, y1, x1+r*cos(angle), y1-r*sin(angle));

    //Recursive calls
    tree(x1+r*cos(angle), y1-r*sin(angle), 0.8*r, angle+dt); //right branch
    tree(x1+r*cos(angle), y1-r*sin(angle), 0.8*r, angle-dt); //left branch
}

//Fern
void fern(int x1, int y1, int r, double angle) {
	double dt = M_PI/6; //angle to change by

	//Base case
	if (r <= 2) return; //if length of line is less than 5 px

	//draw the lines
    gfx_line(x1, y1, x1+r*cos(angle), y1-r*sin(angle));

    //Recursive calls
    fern((x1+r*cos(angle)/4), (y1-r*sin(angle)/4), 0.3*r, angle+dt); //right branch 1
    fern((x1+r*cos(angle)/4), (y1-r*sin(angle)/4), 0.3*r, angle-dt); //left branch 2
   	fern((x1+r*cos(angle)/2), (y1-r*sin(angle)/2), 0.3*r, angle+dt); //right branch 2
   	fern((x1+r*cos(angle)/2), (y1-r*sin(angle)/2), 0.3*r, angle-dt); //left branch 2
   	fern((x1+(3*r*cos(angle))/4), (y1-(3*r*sin(angle))/4), 0.3*r, angle+dt); //right branch 3
    fern((x1+(3*r*cos(angle))/4), (y1-(3*r*sin(angle))/4), 0.3*r, angle-dt); //left branch 3
   	fern((x1+r*cos(angle)), (y1-r*sin(angle)), 0.3*r, angle+dt); //right branch 4
   	fern((x1+r*cos(angle)), (y1-r*sin(angle)), 0.3*r, angle-dt); //left branch 4
}












