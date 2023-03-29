#include <iostream>
#include <GL/freeglut.h>
// #include <GL/glut.h>
#include <math.h>

void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 200, 0, 200);
}

void point(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 0, 0);

    // QUESTÃO 01
    float x = 50;
    float y = 70;
    float d = 100;
    glBegin(GL_TRIANGLES);
    glVertex2f(x, y); // Pto inferior esquerdo
    glVertex2f(x + d / 2, sqrt(pow(d, 2) - pow(d / 2, 2)) + y);
    glVertex2f(x + d, y);
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
    glutDisplayFunc(point);
    glutMainLoop();

    return 0;
}
