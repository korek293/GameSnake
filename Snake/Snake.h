#pragma once
#pragma once
#include <stdlib.h>
#include <glut.h>
#include <gl/GL.h>

class Snake
{
	int Scale;
public:
	int num = 4; //num - poczatkowa liczba kwadratow

	Snake(int scale)
	{
		Scale = scale;
		s[0].x = 10;//poczatkowe wspolrzedne
		s[0].y = 15;//
	}

	struct//macierz snake'a(wspolrzedne snake'a)
	{
		int x;
		int y;
	}
	s[100];



	void DrawSnake()
	{
		glColor3f(0.3, 0.6, 0.7);
		for (int i = 0; i < num; i++)//rysuje kwadraty
		{
			glRectf(s[i].x * Scale, s[i].y * Scale, (s[i].x + 0.9) * Scale, (s[i].y + 0.9) * Scale);//--to takie wspolrzedne kwadratow

		}
	}

	void Move(int dir)//ruch weza
	{
		for (int i = num; i > 0; --i)//przemieszcza sie reszta
		{
			
			s[i].x = s[i - 1].x;
			s[i].y = s[i - 1].y;
		}

		if (dir == 0) s[0].y += 1;//przemieszcza sie glowa
		if (dir == 1) s[0].x -= 1;
		if (dir == 2) s[0].x += 1;
		if (dir == 3) s[0].y -= 1;
	}
};