#include "Fruit.h"
#include <glut.h>
#include <gl/GL.h>


Fruits::Fruits(int x, int y, int scale)
	{
		X = rand() % x;
		Y = rand() % y;
		Scale = scale;
		DrawFruit();
	}
void Fruits::DrawFruit()
	{
		glColor3f(0.0, 1.0, 0.0);
		glRectf(X * Scale, Y * Scale, (X + 1) * Scale, (Y + 1) * Scale);
	}