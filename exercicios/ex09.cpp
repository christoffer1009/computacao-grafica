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

    // EXERCICIO 09

    int x1 = 0, y1 = 0, x2 = 25, y2 = 25;
    int change = 1;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            change = change * (-1);

            if (change == -1)
                glColor3f(1.0, 1.0, 1.0);
            else
                glColor3f(0.0, 0.0, 0.0);
            glRecti(x1, y1, x2, y2);

            x1 += 25;
            x2 += 25;
        }
        y1 += 25;
        y2 += 25;
        x1 = 0;
        x2 = 25;
        change = change * (-1); // un comment in case of even no of boxes in a ro
    }

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
