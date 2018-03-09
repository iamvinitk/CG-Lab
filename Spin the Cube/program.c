#include<GL/glut.h>
#include<stdio.h>
#include<math.h>

float ver[][3]={{-1,-1,-1},{1,-1,-1},{1,1,-1},{-1,1,-1},{-1,-1,1},{1,-1,1},{1,1,1},{-1,1,1}};


void polygon(int a,int b,int c,int d)
{
	//glColor3f(1,0,0);
	glBegin(GL_POLYGON);
	glVertex3fv(ver[a]);
	glVertex3fv(ver[b]);
	glVertex3fv(ver[c]);
	glVertex3fv(ver[d]);
	glEnd();
}

void color_cube()
{
	glColor3f(1.0,1.0,0.0);
	polygon(0,3,2,1);

	glColor3f(1.0,0.7,0.0);
	polygon(2,3,7,6);

	glColor3f(1.0,1.0,1.0);
	polygon(0,4,7,3);

	glColor3f(1.0,0.0,1.0);	
	polygon(1,2,6,5);

	glColor3f(0.4,0.6,0.8);
	polygon(4,5,6,7);

	glColor3f(0.8,0.2,0.1);	
	polygon(0,1,5,4);

	
}

void init()
{
	glOrtho(-2,2,-2,2,-5,5);
        glMatrixMode(GL_PROJECTION);
	glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();
}

void display()
{	glClearColor(0,0,0,1);

	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	
	
	color_cube();
	glRotatef(40,0,1,1);
	glFlush();

}

void main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE| GLUT_DEPTH);
	glutInitWindowPosition(50,50);
	glutInitWindowSize(500,500);
	glutCreateWindow("Spin Cube");
	init();
	glutDisplayFunc(display);
        glEnable(GL_DEPTH_TEST);
	glutMainLoop();
}

/* void color_cube()
{
	glColor3f(1.0,0.0,0.0);
	polygon(0,1,2,3);

	glColor3f(1.0,1.0,0.0);
	polygon(0,3,6,7);

	glColor3f(1.0,1.0,1.0);
	polygon(1,2,5,4);

	glColor3f(1.0,0.0,1.0);	
	polygon(2,3,6,5);

	glColor3f(1.4,0.6,0.8);
	polygon(0,7,4,1);

	glColor3f(1.8,0.2,0.1);	
	polygon(7,4,5,6);

	
}

void init()
{
	glOrtho(-2,2,-1,2,-5,5);
        glMatrixMode(GL_PROJECTION);
	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
}

void display()
{

	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glClearColor(0,0,0,1);
	glColor3f(1.0,0.0,0.0);
	color_cube();
	glEnd();
	glFlush();

}

void main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE |GLUT_DEPTH);
	glutInitWindowPosition(50,50);
	glutInitWindowSize(500,500);
	glutCreateWindow("Spin the Cube");
	init();
	glutDisplayFunc(display);
        glEnable(GL_DEPTH_TEST);
	glutMainLoop();
}

*/
