#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>

using namespace std;

GLfloat v[3][3] = { { -1.0, -0.58,0 },
{ 1.0, -0.58,0 },{ 0.0, 1.15,0 } };

int n;

void triangle(GLfloat *a, GLfloat *b, GLfloat *c)
/* display one triangle */
{
	glVertex2fv(a);
	glVertex2fv(b);
	glVertex2fv(c);
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
	else(triangle(a, b, c));
}
void tetrahedron(int m)
{
	glColor3f(0.0, 1.0, 0.0);
	divide_triangle(v[0], v[1], v[2], m);
	glColor3f(0.0, 0.0, 1.0);
	divide_triangle(v[3], v[2], v[1], m);
	glColor3f(0.0, 0.0, 0.0);
	divide_triangle(v[0], v[3], v[1], m);
	glColor3f(1.0, 0.0, 0.0);
	divide_triangle(v[0], v[2], v[3], m);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_TRIANGLES);
	divide_triangle(v[0], v[1], v[2], n);
	tetrahedron(n);
	glEnd();
	glFlush();
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

int main(int argc, char **argv)
{

	n = 5;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutCreateWindow("3D Gasket");

	glutDisplayFunc(display);
	myinit();
	glutMainLoop();
	system("pause");
	return 0;
}