/*
 *Interaction program using callback function.cpp
 * Author:Yun Pei Chao 
 */
#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>
#include <GL/glut.h>
#include <stdlib.h>
int n = 0;
void mydispFun() // 固定畫出一個 多邊形 function.

{
	glClear(GL_COLOR_BUFFER_BIT); //清掉 buffer
	glBegin(GL_POLYGON); // 開始GL 命令, 畫多邊形.

	glColor3f(1.0, 0.0, 0.0);
	//glColor3f(1.5, 6.7, 0.4);
	glVertex3f(0.0, 0.0, 0.0); // 與上面 GL_POLYGON 相關 的頂點定義.

	glColor3f(0.0, 1.0, 0.0);
	//glColor3f(5.5, 6.5, 2.5);
	glVertex3f(0.3, 0.0, 0.0); // 


	glColor3f(0.0, 0.0, 1.0);
	//glColor3f(5.5, 2.5, 0.4);
	glVertex3f(0.4, 0.4, 0.0);

	glColor3f(1.0, 1.0, 0.0);
	//glColor3f(5.5, 6.5, 4.4);
	glVertex3f(0.0, 0.5, 0.0);
	glEnd(); // 結束 GL begin
	glFlush(); // update 結果.
}

void drawSquare()
{
	glColor3ub((char)rand() % 256, (char)rand() % 256,
		(char)rand() % 256); /* a random color */
	glBegin(GL_POLYGON);
	glVertex2f(-0.5, -0.5);
	glVertex2f(-0.5, 0.5);
	glVertex2f(0.5, 0.5);
	glVertex2f(0.5, -0.5);
	glEnd();
	glFlush();
}

void drawRSquare()
{
	glColor3f(1, 0, 0); /* a random color */
	glBegin(GL_POLYGON);
	glVertex2f(-0.5, -0.5);
	glVertex2f(-0.5, 0.5);
	glVertex2f(0.5, 0.5);
	glVertex2f(0.5, -0.5);
	glEnd();
	glFlush();
}
void drawGSquare()
{
	glColor3f(0, 1, 0);
	glBegin(GL_POLYGON);
	glVertex2f(-0.5, -0.5);
	glVertex2f(-0.5, 0.5);
	glVertex2f(0.5, 0.5);
	glVertex2f(0.5, -0.5);
	glEnd();
	glFlush();
}
void drawBSquare()
{
	glColor3f(0, 0, 1);
	glBegin(GL_POLYGON);
	glVertex2f(-0.5, -0.5);
	glVertex2f(-0.5, 0.5);
	glVertex2f(0.5, 0.5);
	glVertex2f(0.5, -0.5);
	glEnd();
	glFlush();
}

void mouse(int btn, int state, int x, int y)
{
	if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if (n % 3 == 0)
			drawRSquare();
		else if (n % 3 == 1)
			drawGSquare();
		else
			drawBSquare();
		n++;
	}
	if (btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
		exit(0);
}

void mykey(unsigned char key, int x, int y)
{
	if (key == 'R' || key == 'r')
		drawRSquare();
	if (key == 'G' || key == 'g')
		drawGSquare();
	if (key == 'B' || key == 'b')
		drawBSquare();
	if (key == 'Q' || key == 'q')
		exit(0);
}

void init()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
}

void mydisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glutMouseFunc(mouse);
	glutKeyboardFunc(mykey);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("simple");
	glutDisplayFunc(mydisplay);
	init();
	glutMainLoop();
}