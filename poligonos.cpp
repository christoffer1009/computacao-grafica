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

	//POLÍGONOS

	//glRect* desenha um retângulo com colorido, onde * significa as diversas formas de usar os parâmetros, duas ou três dimensões, inteiros, reais
	//ou vetor, etc. As duas primeiras coordendas correspondem ao canto inferior direito do retângulo
	//enquanto as duas últimas correspondem ao canto superior esquerdo. O retângulo é gerado no sentido horário
	// ou seja, (200,100)->(50,100)->(50,250)->(200,250)->(200,100), fechando a figura.
    //glRecti(200,100,50,250);
	//GL_POLYGON desenha qualquer polígono usando os vértices no sentido anti-horário.

	glBegin(GL_POLYGON);
		glVertex2i(100, 100);
		glVertex2i(100, 130);
		glVertex2i(160, 130);
		glVertex2i(160, 100);
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

