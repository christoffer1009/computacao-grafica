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

    // EXERCICIO 14
    //  Desenha a face do cubo vermelho
    glColor3f(1, 0, 0);
    glRecti(110, 10, 10, 110);
    // Desenha a lateral azul
    glColor3f(0, 0, 1);
    glBegin(GL_POLYGON);
    glVertex2i(110, 10);
    glVertex2i(150, 50);
    glVertex2i(150, 150);
    glVertex2i(110, 110);
    glEnd();
    // Desenha o topo amarelo
    glColor3f(1, 1, 0);
    glBegin(GL_POLYGON);
    glVertex2i(110, 110);
    glVertex2i(150, 150);
    glVertex2i(50, 150);
    glVertex2i(10, 110);
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
