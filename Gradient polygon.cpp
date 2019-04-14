#include<GL\glut.h>
#include<iostream>
using namespace std;

void mydispFun() // �T�w�e�X�@�� �h��� function.

{
	glClear(GL_COLOR_BUFFER_BIT); //�M�� buffer
	glBegin(GL_POLYGON); // �}�lGL �R�O, �e�h���.
	
	glColor3f(1.0, 0.0, 0.0);
	//glColor3f(1.5, 6.7, 0.4);
	glVertex3f(0.0, 0.0, 0.0); // �P�W�� GL_POLYGON ���� �����I�w�q.
	
	glColor3f(0.0, 1.0, 0.0);
	//glColor3f(5.5, 6.5, 2.5);
	glVertex3f(0.3, 0.0, 0.0); // 


	glColor3f(0.0, 0.0, 1.0);
	//glColor3f(5.5, 2.5, 0.4);
	glVertex3f(0.4, 0.4, 0.0);

	glColor3f(1.0, 1.0, 0.0);
	//glColor3f(5.5, 6.5, 4.4);
	glVertex3f(0.0, 0.5, 0.0);
	glEnd(); // ���� GL begin
	glFlush(); // update ���G.
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);// �ϥ�single buffer , �p��double buffer, �B�אּ GLUT_DOUBLE, glFlush() �אּglutSwapBuffers()
	glutInitWindowSize(640, 480);        // �]�wopen GL windows size
	glutInitWindowPosition(100, 100);  // �N�����I�]�� [100,100] ���y�ФW
	glutCreateWindow("Hello world!!!"); // ��GL window ���W�r, �P�ɶ}��
	glutDisplayFunc(mydispFun); // �]�wdisplay function. �u�n windows �n���e, �N�|call �o��fuction
	glutMainLoop();
	system("PAUSE");
	return 0;
}