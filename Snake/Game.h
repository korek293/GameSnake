#pragma once

#include <glut.h>
#include <gl/GL.h>
#include <stdlib.h>
#include "Virus.h"
#include "Fruit.h"
#include "Snake.h"

class Game
{
public:
	int N = 20, M = 30;//N-szerokosc M-dlugosc
	int Scale = 25;
	int dir;//dir-zmienna, reprezentujaca kierunki weza. 

	int w = Scale * N;
	int h = Scale * M;

	Game()
	{
		dir = 0;

		// tworzy fruits
		for (int i = 0; i < 5; i++)
			m[i] = new Fruits(N, M, Scale);

		// tworzy wirusy
		for (int i = 0; i < 5; i++)
			n[i] = new Viruses(N, M, Scale);



		// tworzy snake
		snake = new Snake(Scale);
	}

private:
	Fruits* m[10];
	Viruses* n[10];
	Snake* snake;
	int finish = 0;
public:

	void DrawField()
	{
		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_LINES);

		for (int i = 0; i < w; i += Scale)
		{
			glVertex2f(i, 0);
			glVertex2f(i, h);
		}
		for (int j = 0; j < h; j += Scale)
		{
			glVertex2f(0, j);
			glVertex2f(w, j);
		}
		glEnd();
	}

	void Display()//funkcja, ktora wszystko wyswietla na ekran
	{
		glClear(GL_COLOR_BUFFER_BIT);
		DrawField();
		void output_text(int x, int y, const char* string);

		//sprawdza dlugosc snakea
		if (snake->num > 40)
		{
			const char* win = "YOU WIN!!!";
			output_text(4 * Scale, 30 * Scale, win);

		}

		// ruch snakea
		snake->Move(dir);

		//sprawdza limity display
		if (snake->s[0].x < 0) snake->s[0].x = N;
		if (snake->s[0].x > N) snake->s[0].x = 0;
		if (snake->s[0].y < 0) snake->s[0].y = M;
		if (snake->s[0].y > M) snake->s[0].y = 0;

		// rysuje snake
		snake->DrawSnake();

		for (int i = 0; i < 10; i++)
		{
			if (m[i] != nullptr)
			{
				// sprawdza czy jablko bylo zjedzone
				if ((m[i]->X == snake->s[0].x) && (m[i]->Y == snake->s[0].y))
				{
					// jesli snake zjadl jablko, to dlugosc zwieksza sie				
					snake->num += 1;
					// usuwa stare jablko
					free(m[i]);
					// tworzy nowe jablko
					m[i] = new Fruits(N, M, Scale);
				}
				// rysuje jablko
				m[i]->DrawFruit();
			}
		}

		for (int i = 0; i < 10; i++)
		{
			if (n[i] != nullptr)
			{
				// sprawdza, czy byly zjedzony wirus
				if ((n[i]->H == snake->s[0].x) && (n[i]->J == snake->s[0].y))
				{
					// jesli snake zjadl wirus, to gra sie konczy
					exit(0);

				}
				// rysuje virus
				n[i]->DrawVirus();
			}
		}
		glFlush();
	}
} game;

