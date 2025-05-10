#pragma once
#include "Movil.hpp"
class Raton : public Movil
{
private:
public:
	Raton(int x, int y);
	~Raton();
	void mover() override;
	void moverControlado(int xo, int yo, float distanciaMinima);
	void dibujar() override;
};

Raton::Raton(int x, int y) : Movil(x, y)
{
	this->ancho = 7;
	this->alto = 1;
	dx = rand() % 3 - 1;
	dy = rand() % 3 - 1;
}

Raton::~Raton()
{
}

void Raton::mover()
{
	if (x + dx < 0 || x + ancho + dx >= WIDTH) {
		dx *= -1;
	}
	if (y + dy < 0 || y + alto + dy > HEIGHT) {
		dy *= -1;
	}

	x += dx;
	y += dy;
}

void Raton::moverControlado(int xo, int yo, float distanciaMinima)
{
	float distancia;
	distancia = sqrt(pow(xo - x, 2) + pow(yo - y, 2));
	if (distancia < distanciaMinima) {
		if (x < xo) dx = -1;
		else if (x > xo) dx = 1;
		else dx = 0;

		if (y < yo) dy = -1;
		else if (y > yo) dy = 1;
		else dy = 0;
	}
	

	if (x + dx < 0 || x + ancho + dx >= WIDTH) {
		dx *= -1;
	}
	if (y + dy < 0 || y + alto + dy > HEIGHT) {
		dy *= -1;
	}

	x += dx;
	y += dy;
}

void Raton::dibujar()
{
	if (!visible) return;
	Console::SetCursorPosition(x, y);
	cout << "--(_c'>";
}
