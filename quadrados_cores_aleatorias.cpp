#include <iostream>
#include <GL/freeglut.h>
//#include <GL/glut.h>
#include <time.h>

void init(void) {
	glClearColor(1.0, 1.0, 1.0, 0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 800, 0, 600);
}

float setRandColors(){
	glColor3f( (float)rand() / (float)RAND_MAX, (float)rand() / (float)RAND_MAX, (float)rand() / (float)RAND_MAX);

}

void solution(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	srand(time(0));	
	for(int i=0; i<=10; ++i){
		setRandColors();
		glRecti( i*30, i*30, 30+(i*30)+(i*10), 30+(i*30)+(i*10) );
	}
	glFlush();
}

int main(int argc, char ** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Computação Gráfica");
	init();
	glutDisplayFunc(solution);
	glutMainLoop();

	return 0;
}
