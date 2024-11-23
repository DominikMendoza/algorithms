#pragma once
#include "Movil.hpp"
class Bala : public Movil
{
private:
public:
	Bala(int x, int y, int width, int height);
	~Bala();
};

Bala::Bala(int x, int y, int width, int height) : Movil(x, y, width, height, 0.3, 10, 0)
{
}

Bala::~Bala()
{
}