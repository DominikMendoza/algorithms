#pragma once
#include <conio.h>
#include "Movil.hpp"
class Gato : public Movil
{
private:
public:
	Gato(int x, int y);
	~Gato();
	void mover() override;
	void dibujar() override;
};

Gato::Gato(int x, int y) : Movil(x, y)
{
	this->ancho = 5;
	this->alto = 3;
}

Gato::~Gato()
{
}

void Gato::mover()
{
	if (kbhit()) {
		char tecla = _getch();
		tecla = toupper(tecla);
		switch (tecla)
		{
		case 'W': dy = -1; dx = 0; break;
		case 'A': dy = 0; dx = -1; break;
		case 'S': dy = 1; dx = 0; break;
		case 'D': dy = 0; dx = 1; break;
		default:
			break;
		}
	}
	dx *= 3;
	dy *= 3;
	if (x + dx < 0 || x + dx >= WIDTH) {
		dx = 0;
	}
	if (y + dy < 0 || y + dy > HEIGHT) {
		dy = 0;
	}

	x += dx;
	y += dy;
	dx = dy = 0;
}

void Gato::dibujar()
{
	for (int i = 0; i < ancho; i++)
	{
		for (int j = 0; j < alto; j++)
		{
			Console::SetCursorPosition(x + i, y + j);
			cout << "*";
		}
	}
}
