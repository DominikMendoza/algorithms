#pragma once
#include "Movil.hpp"
class Personaje : public Movil
{
private:
	int hp;
public:
	Personaje(int x, int y, int width, int height, int hp);
	~Personaje();
	void dibujar(Graphics^ g);
	void movimientoControlado(Graphics^ g, char tecla);
	void disminuirVida();
	void resetearCoordenadas();
	int getVidas();
};

Personaje::Personaje(int x, int y, int width, int height, int hp) : Movil(x, y, width, height, 1.0)
{
	this->hp = hp;
}

Personaje::~Personaje()
{
}

void Personaje::dibujar(Graphics^ g)
{
	SolidBrush^ b = gcnew SolidBrush(Color::Green);
	g->FillRectangle(b, *this->rec);
}

void Personaje::movimientoControlado(Graphics^ g, char tecla)
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

void Personaje::disminuirVida()
{
	this->hp--;
}

void Personaje::resetearCoordenadas()
{
	rec->X = 0;
	rec->Y = 0;
}

int Personaje::getVidas()
{
	return this->hp;
}
