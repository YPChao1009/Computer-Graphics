#include<GL\glut.h>
#include<windows.h>
#include <iostream>
using namespace std;

GLfloat no_mat[] = { 1.0, 1.0, 0.0, 1.0 };
GLfloat mat_ambient[] = { 1.0, 0.5, 1.0, 1.0 };
GLfloat mat_ambient_color[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat mat_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat mat_specular[] = { 0.0, 0.6, 0.5, 1.0 };
GLfloat no_shininess[] = { 0.1 };
GLfloat low_shininess[] = { 5.0 };
GLfloat high_shininess[] = { 100.0 };
GLfloat mat_emission[] = { 0.3, 0.2, 0.2, 0.0 };
static int angle = 0, neck = 0, lshoulder = -5, lelbow = -10, rshoulder = 5, relbow = 10,
lhips = 5, rhips = -5, lfoot = 10, rfoot = -10, flagneck = 0, flaglshoulder = 0,
flaglelbow = 0, flagrshoulder = 0, flagrelbow = 0, flaglhips = 0,
flagrhips = 0, flaglfoot = 0, flagrfoot = 0;

void init(void)
{
	GLfloat ambient[] = { 0.0, 0.0, 0.0, 1.0 };     // 0.0, 0.0, 0.0, 1.0
	GLfloat diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat position[] = { 0.0, 5.0, 10.0, 0.0 };
	GLfloat lmodel_ambient[] = { 0.4, 0.4, 0.4, 1.0 };
	GLfloat local_view[] = { 0.0 };

	glClearColor(0, 0, 0, 0);

	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_POSITION, position);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
	glLightModelfv(GL_LIGHT_MODEL_LOCAL_VIEWER, local_view);

	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
}

void draw_body(void)
{
	glPushMatrix();
	glTranslatef(0, 1.5, 0);
	glScalef(0.5, 1, 0.4);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_color);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
	glutSolidCube(4); ;
	glPopMatrix();
}

void draw_leftshoulder(void)
{
	glPushMatrix();
	/*glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
	glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);*/
	glTranslatef(1.5, 3, 0);
	glRotatef(lshoulder, 1, 0, 0);

	glTranslatef(0, -0.5, 0);
	glScalef(0.4, 1, 0.5);
	glutSolidCube(2);

	glScalef(1 / 0.4, 1 / 1, 1 / 0.5);
	glTranslatef(0, -1.4, 0);
	glRotatef(lelbow, 1, 0, 0);
	glutWireSphere(0.4, 200, 500);

	glScalef(0.4, 1, 0.5);
	glTranslatef(0, -1.4, 0);
	glutSolidCube(2);

	glPopMatrix();
}

void draw_rightshoulder(void)
{
	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
	glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
	glTranslatef(-1.5, 3, 0);
	glRotatef(rshoulder, 1, 0, 0);

	glTranslatef(0, -0.5, 0);
	glScalef(0.4, 1, 0.5);
	glutSolidCube(2);

	glScalef(1 / 0.4, 1 / 1, 1 / 0.5);
	glTranslatef(0, -1.4, 0);
	glRotatef(relbow, 1, 0, 0);
	glutWireSphere(0.4, 200, 500);

	glScalef(0.4, 1, 0.5);
	glTranslatef(0, -1.4, 0);
	glutSolidCube(2);

	glPopMatrix();
}

void draw_head(void)
{
	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);

	glTranslatef(0, 3.5, 0);
	glRotatef(neck, 0, 0, 1);
	glTranslatef(0, 1, 0);
	glutWireSphere(1, 200, 500);

	glPopMatrix();
}

void draw_leye(void)
{
	glPushMatrix();
	/*glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);*/
	glColor3f(0, 0, 0);
	//glTranslatef(-0.3,4.5,1);
	glTranslatef(-0.2, 4, 0.5);
	glRotatef(neck, 0, 0, 1);
	glTranslatef(-0.2, 0.5, 0.5);
	//glRotatef(neck,0,0,1);
	//glTranslatef(0,1,0);
	glutWireSphere(0.2, 100, 300);

	glPopMatrix();
}

void draw_reye(void)
{
	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);

	glTranslatef(0.2, 4, 0.5);
	glRotatef(neck, 0, 0, 1);
	glTranslatef(0.2, 0.5, 0.5);
	glutWireSphere(0.2, 100, 300);

	glPopMatrix();
}

