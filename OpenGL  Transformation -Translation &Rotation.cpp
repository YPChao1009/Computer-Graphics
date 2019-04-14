/*
 *OpenGL  Transformation -Translation &Rotation.cpp
 * Author:Yun Pei Chao 
 */
#include <GL/glut.h>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
double color_1[3] = { 1.0,0.0,0.0 };
double color_2[3] = { 0.0,1.0,0.0 };
double color_3[3] = { 0.0,0.0,1.0 };
double color_4[3] = { 0.0,0.0,0.0 };
int rotate, transform;
/* initial triangle */
GLfloat v[3][3] = { { -1.0, -0.58 },{ 1.0, -0.58 },{ 0.0, 1.15 } };
int n; /* number of recursive steps */
void mouse(int btn, int state, int x, int y);
void timer(int t);
int xyz = 0;
GLfloat theta[4] = { 0, 0, 0, 0 };
int axis = 3;
int color, N;




void triangle(GLfloat *a, GLfloat *b, GLfloat *c)
{

	glBegin(GL_TRIANGLES);
	glVertex3fv(a);
	glVertex3fv(b);
	glVertex3fv(c);
	glEnd();
}
void divide_triangle(GLfloat *a, GLfloat *b, GLfloat *c, int m)//切割三角形
{
	GLfloat v1[3], v2[3], v3[3];
	int j;
	if (m > 0)
	{
		for (j = 0; j < 3; j++)
			v1[j] = (a[j] + b[j]) / 2;
		for (j = 0; j < 3; j++)
			v2[j] = (a[j] + c[j]) / 2;
		for (j = 0; j < 3; j++)
			v3[j] = (b[j] + c[j]) / 2;
		divide_triangle(a, v1, v2, m - 1);
		divide_triangle(c, v2, v3, m - 1);
		divide_triangle(b, v3, v1, m - 1);
	}
	else(triangle(a, b, c));
}

void tetrahedron(int m)
{  //設定顏色
	glColor3f(color_1[0], color_1[1], color_1[2]);
	divide_triangle(v[0], v[1], v[2], m);
	glColor3f(color_2[0], color_2[1], color_2[2]);
	divide_triangle(v[3], v[2], v[1], m);
	glColor3f(color_3[0], color_3[1], color_3[2]);
	divide_triangle(v[0], v[3], v[1], m);
	glColor3f(color_4[0], color_4[1], color_4[2]);
	divide_triangle(v[0], v[2], v[3], m);

}
void display()//展示結果
{
	glClear(GL_COLOR_BUFFER_BIT);
	//glBegin(GL_TRIANGLES);
	glPushMatrix();
	glRotatef(theta[0], 1.0, 0.0, 0.0);
	glRotatef(theta[1], 0.0, 1.0, 0.0);
	glRotatef(theta[2], 0.0, 0.0, 1.0);
	tetrahedron(n);
	glPopMatrix();
	glutSwapBuffers();


	// glEnd();


}
void myinit() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-2.0, 2.0, -2.0, 2.0);
	glMatrixMode(GL_MODELVIEW);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(0.0, 0.0, 0.0);
}


