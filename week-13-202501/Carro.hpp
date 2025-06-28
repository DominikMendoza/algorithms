#pragma once
#include "Movil.hpp"
class Carro : public Movil
{
private:
public:
	Carro(int x, int y, int width, int height);
	~Carro();
	void mover(Graphics^ g, char tecla) override;
};

Carro::Carro(int x, int y, int width, int height) : Movil(width, height)
{
	this->x = x;
	this->y = y;
	zoom = 1.0;
	dy = dx = 0;
	idy = 2;
}

Carro::~Carro()
{
}

void Carro::mover(Graphics^ g, char tecla)
{
	switch (tecla)
	{
	case 'V': idy = 0; break;
	case 'R': idy = 1; break;
	case 'P': idy = 2; break;
	}
	idx++;
	if (idx > 3) idx = 0;
}