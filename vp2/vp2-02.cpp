#include <iostream>
#include <GL/freeglut.h>

void init(void) {
	glClearColor(1, 1, 1, 0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-800, 800, -800, 800);

}


void midpoint()
{   
    int xCentro = 640;
    int yCentro = 340;
    int raio = 20;
    int p = 1 - raio;
    int x = 0, y = raio;
    //glVertex2i(x, y);

    while (x < y)
    {
        x++;
        if (p < 0)
        {
            p = p + 2 * x + 1;
        }
        else
        {
            y -= 1;
            p = p + 2 * x + 1 - 2 * y;
        }

        std::cout << "x " << y+xCentro << " y " << x+yCentro << "\n";

        glVertex2i(y + xCentro, x + yCentro);

        
        //glVertex2i(x, y);
        //glVertex2i(y, x);
        //glVertex2i(-y, x);
        //glVertex2i(-x, y);
        //glVertex2i(-x, -y);
        //glVertex2i(-y, -x);
        //glVertex2i(y, -x);
        //glVertex2i(x, -y);
    }
}

void lineSegment(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 0, 1);
	glPointSize(2);

    glBegin(GL_POINTS);
	midpoint();
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