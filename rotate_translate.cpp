#include <iostream>
#include <stdio.h>
#include <GL/glut.h>

using namespace std;
int a, OffsetX = 0, OffsetY = 0;
float R = 0, G = 0, B = 1;
GLint V = 50, Ang = 0;
GLint DesLoca = -100;
int tam = 50;
void init(void) {
	glClearColor(1.0, 1.0, 1.0, 0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-400, 400, -400, 400);
}


void lineSegment(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glColor3f(R, G, B);
	
	//Traça eixos X e Y
	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2i(0, -400);
	glVertex2i(0, 400);
	glVertex2i(-400, 0);
	glVertex2i(400, 0);
	glEnd();

	// EXEMPLO 3: MOSTRA UM RETÂNGULO CIRCULANDO. ACELERA E DESACELERA COM
	// SETAS DO TECLADO
	//
	glColor3f(R, G, B);
	glLoadIdentity(); // Reset current matrix to identity.
	glTranslatef(OffsetX, OffsetY, 0);
	glRotatef(Ang, 0.0, 0.0, 1.0);
	
	glRecti(0, 0, tam, tam); // Mostra retangulo azul*/
	
	glFlush();
}

void Teclado(unsigned char key, int x, int y)
{
	if (key == 27) {
		exit(0);
	};
	if (key == 13) {
		tam = 50;
		V = 50;
		Ang = 1;
	};
	if (key == 97) {
		OffsetX = OffsetX - 10;
		cout << OffsetX<<"\n";
		glutPostRedisplay();
	};
	if (key == 100) {
		OffsetX = OffsetX + 10;
		cout << OffsetX << "\n";
		glutPostRedisplay();
	};
	if (key == 119) {
		OffsetY = OffsetY + 10;
		cout << OffsetY << "\n";
		glutPostRedisplay();
	};
	if (key == 115) {
		OffsetY = OffsetY - 10;
		cout << OffsetY << "\n";
		glutPostRedisplay();
	};


};

void Anima(int value);

void specialKey(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_UP:
		V = V + 10;
		break;
	case GLUT_KEY_DOWN:
		V = V - 10;
		if (V <= 0) { V = 1; };
		break;

	case GLUT_KEY_RIGHT:
		tam = tam + 10;
		break;
	case GLUT_KEY_LEFT:
		tam = tam - 10;
		break;

	};
	cout << V << endl;
};

void mouseFunc(int button, int state, int x, int y) {
	//cout << x << endl;
	//cout << y << endl;
	srand(time(NULL));
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		B = (double)rand() / (double)RAND_MAX;
		R = (double)rand() / (double)RAND_MAX;
		G = (double)rand() / (double)RAND_MAX;
		glutPostRedisplay();
	};
}

void Anima(int value)
{
	
	Ang = Ang + 10;
	if (Ang == 360) { Ang = 0; }
	glutPostRedisplay();
	//cout << tam << endl;
	B = (double)rand() / (double)RAND_MAX;
	R = (double)rand() / (double)RAND_MAX;
	G = (double)rand() / (double)RAND_MAX;
	glutTimerFunc(V, Anima, 1);

}


// Programa Principal 
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(1000, 1000);
	glutCreateWindow("Acelera/Desacelera Movimentação");
	init();
	glutDisplayFunc(lineSegment);
	glutTimerFunc(V, Anima, 1);
	glutKeyboardFunc(Teclado);
	glutSpecialFunc(specialKey);
	glutMouseFunc(mouseFunc);
	glutMainLoop();

	return 0;

}