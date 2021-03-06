#include<stdio.h>
#include<stdlib.h>
#include<GL/gl.h>
#include<GL/glut.h>
#include<GL/glu.h>
#include"function.h"
#include<math.h>
#include<time.h>
#include<SOIL/SOIL.h>
const screenWidth = 1500;
const screenHeight = 700;

myInit()
{
	glClearColor(0.0,0.0,0.0,0.0);
	glColor3f(0.0f,1.0f,0.0f);
	glLineWidth(1.0);
}

void hexSwirl()
{
	double angle;
	double angleInc = 2*(M_PI/6.0);
	double inc = 5.0/100.0;
	double radius=5.0/100.0;
	glClear(GL_COLOR_BUFFER_BIT);
	int i,j;
	for(i=0;i<100;i++)
	{
		angle = i;
		glBegin(GL_LINE_STRIP);
		for(j=0;j<=6;j++)
		{
			angle += angleInc;
			glVertex2d(radius * cos(angle), radius *sin(angle));
		}
		glEnd();
		radius += inc;
		 
	}
	glutSwapBuffers();
	SOIL_save_screenshot("/home/xpd54/personal/mywork/cg/output/hexswirl.bmp",SOIL_SAVE_TYPE_BMP,0,0,screenWidth,screenHeight);
	glFlush();
}


void zoomOut()
{
	float Cx = 0.3,Cy =0.2;
	float H,W = 1.2, aspect =0.7;
	setViewport(0.0,screenWidth,0.0,screenHeight);
	int frame ;
	
	for(frame =0;frame <12;frame++)
	{
		glClearColor(0.0,0.0,0.0,0.0);
		W -=aspect;
		H =W/aspect;
		setWindow(Cx - W,Cx + W,Cy - H,Cy +H);
		//sleep(0.01);
		hexSwirl();
	}
	glFlush();
}

void zoomIn()
{
	float Cx = 0.3,Cy =0.2;
	float H,W = 1.2, aspect =0.7;
	setViewport(0.0,screenWidth,0.0,screenHeight);
	int frame ;
	
	for(frame =0;frame <8;frame++)
	{
		glClearColor(0.0,0.0,0.0,0.0);
		W -=aspect;
		H =W/aspect;
		setWindow(Cx + W,Cx - W,Cy + H,Cy -H);
		//sleep(0.01);
		hexSwirl();
	}
	printf("%f   %f\n",W,H);
	glFlush();
}

void mouse(int button,int state, int x,int y )
{
	if( state == GLUT_DOWN)
	{
		if(button == GLUT_LEFT_BUTTON)
		zoomIn();
		if(button == GLUT_RIGHT_BUTTON)
		zoomOut();
		
	}
	
	
}


void main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(screenWidth,screenHeight);
	glutInitWindowPosition(100,150);
	glutCreateWindow("hexswirl");
	setWindow(-5.0, 5.0, -5.0, 5.0);
	setViewport(0.0,screenWidth,0.0,screenHeight);
	//glutDisplayFunc(zoomIn);
	glutMouseFunc(mouse);
	myInit();
	glutMainLoop();
}


