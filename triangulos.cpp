// INCLUDES BASEADOS NO LINUX
#include <GL/glut.h>

#include <iostream>
#include <stdlib.h>
#include <math.h>
// ***************************


void init(void) {
	glClearColor(1.0, 1.0, 1.0, 0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 200, 0, 150);

}

void point(void ) {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 0.4, 0.2);

	//TRIÂNGULOS
    //cada linha é um vértice do triângulo
	/*glBegin(GL_TRIANGLES);
		glVertex2i(100, 120);
		glVertex2i(80, 30);
		glVertex2i(140, 50);
	glEnd();*/

	//São gerados dois triângulos separados
	glBegin(GL_TRIANGLES);
		glVertex2i(100, 120);
		glVertex2i(80, 30);
		glVertex2i(140, 50);
        glColor3f(1.0, 0.4, 0.2);//muda a cor
		glVertex2i(10, 20);
		glVertex2i(80, 30);
		glVertex2i(40, 50);
	glEnd();


	glFlush();
}

// Programa Principal

int main(int argc, char ** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(1280, 720);
	glutCreateWindow("Hello Word!");
	init();
	glutDisplayFunc(point);
	glutMainLoop();

	return 0;
}

