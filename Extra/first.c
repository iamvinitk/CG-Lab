#include<GL/glut.h>

void display()
{
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,0,0);
	
	//House
	glBegin(GL_POLYGON);
	glColor3f(1,0,0);
	glVertex2i(10,10);
	glVertex2i(10,50);
	glVertex2i(50,50);
    glVertex2i(50,10);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1,0,1);
	glVertex2i(10,50);
	glVertex2i(30,70);
	glVertex2i(50,50);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0,1,0);
	glVertex2i(25,10);
	glVertex2i(25,25);
	glVertex2i(35,25);
	glVertex2i(35,10);
	glEnd();
	//Triangle
	glBegin(GL_POLYGON);
	glColor3f(0,0,1);
	glVertex2i(60,10);
	glVertex2i(70,20);
	glVertex2i(80,10);
	glEnd();
	
	for(int i=10;i<50;i++)
	{

	glBegin(GL_POINTS);
	glVertex2i(90,i);
	glVertex2i(92,i);
	glVertex2i(94,i);
	glVertex2i(96,i);
	glVertex2i(98,i);
	glVertex2i(90,11);
	glVertex2i(92,12);
	glVertex2i(94,13);
	glVertex2i(96,14);
	glVertex2i(98,15);
	glEnd();
	}
	glFlush();

}
void Init()
{
	gluOrtho2D(0,150,0,150);
}

void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(50,50);
	glutInitWindowSize(500,500);
	glutCreateWindow("Line");
	Init();
	glutDisplayFunc(display);
	glutMainLoop();
	
}
