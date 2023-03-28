#include <iostream>
#include <GL/freeglut.h>
// #include <GL/glut.h>

void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 200, 0, 150);
}

void point(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 0, 0);

    // EXERCICIO 02
    int p1[] = {0, 150};
    int p2[] = {200, 150};
    int p3[] = {200, 0};

    for (int i = 0; i < 150; i++)
    {
        glBegin(GL_LINES);
        glVertex2iv(p1);
        glVertex2f(200, i);
        glEnd();
    }

    for (int i = 0; i < 200; i++)
    {
        glBegin(GL_LINES);
        glVertex2iv(p3);
        glVertex2f(i, 150);
        glEnd();
    }

    glBegin(GL_LINES);
    glVertex2iv(p1);
    glVertex2iv(p3);
    glEnd();

    // for (int a = 180; a >= 0; a--)
    // {
    //     glBegin(GL_LINES);
    //     glVertex2i(180, 15);
    //     glVertex2i(a, 145);
    //     glEnd();
    // }

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
