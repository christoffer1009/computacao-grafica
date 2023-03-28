// INCLUDES BASEADOS NO LINUX
#include <GL/glut.h>

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

	//RETAS

	int p1[] = { 20,30 };// {x, y}
	int p2[] = { 40,20 };
	int p3[] = { 50,40 };
	int p4[] = { 60,20 };
	int p5[] = { 80,30 };

	// GL_LINES plotará linhas ligando pares de pontos. Como tem uma quantidade ímpar, o último ponto será
	// ignorado,
    //glVertex2iv recebe sempre um vetor de int
	/*glBegin(GL_LINES);
		glVertex2iv(p1);// liga de p1 a p2
		glVertex2iv(p2);
		glVertex2iv(p3);// liga de p3 a p4
		glVertex2iv(p4);
		glVertex2iv(p5);// ignorado
	glEnd();*/


	// GL_LINE_STRIP  ligará os cinco pontos P1->P2, P2->P3... até P4->P5, mas não faz P5->P1!
	/*glBegin(GL_LINE_STRIP);//desenha seguindo os pontos na ordem
		glVertex2iv(p1);
		glVertex2iv(p2);
		glVertex2iv(p3);
		glVertex2iv(p4);
		glVertex2iv(p5);
	glEnd();*/

	// GL_LINE_LOOP  ligará os cinco pontos P1->P2, P2->P3... até P4->P5, e fará P5->P1!
	glBegin(GL_LINE_LOOP);
		glVertex2iv(p1);
		glVertex2iv(p2);
		glVertex2iv(p3);
		glVertex2iv(p4);
		glVertex2iv(p5);
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

