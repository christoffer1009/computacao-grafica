// INCLUDES BASEADOS NO LINUX
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

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

	// PONTOS

	//tamanho do ponto
	glPointSize(10.0f);

    //desenha ponto com base em coordenadas x e y
	glBegin(GL_POINTS);
		glVertex2f(10, 10);
		glVertex2f(20, 20);
		glVertex2f(30, 30);
		glVertex2f(1270, 710);// fora da tela
		glVertex2f(620, 350);//fora da tela
	glEnd();

    //desenha ponto com base em vetor de coordenadas {x,y}
	/*int p1[] = { 20,30 };
	int p2[] = { 40,20 };
	int p3[] = { 50,40 };
	int p4[] = { 60,20 };
	int p5[] = { 80,30 };*/

	// Observe que o sufixo "iv" indica que o argumento será um vetor de inteiros.
	/*glBegin(GL_POINTS);
		glVertex2iv(p1);
		glVertex2iv(p2);
		glVertex2iv(p3);
		glVertex2iv(p4);
		glVertex2iv(p5);
	glEnd();*/


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

