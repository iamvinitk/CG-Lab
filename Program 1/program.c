

#include<GL/glut.h>
#include<stdio.h>
int x,y;
int x1,x2,y1,y2;
void myInit()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0,0,0,1);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0,500,0,500);
}

void draw_pixel(int x,int y)
{
	glColor3f(1,0,0);
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
	glFlush();
}



void draw_line(int x1,int x2,int y1,int y2)
{
	int dx,dy,i,e;
	int incx,incy,inc1,inc2;
	dx=x2-x1;
	dy=y2-y1;
	
	if(dx<0)dx=-dx;
	if(dy<0)dy=-dy;
	incx=1;

	if(x2<x1)incx=-1;
	
	incy=1;

	if(y2<y1)incy=-1;

	if(dx>dy)
	{
		draw_pixel(x,y);
		e=2*dy-dx;
		inc1=2*(dy-dx);
		inc2=2*dy;
		for(int i=0;i<dx;i++)
		{
			if(e>=0)
			{
				y+=incy;
				e+=inc1;
			}
			
			else 
				e+=inc2;

				x+=incx;
				draw_pixel(x,y);
		}
	}

	else
	{
		draw_pixel(x,y);
		e=2*dx-dy;
		inc1=2*(dx-dy);
		inc2=2*dx;
		for(int i=0;i<dy;i++)
		{
			if(e>=0)
			{
				x+=incx;
				e+=inc1;
			}
			else
				e+=inc2;

				y+=incy;
				draw_pixel(x,y);
		}	
	}
}



void myDisplay()
{
	draw_line(x1,x2,y1,y2);
   	glEnd();
	glFlush();
}

int main(int argc,char** argv)
{
	
	printf("Enter 4 points");
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	printf("(%d,%d) (%d,%d)",x1,y1,x2,y2);
	
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




