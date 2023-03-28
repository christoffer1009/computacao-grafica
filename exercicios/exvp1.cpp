#include <iostream>
#include <GL/freeglut.h>
// #include <GL/glut.h>
#include <math.h>

void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);
}

void desenha(int cx, int cy, int d)
{
    int s, r;

    s = d * (sqrt(2) / 2);
    r = d * (sqrt(2) / 2);

    glBegin(GL_POLYGON);
    glVertex2f(cx + r, cy + s);
    glVertex2f(cx, cy + d);
    glVertex2f(cx - r, cy + s);
    glVertex2f(cx - d, cy);
    glVertex2f(cx - r, cy - s);
    glVertex2f(cx, cy - d);
    glVertex2f(cx + r, cy - r);
    glVertex2f(cx + d, cy);
    glEnd();
}

void point(void)
{   

    //EXERCÍCIO VP1
    
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    srand(time(NULL));

    float re, gr, bl;
    re = (double)rand() / (double)RAND_MAX;
    gr = (double)rand() / (double)RAND_MAX;
    bl = (double)rand() / (double)RAND_MAX;
    int cx, cy, d;

    for (int i = 0; i < 50; i++)
    {

        re = ((double)rand() / (double)RAND_MAX);
        gr = ((double)rand() / (double)RAND_MAX);
        bl = ((double)rand() / (double)RAND_MAX);
        glColor3f(re, gr, bl);

        cx = ((double)rand() / (double)RAND_MAX) * 500;
        cy = ((double)rand() / (double)RAND_MAX) * 500;
        d = ((double)rand() / (double)RAND_MAX) * 50;
        desenha(cx, cy, d);
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
