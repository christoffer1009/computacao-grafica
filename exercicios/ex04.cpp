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
	
	//EXERCICIO 04
    //retas iniciais aleatórias
    int x1 = rand() % 200 + 1;
	int y1 = rand() % 150 + 1;
	int x2 = rand() % 200 + 1;
	int y2 = rand() % 150 + 1;

    //cores aleatórias
	double r = (double) rand() / RAND_MAX;
	double g = (double) rand() / RAND_MAX;
	double b = (double) rand() / RAND_MAX;

    //1000 retas
	for (int i = 0; i < 1000; i++)
	{
		//retas aleatórias
		x1 = rand() % 200 + 1;
		y1 = rand() % 150 + 1;
		x2 = rand() % 200 + 1;
		y2 = rand() % 150 + 1;
        //cores aleatórias
		r = (double)rand() / RAND_MAX;
		g = (double)rand() / RAND_MAX;
		b = (double)rand() / RAND_MAX;

        /*
		std::cout << x1 << ',' << y1 << std::endl;
		std::cout << x2 << ',' << y2 << std::endl;
		std::cout << r << ',' << g << ',' << b << std::endl;
        */

		glColor3f(r, g, b);
		glBegin(GL_LINES);
            glVertex2i(x1, y1);
            glVertex2i(x2, y2);
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
