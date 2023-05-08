#include <stdlib.h>
#include <glut.h>
#include <gl/GL.h>
#include <string.h>
#include "Fruit.h"
#include "Snake.h"
#include "Game.h"


void output_text(int x, int y, const char* string);

void timer(int = 0)//cykl glowny tego programu, w ktorym sa elementy zmienne
{
	game.Display();
	glutTimerFunc(200, timer, 0);
}

void Keyboard(int key, int a, int b)
{
	switch (key)
	{
	case 101: game.dir = 0;
		break;
	case 102: game.dir = 2;
		break;
	case 100: game.dir = 1;
		break;
	case 103: game.dir = 3;
		break;
	default:;
	}
}

void Display()
{
	game.Display();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(game.w, game.h);
	glutCreateWindow("Snake");
	glClearColor(1.0, 1.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, game.w, 0, game.h);

	glutDisplayFunc(Display);
	glutTimerFunc(200, timer, 10000);
	glutSpecialFunc(Keyboard);

	glutMainLoop();
}

void output_text(int x, int y, const char* string)
{
	glColor3f(0.3, 0.6, 0.7);
	glRasterPos2f(x, y);
	int i;
	int len = (int)strlen(string);
	for (i = 0; i < len; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
	}
}