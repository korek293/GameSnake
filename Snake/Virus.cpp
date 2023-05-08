#include "Virus.h"
#include <glut.h>
#include <gl/GL.h>


Viruses::Viruses(int x, int y, int scale)
{
	H = rand() % x;
	J = rand() % y;
	Scale = scale;
	DrawVirus();
}
void Viruses::DrawVirus()
{
	glColor3f(1.0, 0.0, 0.0);
	glRectf(H * Scale, J * Scale, (H + 1) * Scale, (J + 1) * Scale);
}