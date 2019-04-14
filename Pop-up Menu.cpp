/*
 *Pop-up Menu.cpp
 * Author:Yun Pei Chao 
 */
#include <GL/glut.h> 
#include<stdio.h> 
#include<stdlib.h> 

/* initial triangle */
GLfloat v[3][3] = { { -1.0, -0.58 },
{ 1.0, -0.58 },{ 0.0, 1.15 } };
int n = 0; /* number of recursive steps */
int id;
int id1;
double r = 0, g = 0, b = 0;

void mouse(int btn, int state, int x, int y);
void display();
void divide_triangle(GLfloat *a, GLfloat *b, GLfloat *c, int m);

void mymenu(int id)
{
	if (id == 1)
	{
		n = 1;
		glutPostRedisplay();
	}
	if (id == 2)
	{
		n = 2;
		glutPostRedisplay();
	}
	if (id == 3)
	{
		n = 3;
		glutPostRedisplay();
	}
	if (id == 4)
	{
		r = 1; g = 0; b = 0;
		glutPostRedisplay();
	}
	if (id == 5)
	{
		r = 0; g = 1; b = 0;
		glutPostRedisplay();
	}
	if (id == 6)
	{
		r = 0; g = 0; b = 1;
		glutPostRedisplay();
	}
	if (id == 7) exit(0);
}

void mouse(int btn, int state, int x, int y)
{
	if (btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		id = glutCreateMenu(mymenu);

		glutAddMenuEntry("N=1", 1);
		glutAddMenuEntry("N=2", 2);
		glutAddMenuEntry("N=3", 3);
		glutCreateMenu(mymenu);


		id1 = glutCreateMenu(mymenu);
		glutAddMenuEntry("Red", 4);
		glutAddMenuEntry("Green", 5);
		glutAddMenuEntry("Blue", 6);
		glutCreateMenu(mymenu);
		glutAddSubMenu("N", id);
		glutAddSubMenu("Color", id1);


		glutAddMenuEntry("exit", 7);


		glutAttachMenu(GLUT_RIGHT_BUTTON);
	}
}



void myReshape(int w, int h)
{
	glViewport(0, 0, w, h);
}



void triangle(GLfloat *a, GLfloat *b, GLfloat *c)
{
	glVertex3fv(a);
	glVertex3fv(b);
	glVertex3fv(c);
}

void divide_triangle(GLfloat *a, GLfloat *b, GLfloat *c, int m)
{
	GLfloat v1[3], v2[3], v3[3];
	int j;
	if (m > 0)
	{
		for (j = 0; j < 3; j++) v1[j] = (a[j] + b[j]) / 2;
		for (j = 0; j < 3; j++) v2[j] = (a[j] + c[j]) / 2;
		for (j = 0; j < 3; j++) v3[j] = (b[j] + c[j]) / 2;
		divide_triangle(a, v1, v2, m - 1);
		divide_triangle(c, v2, v3, m - 1);
		divide_triangle(b, v3, v1, m - 1);
	}
	else
		triangle(a, b, c);
}




void myinit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-2.0, 2.0, -2.0, 2.0);
	glMatrixMode(GL_MODELVIEW);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(0.0, 0.0, 0.0);
}

void tetrahedron(int m)
{
	glColor3f(r, g, b);
	divide_triangle(v[0], v[1], v[2], m);

	divide_triangle(v[3], v[2], v[1], m);

	divide_triangle(v[0], v[3], v[1], m);

	divide_triangle(v[0], v[2], v[3], m);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_TRIANGLES);
	tetrahedron(n);
	glutMouseFunc(mouse);
	glEnd();
	glFlush();

}
int main(int argc, char **argv)
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutCreateWindow("2D Gasket");
	glutDisplayFunc(display);
	myinit();
	glutMainLoop();
	glutReshapeFunc(myReshape);

}