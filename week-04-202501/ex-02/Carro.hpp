#pragma once
#include "Llanta.hpp"
#include "Chasis.hpp"
#define WIDTH 80
#define HEIGHT 40
class Carro
{
private:
	int x, y, dx, dy;
	int ancho, alto;
	int codigoColor;
	Llanta* llanta;
	Chasis* chasis;
public:
	Carro(int x, int y);
	~Carro();
	void borrar();
	void mover();
	void dibujar();
	int getDx();
};

Carro::Carro(int x, int y)
{
	this->x = x;
	this->y = y;
	this->dx = rand() % 3 + 1;
	this->dy = 0;
	this->alto = 3;
	this->ancho = 5;
	this->codigoColor = rand() % 14 + 1;
	this->llanta = new Llanta();
	this->chasis = new Chasis();
}

Carro::~Carro()
{
}

void Carro::borrar()
{
	llanta->borrar(x, y);
	llanta->borrar(x + 2, y);
	chasis->borrar(x, y + 1);
	llanta->borrar(x, y + 2);
	llanta->borrar(x + 2, y + 2);
}

void Carro::mover()
{
	dx = rand() % 5 + 1;
	if (x + ancho + dx > WIDTH) {
		dx = 0;
	}
	x += dx;
	y += dy;
}

void Carro::dibujar()
{
	Console::ForegroundColor = ConsoleColor(codigoColor);
	llanta->dibujar(x, y);
	llanta->dibujar(x + 2, y);
	chasis->dibujar(x, y + 1);
	llanta->dibujar(x, y + 2);
	llanta->dibujar(x + 2, y + 2);
	// Console::ResetColor();
}

int Carro::getDx()
{
	return this->dx;
}
