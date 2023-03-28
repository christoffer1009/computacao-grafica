#include <iostream>
#include <GL/freeglut.h>
//#include <GL/glut.h>

void init(void) {
	glClearColor(1.0, 1.0, 1.0, 0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 200, 0, 150);
}

void point(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 0, 0);
	
	//EXERCICIO 01
	int p1[] = {0, 0};//inferior esquerdo
	int p2[] = {100, 0};
	int p3[] = {200, 0};
	int p4[] = {200, 75};
	int p5[] = {200, 150};
	int p6[] = {100, 150};
	int p7[] = {0, 150};
	int p8[] = {0, 75};

	glBegin(GL_LINES);
		glVertex2iv(p1);
		glVertex2iv(p5);
		glVertex2iv(p3);
		glVertex2iv(p7);
		glVertex2iv(p2);
		glVertex2iv(p6);
		glVertex2iv(p4);
		glVertex2iv(p8);
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
