
#include<GL/glut.h>
#include<stdio.h>
#include<math.h>


float cp[3][2] = {{1,1}, {3,3}, {4,1}};

void myInit()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0,500,0,500);
}

void biezercoeff(float n, float *c){
	for(int k=0; k<n; k++){
		c[k] = 1;
		for(int i=n; i>=(n-k); i--){
			c[k]*=i;
		}
		for(int i=(n-k); i>=1; i--){
			c[k]/=i;
		}
	}
}

void myDisplay()
{
	float c[4];
	int n =3;
	float x, y, u, blend;
	glColor3f(1,0,0);
	glBegin(GL_LINE_STRIP);
	for(float u=0; u<1; u+=0.1){
		float x=0, y=0;
		for(int k=0; k<=n; k++){
			blend=c[k] * pow(u, k) * pow((1-u), (n-k));
			x+=cp[k][0] * blend;
			y+=cp[k][1] * blend;
		}
	}
   	glEnd();
	glFlush();
}

int main(int argc,char** argv)
{

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(50,50);
	glutInitWindowSize(500,500);
	glutCreateWindow(".Line.");
	myInit();
	glutDisplayFunc(myDisplay);
	glutMainLoop();
	return 0;
}
