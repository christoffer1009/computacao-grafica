#include <iostream>
#include <GL/freeglut.h>
//#include <GL/glut.h>
#include <math.h>

void init(void) {
	glClearColor(1.0, 1.0, 1.0, 0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 200, 0, 150);
}

void Triangulo(int x, int y, int d) {
	glBegin(GL_LINE_LOOP);
	glVertex2i(x, y);  // Pto inferior esquerdo
	glVertex2i(x + d / 2, sqrt(pow(d, 2) - pow(d / 2, 2)) + y);
	glVertex2i(x + d, y);
	glEnd();
}

void point(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 0, 0);
	
	//EXERCICIO 10
	int x = 40;
	int y = 50;
	int d = 50;

	for (int i = 0; i < 10; i++) {
		Triangulo(x, y, d);
		x = x + 2;
		y = y + 2;
		d = d - 4;
	}
	
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
