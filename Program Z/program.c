
#include<GL/glut.h>
#include<stdio.h>
#include<math.h>


float cp[4][2] = {{40,350}, {210,300}, {310, 400}, {430, 340}};

void myInit()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1,1,1,1);
	gluOrtho2D(0,500,0,500);
}

void biezercoeff(float n, float *c){
	for(int k=0; k<=n; k++){
		c[k] = 1;
		for(int i=n; i>=k+1; i--){
			c[k]*=i;
		}
		for(int i=(n-k); i>=2; i--){
			c[k]/=i;
		}
	}
}

void myDisplay()
{
	float c[4];
	int n=3;
	float x, y, u, blend;

	glColor3f(1,0,0);
	for(int m=0; m<4;m++){
	biezercoeff(n, c);
	glBegin(GL_LINE_STRIP);
		for(float u=0; u<1; u+=0.1){
		x=0, y=0;
			for(int k=0; k<=n; k++){
			blend=c[k] * pow(u, k) * pow((1-u), (n-k));
			x+=cp[k][0] * blend;
			y+=cp[k][1] * blend;
			}
		glVertex2f(x , y);
		}
		   	glEnd();
		for(int z=0; z<4; z++){
			//cp[z][0] += 10;
			cp[z][1] += 40;
		}	
	}
	glBegin(GL_LINES);
	glVertex2i(40, 470);
	glVertex2i(40, 100);
	glVertex2i(395, 474);
	glVertex2i(395, 354);
	glEnd();
	glFlush();
}

int main(int argc,char** argv)
{

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(50,50);
	glutInitWindowSize(500,500);
	glutCreateWindow("Flag");
	myInit();
	glutDisplayFunc(myDisplay);
	glutMainLoop();
	return 0;
}
