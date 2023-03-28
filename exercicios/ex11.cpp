#include <iostream>
#include <GL/freeglut.h>
// #include <GL/glut.h>
#include <math.h>

void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-20, 20, -20, 20);
}

void point(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 0, 0);

    // EXERCICIO 11

    GLint k;
    int n = 6; // numero de lados
    double theta = (6.2831853 / n);
    float r, g, b;
    for (int p = 1; p < 18; p = p + 2)
    {
        r = (double)rand() / (double)RAND_MAX;
        g = (double)rand() / (double)RAND_MAX;
        b = (double)rand() / (double)RAND_MAX;
        glColor3f(r, g, b);
        glBegin(GL_LINE_LOOP);
        for (k = 0; k < n; k++)
        {

            glVertex2f(p * cos(theta * k), p * sin(theta * k));
        }
        glEnd();
    };

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
    glutDisplayFunc(point);
    glutMainLoop();

    return 0;
}
