#include<GL\glut.h>
#include<iostream>
using namespace std;

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

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);// 使用single buffer , 如用double buffer, 且改為 GLUT_DOUBLE, glFlush() 改為glutSwapBuffers()
	glutInitWindowSize(640, 480);        // 設定open GL windows size
	glutInitWindowPosition(100, 100);  // 將中心點設成 [100,100] 的座標上
	glutCreateWindow("Hello world!!!"); // 給GL window 的名字, 同時開啟
	glutDisplayFunc(mydispFun); // 設定display function. 只要 windows 要重畫, 就會call 這支fuction
	glutMainLoop();
	system("PAUSE");
	return 0;
}