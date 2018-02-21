#include<GL/glut.h>
#include<stdio.h>
int x1,x2,y1,y2;
void init()
{
	
	gluOrtho2D(0,500,0,500);
	glMatrixMode(GL_PROJECTION);
}

void draw_pixel(int x,int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
}

void draw_line(int x1,int x2,int y1,int y2)
{
	int dx,dy,i,e,incx,incy,inc1,inc2,x,y;
	dx=x2-x1;
	dy=y2-y1;
	if(dx<0)
		dx=-dx;
	if(dy<0)
		dy=-dy;
	incx=1;
	if(x2<x1)
		incx=-1;
	incy=1;
	if(y2<y1)
		incy=-1;
	x=x1;
	y=y1;
	if(dx>dy)
	{
		draw_pixel(x,y);
		e=2*dy-dx;
		inc1=2*(dy-dx);
		inc2=2*dy;
		for(i=0;i<dx;i++)
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
		for(i=0;i<dy;i++)
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

void display()
{	
	int a1,b1;
	glColor3f(0,0,1);
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1,1,1,1);	
	draw_line(x1,x2,y1,y2);
	a1=x1-50;
	b1=y1-50;
	draw_line(a1,x2,b1,y2);
	draw_line(a1,x1,b1,y1);
	glFlush();
}

void main(int argc,char **argv)
{
	printf("Enter the four points:");
	scanf("%d%d%d%d",&x1,&x2,&y1,&y2);	
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
	glutCreateWindow("Prog1");
	glutInitWindowPosition(50,50);
	glutInitWindowSize(500,500);
	init();
	display();
	glutMainLoop();
}


