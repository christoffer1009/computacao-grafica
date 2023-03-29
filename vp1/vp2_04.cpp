#include <iostream>
#include <GL/freeglut.h>
// #include <GL/glut.h>

char entrada;

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

    // QUESTÃO 04
    glRasterPos2i(100, 100);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, entrada);

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
    std::cin >> entrada;
    glutDisplayFunc(point);
    glutMainLoop();

    return 0;
}
