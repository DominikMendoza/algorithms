#pragma once
#include "Movil.hpp"
class Personaje : public Movil
{
private:
public:
	Personaje(int x, int y, int width, int height);
	~Personaje();
	void mover(Graphics^ g, char tecla) override;
};

Personaje::Personaje(int x, int y, int width, int height) : Movil(width, height)
{
	this->x = x;
	this->y = y;
	zoom = 1.5;
	dx = dy = 5;
}

Personaje::~Personaje()
{
}

void Personaje::mover(Graphics^ g, char tecla)
{
	switch (tecla)
	{
	case 'S': {
		if (y + dy + height * zoom > g->VisibleClipBounds.Height) return;
		y += dy;
		idy = 0;
		break;
	}
	case 'A': {
		if (x - dx < 0) return;
		x -= dx;
		idy = 1;
		break;
	}
	case 'D': {
		if (x + dx + width * zoom > g->VisibleClipBounds.Width) return;
		x += dx;
		idy = 2;
		break;
	}
	case 'W': {
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
