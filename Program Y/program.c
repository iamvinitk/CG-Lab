#include<stdio.h>
#include<GL/glut.h>

//float v[4][3]={{0,0,1},{-1,-1,-1},{1,-1,-1},{0,1,-1}};
float v[4][3]={{1,1,1},{-1,1,-1},{-1,-1,1},{1,-1,-1}};//for a proper tetrahedron

int m;

float theta[3]={0.0,0.0,0.0};

int axis=3,flag=0;
void spin()
{
	if(flag==1)
		theta[axis]+=2.0;
		
	if(theta[axis]>360.0)
		theta[axis]-=360.0;

	if(theta[axis]<0.0)
		theta[axis]=0.0;
	
	glutPostRedisplay();
}

void init()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2,2,-2,2,-5,5);
	//glFrustum(-2,2,-2,2,1,20);
	glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();
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
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(0,0,3,0,0,0,0,1,0);
	
	glRotatef(theta[0],1,0,0);
	glRotatef(theta[1],0,1,0);
	glRotatef(theta[2],0,0,1);
	
	//fun variation start
	//float c=0.0001;
	//float v2[4][3]={{1-c,1-c,1-c},{-1+c,1-c,-1+c},{-1+c,-1+c,1-c},{1-c,-1+c,-1+c}};
	//int a0=0,a1=1,a2=2,a3=3,t;
	//for(int i=0;i<4;i++)
	/*{
		glColor3f(0,0,0);
		glBegin(GL_TRIANGLES);
		glVertex3fv(v2[a0]);
		glVertex3fv(v2[a1]);
		glVertex3fv(v2[a2]);
		glEnd();
		
		t=a0;a0=a1;a1=a2;a2=a3;a3=t;
	}
	//fun variation end
	*/
	tetrahedron(m);
	glutSwapBuffers();
	glFlush();
}

void MyMouse(int btn, int state, int x, int y)
{
	if(btn==GLUT_RIGHT_BUTTON && state==GLUT_DOWN){
		flag=0; axis=1;/*y-rotation start*/}
	if(btn==GLUT_RIGHT_BUTTON && state==GLUT_UP){
		flag=1; axis=1;/*y-rotation stop*/}
	if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN){
		flag=0; axis=0;/*x-rotation start*/}
	if(btn==GLUT_LEFT_BUTTON && state==GLUT_UP){
		flag=1; axis=0;/*x-rotation stop*/}
	if(btn==GLUT_MIDDLE_BUTTON && state==GLUT_DOWN){
		flag=0; axis=2;/*z-rotation start*/}
	if(btn==GLUT_MIDDLE_BUTTON && state==GLUT_UP){
		flag=1; axis=2;/*z-rotation stop*/}
}


void main(int argc,char **argv)
{
	
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
	
	printf("Enter Level of Sierpinski Gasket: ");
	scanf("%d",&m);
	
	glutInitWindowPosition(0,0);
	glutInitWindowSize(600,600);
	glutCreateWindow("Sierpinski Gasket");
	
	init();
	glEnable(GL_DEPTH_TEST);
	glutMouseFunc(MyMouse);
	glutIdleFunc(spin);
	glutDisplayFunc(display);
	glutMainLoop();
}
