#include<GL/glut.h>

void display()
{
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,0,0);
	
	//House
	glBegin(GL_LINE_LOOP);
	glVertex2i(10,15);
	glVertex2i(10,30);
	glVertex2i(30,30);
    	glVertex2i(40,40);
    	glVertex2i(60,40);
	glVertex2i(70,30);
	glVertex2i(70,15);
	glVertex2i(60,15);
	glVertex2i(55,15);
	glVertex2i(30,15);
	glVertex2i(25,15);
	glEnd();


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
