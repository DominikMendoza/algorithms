#pragma once
#include "Ala.hpp"
#include "Fuselaje.hpp"
#include "TrenDeAterrizaje.hpp"
#define WIDTH 80
#define HEIGHT 40
class Avion
{
private:
	int x, y, dx, dy;
	int ancho, alto;
	Ala* ala;
	Fuselaje* fuselaje;
	TrenDeAterrizaje* trenDeAterrizaje;
public:
	Avion(int x, int y);
	~Avion();
	void borrar();
	void mover();
	void dibujar();
};

Avion::Avion(int x, int y)
{
	this->x = x;
	this->y = y;
	this->dx = rand() % 3 - 1;
	this->dy = 1;
	this->alto = 3;
	this->ancho = 10;
	this->ala = new Ala();
	this->fuselaje = new Fuselaje();
	this->trenDeAterrizaje = new TrenDeAterrizaje();
}

Avion::~Avion()
{
}

void Avion::borrar()
{
	// Borrar preciso
	ala->borrar(x + 3, y);
	fuselaje->borrar(x + 1, y + 1);
	trenDeAterrizaje->borrar(x, y + 1);
	/* Mas sencillo
	for (int i = 0; i < ancho; i++)
	{
		for (int j = 0; j < alto; j++)
		{
			Console::SetCursorPosition(i, j);
			cout << " ";
		}
	}
	*/
}

void Avion::mover()
{
	dx = rand() % 3 - 1;
	if (x + dx < 0 || x + ancho + dx > WIDTH) {
		dx = 0;
	}

	if (y + alto + dy > HEIGHT) {
		dy = 0;
	}

	if (dy == 0) dx = 0;
	x += dx;
	y += dy;
}

void Avion::dibujar()
{
	ala->dibujar(x + 3, y);
	fuselaje->dibujar(x + 1, y + 1);
	trenDeAterrizaje->dibujar(x, y + 1);
}
