#include<stdio.h>
#include<stdlib.h>
#include<GL/glu.h>
#include<GL/gl.h>
#include<GL/glut.h>
#include<math.h>
#include<SOIL/SOIL.h>
#include<time.h>
#include"function.h"
const screenWidth =  700;
const screenHeight = 700;
#define l  0.892486418
void myInit()
{
	glClearColor(1.0,1.0,0.0,0.0);       
	glColor3f(0.0, 0.0, 0.0);         
	glPointSize(5.0);                   
	setWindow((GLdouble)0.0,(GLdouble)1.0,(GLdouble)0.0,(GLdouble)1.0);
	setViewport(0.0,screenWidth,0.0,screenHeight);	
	
}
int flag=0;
double mapFunction(double x)
{
	double i;
	double xk=4*l*x*(1-x);
	glBegin(GL_LINE_STRIP);
	glVertex2f(x,xk);
	glVertex2f(xk,xk);
	//if(xk<(1-1/4*l))
	if(flag <1000)    //only for limited number of recursion exact condition for prevent infinite recursion not found
	{
	flag++;
	mapFunction(xk);
	}
	else return;
	glEnd();
	
}

void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	double x0=0.1,i;
	glBegin(GL_LINE_STRIP);
	for(i=0.0;i<=1.2;i+=0.05)
	glVertex2f(i,4*l*i*(1-i));
	glVertex2f(0.0,0.0);
	glVertex2f(1.0,1.0);
	glEnd();
	//drawCircle(0.2,0.9,0.07);
	mapFunction(x0);
	
}



void main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(screenWidth,screenHeight);
	glutInitWindowPosition(100,100);
	glutCreateWindow("logistic");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}
