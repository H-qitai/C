#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	double x;
	double y;
} Point;

/********************************************************************************/
/********************************************************************************/
/******** This is the only function you need to define for this exercise ********/
/********************************************************************************/
/********************************************************************************/
/********************************************************************************/
void Sierpinski(int numPoints, Point a, Point b, Point c, Point d){

    int values[10000] = {0};

    for (int i = 0; i < numPoints;i++){
        values[i] = rand()%3;
    }

    for (int i = 0; i < numPoints; i++){
        if (values[i] == 0){
            d.x = (a.x+d.x) /2;
            d.y = (a.y+d.y) /2;
            printf("0 %f %f\n", d.x, d.y);
        }
        else if (values[i] == 1){
            d.x = (b.x+d.x) /2;
            d.y = (b.y+d.y) /2;
            printf("1 %f %f\n", d.x, d.y);
        }
        else if (values[i] == 2){
            d.x = (c.x+d.x) /2;
            d.y = (c.y+d.y) /2;
            printf("2 %f %f\n", d.x, d.y);
        }
    }
}
/********************************************************************************/
/********************************************************************************/
/********************************************************************************/
/********************************************************************************/
/********************************************************************************/
/********************************************************************************/


int main(void)
{
	Point a, b, c, d;
	int numPoints;

	/* Set the random number generator seed to 0 */
	/* This ensures the same sequence of random values occurs */
	/* which is useful for checking your program */
	srand(0);

	/* Initialise the positions of points a, b and c */
	a.x = 100;
	a.y = 173;

	b.x = 0;
	b.y = 0;

	c.x = 200;
	c.y = 0;

	/* Read the number of points to plot */
	printf("Enter number of points: ");
	scanf("%d", &numPoints);

	/* Initially point d is at some random location */
	//d.x = (double)(rand() % 100);
	//d.y = (double)(rand() % 100);

	d.x = 50;
	d.y = 50;

	/* Print out the points to plot */
	Sierpinski(numPoints, a, b, c, d);

	return 0;
}



