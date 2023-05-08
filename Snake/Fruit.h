#pragma once

#include <glut.h>
#include <gl/GL.h>
#include <stdlib.h>

class Fruits
{
public:
	int X, Y, Scale;
	Fruits(int x, int y, int scale);
	void DrawFruit();
};