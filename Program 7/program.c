#include<stdio.h>
#include<GL/glut.h>

float v[4][3]={{1,1,1},{-1,1,-1},{-1,-1,1},{1,-1,-1}};

int n;

void init()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2,2,-2,2,-5,5);
	glMatrixMode(GL_MODELVIEW);

}

void triangle(float *a,float *b,float *c)
{
	glBegin(GL_TRIANGLES);
	glVertex3fv(a);
	glVertex3fv(b);
	glVertex3fv(c);
	glEnd();
}

void dividetriangle(float *a,float *b,float *c,int m)
{
	int i;
	float v1[3],v2[3],v3[3];
	if(m>0)
	{
		for(i=0;i<3;i++)
		{
			v1[i]=(a[i]+b[i])/2;
			v2[i]=(b[i]+c[i])/2;
			v3[i]=(c[i]+a[i])/2;
		}
		dividetriangle(a,v1,v3,m-1);
		dividetriangle(b,v1,v2,m-1);
		dividetriangle(c,v2,v3,m-1);
	}
	else
		triangle(a,b,c);
}

void tetrahedron(int m)
{
	glColor3f(1,0,0);
	dividetriangle(v[0],v[1],v[2],m);
	glColor3f(0,0,1);
	dividetriangle(v[1],v[0],v[3],m);
	glColor3f(0,1,0);
	dividetriangle(v[0],v[2],v[3],m);
	glColor3f(1,1,0);
	dividetriangle(v[1],v[2],v[3],m);
}

void display()
{
	glClearColor(0,0,0,1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(2,2,2,1,1,1,0,1,0);
	tetrahedron(n);
	glFlush();
}


void main(int argc,char **argv)
{

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	printf("Enter Level of Sierpinski Gasket: ");
	scanf("%d",&n);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(600,600);
	glutCreateWindow("Sierpinski Gasket");
	init();
	glEnable(GL_DEPTH_TEST);
	glutDisplayFunc(display);
	glutMainLoop();
}
