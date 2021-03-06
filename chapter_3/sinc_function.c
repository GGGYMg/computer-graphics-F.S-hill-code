#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<SOIL/SOIL.h>
//#include"function.h"
#include<math.h>
#include<SOIL/SOIL.h>

const float pi = 3.14159265358979;
//--------------------setWindow-------------

void setWindow(GLdouble left,GLdouble right,GLdouble bottom,GLdouble top)
{
	//define our own function to specify the window as explained 
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(left,right,bottom,top);
}

//------------------setViwport-------------------

void setViewport(GLint left,GLint right,GLint bottom,GLint top)
{	
	// define our own function to specify the window as explained--
	glViewport(left,bottom,right-left,top - bottom);
}

//<<<<<<<<<<<<<<<<<<<<<<<<< myDisplay>>>>>>>>>>>>>>>>>>>>>>>>>>>

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glBegin(GL_LINE_STRIP);
	// automatically uses the defined window and viewport clips properly and perform the proper mapping
	float x;
	for(x=-4.0;x<4.0;x+=0.1)
	{
		if(x == 0.0)
			glVertex2f(0.0,1.0);
		else
			glVertex2f(x,sin(3.14159 * x) /(3.14159 * x));
	
		
	}
	glEnd();
	glFlush();
	SOIL_save_screenshot("/home/xpd54/personal/mywork/cg/output/sinc.bmp",SOIL_SAVE_TYPE_BMP,0,0,640,480);
	
}

// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<,myInit>>>>>>>>>>>>>>>>>>>>>>>>>>>>>.

void myInit(void)
{
	glClearColor(1.0,1.0,1.0,0.0);
	glColor3f(0.0f,0.0f,1.0f);
	glLineWidth(2.0);
	
}

void main(int argc, char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(100,150);
	glutCreateWindow("sinc function");
	glutDisplayFunc(myDisplay);
	myInit();
	setWindow(-5.0,5.0,-0.3,1.0); // call the function to specify the window 
	setViewport(0,640,0,480);
	glutMainLoop();
}

