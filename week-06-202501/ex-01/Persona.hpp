#pragma once
#include "Movil.hpp"
#include <conio.h>
class Persona: public Movil
{
private:
	int vidas;
public:
	Persona();
	~Persona();
	void mover() override;
	void dibujar() override;
	int getVidas();
	void setVidas(int vidas);
};

Persona::Persona() : Movil(WIDTH / 2, HEIGHT - 1)
{
	this->vidas = 3;
	this->ancho = 1;
	this->alto = 1;
}

Persona::~Persona()
{
}

void Persona::mover()
{
	if (_kbhit()) {
		char tecla = _getch();
		tecla = toupper(tecla);
		switch (tecla)
		{
		case 'W': dy = -1; dx = 0; break;
		case 'A': dy = 0; dx = -1; break;
		case 'S': dy = 1; dx = 0; break;
		case 'D': dy = 0; dx = 1; break;
		}
	}
	if (x + dx < 0 || x + dx + ancho >= WIDTH) dx = 0;
	if (y + dy < 0 || y + dy + alto >= HEIGHT) dy = 0;
	x += dx;
	y += dy;
	dx = dy = 0;
}

void Persona::dibujar()
{
	Console::SetCursorPosition(x, y);
	cout << char(254);
}

int Persona::getVidas()
{
	return this->vidas;
}

void Persona::setVidas(int vidas)
{
	this->vidas = vidas;
}
