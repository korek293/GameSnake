#pragma once

#include <glut.h>
#include <gl/GL.h>
#include <stdlib.h>

class Viruses
{
public:
	int H, J, Scale;//H->x, J->y

	Viruses(int x, int y, int scale);
	void DrawVirus();
	
};