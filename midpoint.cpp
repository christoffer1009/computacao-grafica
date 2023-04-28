
#include <iostream>
#include <GL/freeglut.h>
// #include <GL/glut.h>

void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-200, 200, -150, 150);
}

void midpoint()
{
    int xCentro = 0;
    int yCentro = 0;
    int raio = 100;
    int p = 1 - raio;
    int x = xCentro, y = yCentro + raio;
    glVertex2i(x, y);

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

        glVertex2i(x, y);
        glVertex2i(y, x);
        glVertex2i(-y, x);
        glVertex2i(-x, y);
        glVertex2i(-x, -y);
        glVertex2i(-y, -x);
        glVertex2i(y, -x);
        glVertex2i(x, -y);
    }
}

void draw(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 0, 0);

    glPointSize(5);
    glBegin(GL_POINTS);
    midpoint();
    glEnd();

    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(1280, 720);
    glutCreateWindow("Computação Gráfica");
    init();
    glutDisplayFunc(draw);
    glutMainLoop();

    return 0;
}
