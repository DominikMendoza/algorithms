#pragma once
#include "Movil.hpp"
class Disco : public Movil
{
private:
public:
	Disco(int x, int y, int width, int height, int dx, int dy);
	~Disco();
	void mover(Graphics^ g, char tecla) override;
	bool isLetal();
	int getType();
};

Disco::Disco(int x, int y, int width, int height, int dx, int dy) : Movil(width, height)
{
	this->x = x;
	this->y = y;
	this->dx = dx;
	this->dy = dy;
	zoom = 0.5;
}

Disco::~Disco()
{
}

void Disco::mover(Graphics^ g, char tecla)
{
	if (x + dx < 0 || x + dx + width * zoom > g->VisibleClipBounds.Width) {
		dx *= -1;
	}
	if (y + dy < 0 || y + dy + height * zoom > g->VisibleClipBounds.Height) {
		dy *= -1;
	}
	x += dx;
	y += dy;
}

bool Disco::isLetal()
{
	return (dx > 0 && dy > 0);
}

int Disco::getType()
{
	if (dy == 0) {
		return 1; // rojo
	}
	if (dx == 0) {
		return 2; // azul
	}
	return 3; // gris
}
