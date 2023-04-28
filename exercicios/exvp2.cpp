#include <iostream>
#include <stdio.h>
#include <GL/glut.h>

void init(void)
{
	glClearColor(1, 1, 1, 0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-250, 250, -250, 250);
}

void midpoint(int n1, int n2, int n3)
{
	int raio = 100;
	int xcentro = 0;
	int ycentro = 0;
	int x = xcentro;
	int y = ycentro + raio;
	int p = 1 - raio;

	for (size_t k = 0; k < y; k++)
	{
		std::cout << "k: " << k << "x: " << x << "y: " << y << "\n";
		x += 1;
		if (p < 0)
		{
			p += 2 * x + 1;
		}
		else
		{
			y -= 1;
			p += (2 * x + 1) - (2 * y);
		}

		switch (n1)
		{
		case 1:
			glVertex2i(x, y); // 1
			break;
		case 2:
			glVertex2i(y, x); // 2
			break;
		case 3:
			glVertex2i(y, -x); // 3
			break;
		case 4:
			glVertex2i(x, -y); // 4
			break;
		case 5:
			glVertex2i(-x, -y); // 5
			break;
		case 6:
			glVertex2i(-y, -x); // 6
			break;
		case 7:
			glVertex2i(-y, x); // 7
			break;
		case 8:
			glVertex2i(-x, y); // 8
			break;
		default:
			glVertex2i(0, 0); // erro
		}

		switch (n2)
		{
		case 1:
			glVertex2i(x, y); // 1
			break;
		case 2:
			glVertex2i(y, x); // 2
			break;
		case 3:
			glVertex2i(y, -x); // 3
			break;
		case 4:
			glVertex2i(x, -y); // 4
			break;
		case 5:
			glVertex2i(-x, -y); // 5
			break;
		case 6:
			glVertex2i(-y, -x); // 6
			break;
		case 7:
			glVertex2i(-y, x); // 7
			break;
		case 8:
			glVertex2i(-x, y); // 8
			break;
		default:
			glVertex2i(0, 0); // erro
		}

		switch (n3)
		{
		case 1:
			glVertex2i(x, y); // 1
			break;
		case 2:
			glVertex2i(y, x); // 2
			break;
		case 3:
			glVertex2i(y, -x); // 3
			break;
		case 4:
			glVertex2i(x, -y); // 4
			break;
		case 5:
			glVertex2i(-x, -y); // 5
			break;
		case 6:
			glVertex2i(-y, -x); // 6
			break;
		case 7:
			glVertex2i(-y, x); // 7
			break;
		case 8:
			glVertex2i(-x, y); // 8
			break;
		default:
			glVertex2i(0, 0); // erro
		}
	}
}

void lineSegment(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 0, 0);
	glPointSize(5);

	glBegin(GL_POINTS);
	midpoint(1, 5, 7);
	glEnd();

	glFlush();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Traabalho VP2 - Midpoint circle");
	init();
	glutDisplayFunc(lineSegment);
	glutMainLoop();

	return 0;
}