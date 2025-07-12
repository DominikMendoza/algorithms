#pragma once
#include "Movil.hpp"
class Planta : public Movil
{
private:
public:
	Planta(int x, int y, int width, int height);
	~Planta();
	void mover(Graphics^ g, char tecla) override;
};

Planta::Planta(int x, int y, int width, int height) : Movil(width, height)
{
	this->x = x;
	this->y = y;
	zoom = 0.8;
	dx = dy = 7;
	idx = rand() % 8;
}

Planta::~Planta()
{
}

void Planta::mover(Graphics^ g, char tecla)
{
	int aux = rand() % 30;
	if (aux % 27 == 0) {
		dx *= -1;
	}

	aux = rand() % 30;
	if (aux % 17 == 0) {
		dy *= -1;
	}

	if (x + dx < 0 || x + dx + width * zoom > g->VisibleClipBounds.Width) {
		dx *= -1;
	}

	if (y + dy < 0 || y + dy + height * zoom > g->VisibleClipBounds.Height) {
		dy *= -1;
	}
	x += dx;
	y += dy;
}