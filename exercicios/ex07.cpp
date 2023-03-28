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
	
    //EXERCICIO 07
	
	srand(time(NULL));
	double r;
	double g;
	double b;

	for (int k = 1; k <= 100; k = k + 10)
	{
		glPointSize(k);
		glBegin(GL_POINTS);
			r = (double)rand() / (double)RAND_MAX;
			g = (double)rand() / (double)RAND_MAX;
			b = (double)rand() / (double)RAND_MAX;
			glColor3f(r, g, b);
			glVertex2i(k, k);
		glEnd();
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
