#include<GL/glut.h>
#include<bits/stdc++.h>
using namespace std;
#define PI 3.1416

int nCtrlPts = 4, nBezCurvePts = 20, flag = 1;

typedef struct bcPoints
{
	float x, y, z;
} bcPoints;

void bino(int *C)
{
	int k, j, n=nCtrlPts-1;
	for(k=0;k<nCtrlPts;k++)
	{
		C[k]=1;
		for(j=n;j>=k+1; j--)
		C[k]*=j;
		for(j=n-k;j>=2;j--)
		C[k]/=j;
	}
}


void computeBezPt(float u, bcPoints *bezPt, bcPoints *ctrlPts, int *C)
{
	int k, n = nCtrlPts-1;
	float bezBlendFcn;
	bezPt ->x =bezPt ->y = bezPt->z=0.0;
	for(k=0; k < nCtrlPts; k++)
	{
		bezBlendFcn = C[k] * pow(u, k) * pow( 1-u, n-k);
		bezPt ->x += ctrlPts[k].x * bezBlendFcn;
		bezPt ->y += ctrlPts[k].y * bezBlendFcn;
		bezPt ->z += ctrlPts[k].z * bezBlendFcn;
	}
}
void bezier(bcPoints *ctrlPts)
{
	bcPoints bezCurvePt;
	float u;
	int *C, k;
	C = new int[nCtrlPts];
	bino(C);
	glBegin(GL_LINE_STRIP);
	for(k=0; k<=nBezCurvePts; k++)
	{
		u = float(k)/float(nBezCurvePts);
		computeBezPt(u, &bezCurvePt, ctrlPts, C);
		glVertex2f(bezCurvePt.x, bezCurvePt.y);
	}
	glEnd();
	delete[] C;
}

void displayFcn()
{
	printf("display called\n");
	static float theta = 0;
	bcPoints ctrlPts[4] = {
		{20, 100, 0},
		{30, 110, 0},
		{50, 90, 0},
		{60, 100, 0}
	};

	ctrlPts[1].x += 10*sin(theta * PI/180.0);
	ctrlPts[1].y += 5*sin(theta * PI/180.0);
	ctrlPts[2].x -= 10*sin((theta+30) * PI/180.0);
	ctrlPts[2].y -= 10*sin((theta+30) * PI/180.0);
	ctrlPts[3].x -= 4*sin((theta) * PI/180.0);
	ctrlPts[3].y += sin((theta-30) * PI/180.0);
	printf("%f\n", theta);
	theta+=20.0;

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glPointSize(5);

	glPushMatrix();
	glLineWidth(5);

	glColor3f(255/255, 153/255.0, 51/255.0);
	for(int i=0;i<8;i++)
	{
		glTranslatef(0, -0.8, 0);
		bezier(ctrlPts);
	}

	glColor3f(1, 1, 1);
	for(int i=0;i<8;i++)
	{
		glTranslatef(0, -0.8, 0);
		bezier(ctrlPts);
	}

	glColor3f(19/255.0, 136/255.0, 8/255.0);
	for(int i=0;i<8;i++)
	{
		glTranslatef(0, -0.8, 0);
		bezier(ctrlPts);
	}

	glPopMatrix();

	glColor3f(0.7, 0.5,0.3);
	glBegin(GL_LINES);
	glVertex2f(20,100);
	glVertex2f(20,40);
	glEnd();
	glFlush();

	if(flag == 1){
		glutPostRedisplay();
		glutSwapBuffers();

	}
}

void winReshapeFun(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 130, 0, 130);
	glClear(GL_COLOR_BUFFER_BIT);
}

void animateMenu(int id){
	if(id==1){
		flag = 1;
	}
	else if (id == 2){
		flag = 0;
	}
	else{
		exit(0);
	}
	glutPostRedisplay();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(600, 600);
	glutCreateWindow("Bezier Curve");
	glutDisplayFunc(displayFcn);
	glutReshapeFunc(winReshapeFun);
	glutCreateMenu(animateMenu);
	glutAddMenuEntry("Animate",1);
	glutAddMenuEntry("Stop",2);
	glutAddMenuEntry("Quit",3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
	return 0;
}
