#include <iostream>
#include <GL/freeglut.h>
//#include <GL/glut.h>
#include<math.h>


void init(void) {
	glClearColor(1.0, 1.0, 1.0, 0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 800, 0, 600);
}

void point(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 0, 0);
	
	glBegin(GL_TRIANGLES);
		glVertex2f(70, 50);  // Pto inferior esquerdo
		glVertex2f(70+ 60/2, sqrt(pow(60, 2) - pow(60 / 2, 2)) + 50);
		glVertex2f(70+60, 50);
	glEnd();

	float x = 100;
	float y = 100;
	float d = 150;
	glBegin(GL_TRIANGLES);
		glVertex2f(x, y);  // Pto inferior esquerdo
		glVertex2f(x + d / 2, sqrt(pow(d, 2) - pow(d / 2, 2)) + y);
		glVertex2f(x + d, y);
	glEnd();
	
	glFlush();
}

int main(int argc, char ** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(1280, 720);
	glutCreateWindow("Computação Gráfica");
	init();
	glutDisplayFunc(point);
	glutMainLoop();

	return 0;
}
