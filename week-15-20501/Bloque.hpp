#pragma once
#include "Movil.hpp"
class Bloque : public Movil
{
private:
public:
	Bloque(int x, int y, int width, int height);
	~Bloque();
	void mover(Graphics^ g, char tecla) override;
};

Bloque::Bloque(int x, int y, int width, int height) : Movil(width, height)
{
	this->x = x;
	this->y = y;
	zoom = 1.5;
	dx = dy = 4;
}

Bloque::~Bloque()
{
}

void Bloque::mover(Graphics^ g, char tecla)
{
}