void draw_mouth(void)
{
	glPushMatrix();
	glColor3f(1, 0, 0);
	//glTranslatef(0,4,1);
	glTranslatef(0, 3.5, 0.5);
	glRotatef(neck, 0, 0, 1);
	glTranslatef(0, 0.5, 0.5);
	glScalef(0.6, 0.4, 0.4);
	//glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_color);
	//glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	//glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	//glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
	//glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
	glutSolidCube(0.6);
	glPopMatrix();
}
void draw_leftfoot(void)
{
	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
	glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);

	glTranslatef(-0.6, -0.6, 0);
	glRotatef(lfoot, 1, 0, 0);
	glTranslatef(0, -1, 0);
	glScalef(0.4, 1, 0.5);
	glutSolidCube(2);

	glScalef(1 / 0.4, 1 / 1, 1 / 0.5);
	glTranslatef(0, -1.4, 0);
	glRotatef(lhips, 1, 0, 0);
	glutWireSphere(0.4, 200, 500);

	glScalef(0.4, 1, 0.5);
	glTranslatef(0, -1.4, 0);
	glutSolidCube(2);

	glPopMatrix();
}

void draw_rightfoot(void)
{
	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
	glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);

	glTranslatef(0.6, -0.6, 0);
	glRotatef(rfoot, 1, 0, 0);
	glTranslatef(0, -1, 0);
	glScalef(0.4, 1, 0.5);
	glutSolidCube(2);

	glScalef(1 / 0.4, 1 / 1, 1 / 0.5);
	glTranslatef(0, -1.4, 0);
	glRotatef(rhips, 1, 0, 0);
	glutWireSphere(0.4, 200, 500);

	glScalef(0.4, 1, 0.5);
	glTranslatef(0, -1.4, 0);
	glutSolidCube(2);

	glPopMatrix();
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();

	glRotatef(angle, 0, 1, 0);

	glTranslatef(0, 4, 0);
	draw_body();
	draw_leye();
	draw_reye();
	draw_mouth();
	draw_head();

	draw_leftshoulder();
	draw_rightshoulder();

	draw_leftfoot();
	draw_rightfoot();

	glPopMatrix();
	glutSwapBuffers();
}

void reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(74.0f, (GLfloat)w / (GLfloat)h, 1.0f, 1000.0f);
	//glOrtho(-8,8,-8,8,-10,10);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 4.0, 10, 0.0, 4, 0.0, 0.0, 1.0, 0.0);
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
		//top
	case 'W':
		//flagrfoot+=5;
		glTranslatef(0.0f, 0.1f, 0.0f);
		glutPostRedisplay();
		break;
		//left
	case 'A':
		glTranslatef(-0.1f, -0.0f, 0.0f);
		if (flaglshoulder)
		{
			lshoulder += 5;
			if (lshoulder >= 60)flaglshoulder = 0;
		}
		else
		{
			lshoulder -= 5;
			if (lshoulder <= -60)flaglshoulder = 1;
		}
		if (flagrshoulder)
		{
			rshoulder -= 5;
			if (rshoulder <= -60)flagrshoulder = 0;
		}
		else
		{
			rshoulder += 5;
			if (rshoulder >= 60)flagrshoulder = 1;
		}

		if (flaglfoot)
		{
			lfoot += 5;
			if (lfoot >= 60)flaglfoot = 0;
		}
		else
		{
			lfoot -= 5;
			if (lfoot <= -60)flaglfoot = 1;
		}
		if (flagrfoot)
		{
			rfoot -= 5;
			if (rfoot <= -60)flagrfoot = 0;
		}
		else
		{
			rfoot += 5;
			if (rfoot >= 60)flagrfoot = 1;
		}

		glutPostRedisplay();
		break;
		//bottom
	case 'S':
		glTranslatef(0.0f, -0.1f, 0.0f);
		glutPostRedisplay();
		break;
		//right
	case 'D':
		glTranslatef(0.1f, 0.0f, 0.0f);
		if (flaglshoulder)
		{
			lshoulder += 5;
			if (lshoulder >= 60)flaglshoulder = 0;
		}
		else
		{
			lshoulder -= 5;
			if (lshoulder <= -60)flaglshoulder = 1;
		}
		if (flagrshoulder)
		{
			rshoulder -= 5;
			if (rshoulder <= -60)flagrshoulder = 0;
		}
		else
		{
			rshoulder += 5;
			if (rshoulder >= 60)flagrshoulder = 1;
		}

		if (flaglfoot)
		{
			lfoot += 5;
			if (lfoot >= 60)flaglfoot = 0;
		}
		else
		{
			lfoot -= 5;
			if (lfoot <= -60)flaglfoot = 1;
		}
		if (flagrfoot)
		{
			rfoot -= 5;
			if (rfoot <= -60)flagrfoot = 0;
		}
		else
		{
			rfoot += 5;
			if (rfoot >= 60)flagrfoot = 1;
		}
		glutPostRedisplay();
		break;
		//inner
	case 'Q':
		glTranslatef(0.0f, 0.0f, -0.1f);
		if (flaglshoulder)
		{
			lshoulder += 5;
			if (lshoulder >= 60)flaglshoulder = 0;
		}
		else
		{
			lshoulder -= 5;
			if (lshoulder <= -60)flaglshoulder = 1;
		}
		if (flagrshoulder)
		{
			rshoulder -= 5;
			if (rshoulder <= -60)flagrshoulder = 0;
		}
		else
		{
			rshoulder += 5;
			if (rshoulder >= 60)flagrshoulder = 1;
		}

		if (flaglfoot)
		{
			lfoot += 5;
			if (lfoot >= 60)flaglfoot = 0;
		}
		else
		{
			lfoot -= 5;
			if (lfoot <= -60)flaglfoot = 1;
		}
		if (flagrfoot)
		{
			rfoot -= 5;
			if (rfoot <= -60)flagrfoot = 0;
		}
		else
		{
			rfoot += 5;
			if (rfoot >= 60)flagrfoot = 1;
		}
		glutPostRedisplay();

		break;
		//outter
	case 'E':
		glTranslatef(0.0f, 0.0f, 0.1f);
		if (flaglshoulder)
		{
			lshoulder += 5;
			if (lshoulder >= 60)flaglshoulder = 0;
		}
		else
		{
			lshoulder -= 5;
			if (lshoulder <= -60)flaglshoulder = 1;
		}
		if (flagrshoulder)
		{
			rshoulder -= 5;
			if (rshoulder <= -60)flagrshoulder = 0;
		}
		else
		{
			rshoulder += 5;
			if (rshoulder >= 60)flagrshoulder = 1;
		}
		if (flaglfoot)
		{
			lfoot += 5;
			if (lfoot >= 60)flaglfoot = 0;
		}
		else
		{
			lfoot -= 5;
			if (lfoot <= -60)flaglfoot = 1;
		}
		if (flagrfoot)
		{
			rfoot -= 5;
			if (rfoot <= -60)flagrfoot = 0;
		}
		else
		{
			rfoot += 5;
			if (rfoot >= 60)flagrfoot = 1;
		}
		glutPostRedisplay();
		break;

	case '+':
		//flagrfoot+=5;
		glTranslatef(0.0f, 1.0f, 0.0f);
		glutPostRedisplay();
		break;
		//left
	case '/':
		glTranslatef(-1.0f, -0.0f, 0.0f);
		if (flaglshoulder)
		{
			lshoulder += 10;
			if (lshoulder >= 80)flaglshoulder = 0;
		}
		else
		{
			lshoulder -= 10;
			if (lshoulder <= -80)flaglshoulder = 1;
		}
		if (flagrshoulder)
		{
			rshoulder -= 10;
			if (rshoulder <= -80)flagrshoulder = 0;
		}
		else
		{
			rshoulder += 10;
			if (rshoulder >= 80)flagrshoulder = 1;
		}

		if (flaglfoot)
		{
			lfoot += 10;
			if (lfoot >= 80)flaglfoot = 0;
		}
		else
		{
			lfoot -= 10;
			if (lfoot <= -80)flaglfoot = 1;
		}
		if (flagrfoot)
		{
			rfoot -= 10;
			if (rfoot <= -80)flagrfoot = 0;
		}
		else
		{
			rfoot += 10;
			if (rfoot >= 80)flagrfoot = 1;
		}

		glutPostRedisplay();
		break;
		//bottom
	case '-':
		glTranslatef(0.0f, -1.0f, 0.0f);
		glutPostRedisplay();
		break;
		//right
	case '*':
		glTranslatef(1.0f, 0.0f, 0.0f);
		if (flaglshoulder)
		{
			lshoulder += 10;
			if (lshoulder >= 80)flaglshoulder = 0;
		}
		else
		{
			lshoulder -= 10;
			if (lshoulder <= -80)flaglshoulder = 1;
		}
		if (flagrshoulder)
		{
			rshoulder -= 10;
			if (rshoulder <= -80)flagrshoulder = 0;
		}
		else
		{
			rshoulder += 10;
			if (rshoulder >= 80)flagrshoulder = 1;
		}

		if (flaglfoot)
		{
			lfoot += 10;
			if (lfoot >= 80)flaglfoot = 0;
		}
		else
		{
			lfoot -= 10;
			if (lfoot <= -80)flaglfoot = 1;
		}
		if (flagrfoot)
		{
			rfoot -= 10;
			if (rfoot <= -80)flagrfoot = 0;
		}
		else
		{
			rfoot += 10;
			if (rfoot >= 80)flagrfoot = 1;
		}
		glutPostRedisplay();
		break;
		//inner






	case '1':
		angle = (angle + 5) % 360;
		glutPostRedisplay();
		break;
	case '2':
		angle = (angle - 5) % 360;
		glutPostRedisplay();
		break;
	case '3':
		if (flagneck)
		{
			neck = neck + 5;
			if (neck >= 30)flagneck = 0;
		}
		else {
			neck = neck - 5;
			if (neck <= -30)flagneck = 1;
		}
		glutPostRedisplay();
		break;
	case 'Y':
		if (flaglshoulder)
		{
			lshoulder += 5;
			if (lshoulder >= 60)flaglshoulder = 0;
		}
		else
		{
			lshoulder -= 5;
			if (lshoulder <= -60)flaglshoulder = 1;
		}
		glutPostRedisplay();
		break;
	case 'U':
		if (flagrshoulder)
		{
			rshoulder += 5;
			if (rshoulder >= 60)flagrshoulder = 0;
		}
		else
		{
			rshoulder -= 5;
			if (rshoulder <= -60)flagrshoulder = 1;
		}
		glutPostRedisplay();
		break;
	case 'I':
		if (flaglelbow)
		{
			lelbow += 5;
			if (lelbow >= 60)flaglelbow = 0;
		}
		else
		{
			lelbow -= 5;
			if (lelbow <= -60)flaglelbow = 1;
		}
		glutPostRedisplay();
		break;
	case 'O':
		if (flagrelbow)
		{
			relbow += 5;
			if (relbow >= 60)flagrelbow = 0;
		}
		else
		{
			relbow -= 5;
			if (relbow <= -60)flagrelbow = 1;
		}
		glutPostRedisplay();
		break;

	case 'H':
		if (flagrfoot)
		{
			rfoot += 5;
			if (rfoot >= 60)flagrfoot = 0;
		}
		else
		{
			rfoot -= 5;
			if (rfoot <= -60)flagrfoot = 1;
		}
		glutPostRedisplay();
		break;
	case 'J':
		if (flaglfoot)
		{
			lfoot += 5;
			if (lfoot >= 60)flaglfoot = 0;
		}
		else
		{
			lfoot -= 5;
			if (lfoot <= -60)flaglfoot = 1;
		}
		glutPostRedisplay();
		break;
	case 'K':
		if (flagrhips)
		{
			rhips += 5;
			if (rhips >= 60)flagrhips = 0;
		}
		else
		{
			rhips -= 5;
			if (rhips <= -60)flagrhips = 1;
		}
		glutPostRedisplay();
		break;
	case 'L':
		if (flaglhips)
		{
			lhips += 5;
			if (lhips >= 60)flaglhips = 0;
		}
		else
		{
			lhips -= 5;
			if (lhips <= -60)flaglhips = 1;
		}
		glutPostRedisplay();
		break;
		glutPostRedisplay();
		break;
	default:
		break;
	}
}


int main(int argc, char** argv)
{
	printf("按鍵 'W','A','S','D'為向上,向下,向左,向右\n");
	printf("按鍵 'Q','E'為向前,向後\n");
	printf("按鍵 '/','*'為快速向左,快速向右\n");
	printf("按鍵 '1','2'為整體旋轉\n");
	printf("按鍵 '3'為頭部旋轉\n");
	printf("按鍵 'Y','U'為手臂旋轉(左,右)\n");
	printf("按鍵 'I','O'為前臂旋轉(左,右)\n");
	printf("按鍵 'H','J'為腿部旋轉(左,右)\n");
	printf("按鍵 'K','L'為小腿旋轉(左,右)\n");
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RED);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}
