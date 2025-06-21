#pragma once
#include "Movil.hpp"
class Enemigo : public Movil
{
private:
public:
	Enemigo(int x, int y, int width, int height);
	~Enemigo();
	void mover(Graphics^ g, char tecla) override;
};

Enemigo::Enemigo(int x, int y, int width, int height) : Movil(width, height)
{
	this->x = x;
	this->y = y;
	zoom = 1.0;
	dx = dy = 5;
}

Enemigo::~Enemigo()
{
}

void Enemigo::mover(Graphics^ g, char tecla)
{
	int randMov = rand() % 4;
	switch (randMov)
	{
	case 0: {
		if (y + dy + height * zoom > g->VisibleClipBounds.Height) return;
		y += dy;
		idy = 0;
		break;
	}
	case 1: {
		if (x - dx < 0) return;
		x -= dx;
		idy = 1;
		break;
	}
	case 2: {
		if (x + dx + width * zoom > g->VisibleClipBounds.Width) return;
		x += dx;
		idy = 2;
		break;
	}
	case 3: {
		if (y - dy < 0) return;
		y -= dy;
		idy = 3;
		break;
	}
	}
	idx++;
	if (idx > 3) {
		idx = 0;
	}
}
