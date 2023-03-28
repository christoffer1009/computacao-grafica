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

void point(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 0, 0);
	
	//EXERCICIO 03
    int p1[] = {100, 75};//centro
    int tamanho = 80;//tamanho do raio
    int n_raios = 12;//qtd de  raios
    double angulo = 6.28 / n_raios;//angulo em rad

    //desenha uma reta a partir do centro, variando o angulo de acordo com o n_raios
    for (int i = 1; i <= n_raios; i++) {
        glBegin(GL_LINES);
            glVertex2iv(p1);
            glVertex2i(p1[0] + tamanho * cos(i * angulo), p1[1] + tamanho * sin(i * angulo));
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
