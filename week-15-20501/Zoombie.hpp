#pragma once
#include "Movil.hpp"
class Zoombie : public Movil
{
private:
	int vidas;
public:
	Zoombie(int x, int y, int width, int height, int vidas);
	~Zoombie();
	void mover(Graphics^ g, char tecla) override;
	bool puedeMoverse(char tecla, Movil* ob);
	void disminuirVidas();
	int getVidas();
};

Zoombie::Zoombie(int x, int y, int width, int height, int vidas) : Movil(width, height)
{
	this->x = x;
	this->y = y;
	this->vidas = vidas;
	zoom = 0.7;
	dx = dy = 5;
}

Zoombie::~Zoombie()
{
}

void Zoombie::mover(Graphics^ g, char tecla)
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

bool Zoombie::puedeMoverse(char tecla, Movil* ob)
{
	int posFutura;
	switch (tecla)
	{
	case 'S': {
		posFutura = y + dy + height * zoom;
		if (posFutura > ob->getRectangle().Y) {
			return false;
		}
		break;
	}
	case 'A': {
		posFutura = x - dx;
		if (posFutura < ob->getRectangle().Width) {
			return false;
		}
		break;
	}
	case 'D': {
		posFutura = x + dx + width * zoom;
		if (posFutura > ob->getRectangle().X) {
			return false;
		}
		break;
	}
	case 'W': {
		posFutura = y - dy;
		if (posFutura < ob->getRectangle().Height) {
			return false;
		}
		break;
	}
	}
	return true;
}

void Zoombie::disminuirVidas()
{
	this->vidas--;
}

int Zoombie::getVidas()
{
	return this->vidas;
}
