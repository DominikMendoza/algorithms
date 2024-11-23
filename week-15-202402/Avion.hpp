#pragma once
#include "Movil.hpp"
class Avion : public Movil
{
private:
	int hp;
public:
	Avion(int x, int y, int width, int height);
	~Avion();
	void movimientoControlado(Graphics^ g, char tecla);
	void disminuirVida();
	void resetearCoordenadas();
	int getVidas();
};

Avion::Avion(int x, int y, int width, int height) : Movil(x, y, width, height, 0.25)
{
	this->hp = 6;
}

Avion::~Avion()
{
}

void Avion::movimientoControlado(Graphics^ g, char tecla)
{
	switch (tecla)
	{
	case 'W': {
		if (rec->Y + dy < 0) return;
		dy = -10; dx = 0; break;
	}
	case 'S': {
		if (rec->Y + dy + rec->Height > g->VisibleClipBounds.Height) return;
		dy = 10; dx = 0; break;
	}
	case 'A': {
		if (rec->X + dx < 0) return;
		dx = -10; dy = 0; break;
	}
	case 'D': {
		if (rec->X + dx + rec->Width > g->VisibleClipBounds.Width) return;
		dx = 10; break;
	}
	}
	rec->X += dx;
	rec->Y += dy;
	dx = dy = 0;
}

void Avion::disminuirVida()
{
	this->hp--;
}

void Avion::resetearCoordenadas()
{
	rec->X = 0;
	rec->Y = 0;
}

int Avion::getVidas()
{
	return this->hp;
}