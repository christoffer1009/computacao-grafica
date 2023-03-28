// OpenGL.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <stdio.h>
#include <string.h>
//#include<GLFW/glut.h>
#include<time.h>

using namespace std;

int main(int argc, char** argv)
{

	srand(time(NULL));
	float r = (double)rand() / (double)RAND_MAX;
	float g = (double)rand() / (double)RAND_MAX;
	float b = (double)rand() / (double)RAND_MAX;
	cout << "R:" << r << endl;
	cout << "G:" << g << endl;
	cout << "B:" << b << endl;

	return 0;

}