//讓圖形在視窗大小改變時，能維持原本形狀不變形
void reshape(GLsizei w, GLsizei h)
{
	GLfloat ratio = (GLfloat)w / (GLfloat)h;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)//保持形狀不變
		gluOrtho2D(-2.0, 2.0, -2.0 / ratio, 2.0 / ratio);
	else
		gluOrtho2D(-2.0*ratio, 2.0*ratio, -2.0, 2.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

//按下menu後，執行之指令
void processMenuEvents(int option)
{
	switch (option)
	{
		//顏色順序:RGBD
	case 0:
		color_1[0] = 1.0; color_1[1] = 0.0; color_1[2] = 0.0;
		color_2[0] = 0.0; color_2[1] = 1.0; color_2[2] = 0.0;
		color_3[0] = 0.0; color_3[1] = 0.0; color_3[2] = 1.0;
		color_4[0] = 0.0; color_4[1] = 0.0; color_4[2] = 0.0;
		display();
		break;
		//顏色順序:GBDR
	case 1:
		color_1[0] = 0.0; color_1[1] = 1.0; color_1[2] = 0.0;
		color_2[0] = 0.0; color_2[1] = 0.0; color_2[2] = 1.0;
		color_3[0] = 0.0; color_3[1] = 0.0; color_3[2] = 0.0;
		color_4[0] = 1.0; color_4[1] = 0.0; color_4[2] = 0.0;
		display();
		break;
		//顏色順序:BDRG
	case 2:
		color_1[0] = 0.0; color_1[1] = 0.0; color_1[2] = 1.0;
		color_2[0] = 0.0; color_2[1] = 0.0; color_2[2] = 0.0;
		color_3[0] = 1.0; color_3[1] = 0.0; color_3[2] = 0.0;
		color_4[0] = 0.0; color_4[1] = 1.0; color_4[2] = 0.0;
		display();
		break;
		//顏色順序:DRGB
	case 'd':
		color_1[0] = 0.0; color_1[1] = 0.0; color_1[2] = 0.0;
		color_2[0] = 1.0; color_2[1] = 0.0; color_2[2] = 0.0;
		color_3[0] = 0.0; color_3[1] = 1.0; color_3[2] = 0.0;
		color_4[0] = 0.0; color_4[1] = 0.0; color_4[2] = 1.0;
		display();
		break;

		//改變N之大小，N越大，圖形切割得越細
	case 8:
		n = 2;
		display();
		break;
	case 3:
		n = 3;
		display();
		break;
	case 4:
		n = 4;
		display();
		break;
	case 5:
		n = 5;
		display();
		break;
	case 6:
		n = 6;
		display();
		break;
	case 7:
		n = 7;
		display();
		break;
	case 9:
		axis = 0;
		display();
		break;
	case 10:
		axis = 1;
		display();
		break;
	case 11:
		axis = 2;
		display();
		break;
	case 12:
		axis = 3;
		display();
		break;
	case 13:
		xyz = 1;
		glTranslatef(0.3, 0, 0);
		display();
		break;
	case 14:
		xyz = 2;
		glTranslatef(0, 0.3, 0);
		display();
		break;
	case 15:
		xyz = 3;
		glTranslatef(0, 0, 0.3);
		display();
		break;
	case 1000:
		exit(1);
	default:
		exit(0);
		break;
	}
}

void timer(int t)
{
	glutTimerFunc(1, timer, t + 1);
	display();
}

void myReshape(int w, int h)
{
	glViewport(0, 0, w, h);

}
void spinCube()
{
	theta[axis] += 0.2;
	if (theta[axis] > 360.0) theta[axis] -= 360.0;
	display();
}

void mykey(unsigned char key,
	int x, int y)
{
	if (key == '+')
	{
		if (xyz == 1)
		{
			glTranslatef(0.3, 0, 0);
			display();
		}
		if (xyz == 2)
		{
			glTranslatef(0, 0.3, 0);
			display();
		}
		if (xyz == 3)
		{
			glTranslatef(0, 0, 0.3);
			display();
		}
	}

	if (key == '-')
	{
		if (xyz == 1)
		{
			glTranslatef(-0.3, 0, 0);
			display();
		}
		if (xyz == 2)
		{
			glTranslatef(0, -0.3, 0);
			display();
		}
		if (xyz == 3)
		{
			glTranslatef(0, 0, -0.3);
			display();
		}
	}

}
int main(int argc, char **argv) {

	n = 2; //切割數量，數字越大 切割得越細
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutCreateWindow("2D Gasket");
	glutReshapeFunc(reshape);

	//建立popup menu 

	/*int menu;
	menu = glutCreateMenu(processMenuEvents);*/

	color = glutCreateMenu(processMenuEvents);
	glutAddMenuEntry("Red", 0);
	glutAddMenuEntry("Green", 1);
	glutAddMenuEntry("Blue", 2);
	glutAddMenuEntry("Black", 'd');
	glutCreateMenu(processMenuEvents);

	N = glutCreateMenu(processMenuEvents);
	glutAddMenuEntry("n=2", 8);
	glutAddMenuEntry("n=3", 3);
	glutAddMenuEntry("n=4", 4);
	glutAddMenuEntry("n=5", 5);
	glutAddMenuEntry("n=6", 6);
	glutAddMenuEntry("n=7", 7);
	glutCreateMenu(processMenuEvents);




	rotate = glutCreateMenu(processMenuEvents);
	glutAddMenuEntry("axis x", 9);
	glutAddMenuEntry("axis y", 10);
	glutAddMenuEntry("axis z", 11);
	glutAddMenuEntry("stop", 12);
	glutCreateMenu(processMenuEvents);

	transform = glutCreateMenu(processMenuEvents);
	glutAddMenuEntry("x", 13);
	glutAddMenuEntry("y", 14);
	glutAddMenuEntry("z", 15);
	glutCreateMenu(processMenuEvents);

	glutAddSubMenu("Color", color);
	glutAddSubMenu("N", N);
	glutAddSubMenu("Rotate", rotate);
	glutAddSubMenu("Transform", transform);


	glutAddMenuEntry("Exit", 1000);
	//點擊右鍵會pop出 menu

	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutIdleFunc(spinCube);
	glutDisplayFunc(display);

	myinit();

	glutKeyboardFunc(mykey);

	glutMainLoop();

}