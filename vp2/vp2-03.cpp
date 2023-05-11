#include <iostream>
#include <GL/freeglut.h>
#include <math.h>

void init(void) {
	glClearColor(1, 1, 1, 0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-400, 400, -400, 400);
}

void lineSegment(void) {
	glClear(GL_COLOR_BUFFER_BIT);

	srand(time(NULL));
	GLint k;
	double theta = (6.2831853 / 180);
	glPointSize(10.0f);
	float r, g, b;
	int tam;
		
	glBegin(GL_LINES);

	for (k = 0; k < 180; k++) {
		r = (double)rand() / (double)RAND_MAX;
		g = (double)rand() / (double)RAND_MAX;
		b = (double)rand() / (double)RAND_MAX;
		tam = ((double)rand() / (double)RAND_MAX) * 200;
		glColor3f(r, g, b);
		glVertex2f(tam * cos(theta * k),tam * sin(theta * k));
		glVertex2f(0,0);

	}
	glEnd();
	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(800, 800 );
	glutCreateWindow("Hello Word!");
	init();
	glutDisplayFunc(lineSegment);
	glutMainLoop();

	return 0;

}