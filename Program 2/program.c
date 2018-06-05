#include<GL/glut.h>
#include<math.h>
#include<stdio.h>


float triangle[3][3]={{350,450,550},{400,573,400},{1,1,1}};
float rot_mat[3][3]={{0},{0},{0}};
float result[3][3]={{0},{0},{0}};
float h=0,k=0,m=0,n=0,theta;
void multiply()
{
	int i,j,l;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++)
		{
			result[i][j]=0;
			for(l=0;l<3;l++)
			{
				result[i][j]+=rot_mat[i][l]*triangle[l][j];
			}
		}
	}
	for(i=0;i<3;i++){
		for(j=0;j<3;j++)
		{
			printf("%f\t",result[i][j]);
		}
		printf("\n");
	}
}

void rrotate(float m,float n)
{
	rot_mat[0][0]=cos(theta);
	rot_mat[0][1]=-sin(theta);
	rot_mat[0][2]=m;
	rot_mat[1][0]=sin(theta);
	rot_mat[1][1]=cos(theta);
	rot_mat[1][2]=n;
	rot_mat[2][0]=0;
	rot_mat[2][1]=0;
	rot_mat[2][2]=1;
	multiply();
}

void drawtriangle()
{
	glBegin(GL_LINE_LOOP);
	glVertex2f(triangle[0][0],triangle[1][0]);
	printf("Normal Triangle %f %f\n", triangle[0][0],triangle[1][0]);
	glVertex2f(triangle[0][1],triangle[1][1]);
	printf("Normal Triangle %f %f\n", triangle[0][1],triangle[1][1]);
	glVertex2f(triangle[0][2],triangle[1][2]);
	printf("Normal Triangle %f %f\n", triangle[0][2],triangle[1][2]);
	glEnd();
}

void drawrotatetriangle()
{
	glBegin(GL_LINE_LOOP);
	glVertex2f(result[0][0],result[1][0]);
	printf("Rotate Triangle %f %f\n", result[0][0],result[1][0]);
	glVertex2f(result[0][1],result[1][1]);
	printf("Rotate Triangle %f %f\n", result[0][1],result[1][1]);
	glVertex2f(result[0][2],result[1][2]);
	printf("Rotate Triangle %f %f\n", result[0][2],result[1][2]);
	glEnd();
}

void display()
{
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,0,0);
	drawtriangle();
	rrotate(0,0);
	glColor3f(0,0,0);
	drawrotatetriangle();
	m=h*(cos(theta)-1)+k*(sin(theta));
	n=-k*(cos(theta)-1)-h*(sin(theta));
	printf("m: %f n: %f\n",m, n );
	rrotate(m,n);
	glColor3f(1,0,1);
	drawrotatetriangle();
	glFlush();
}

void Init()
{
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0,1000,0,1000);
	glMatrixMode(GL_MODELVIEW);

}

void main(int argc, char **argv)
{
	printf("Enter the values for theta, h and k:");
	scanf("%f%f%f",&theta,&h,&k);
	theta=theta*(3.14/180);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(50,50);
	glutInitWindowSize(1000,1000);
	glutCreateWindow("Triangle Rotation");
	Init();
	glutDisplayFunc(display);
	glutMainLoop();

}
