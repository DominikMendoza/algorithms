#pragma once
#include "Movil.hpp"
class Enemigo : public Movil
{
private:
public:
	Enemigo(int x, int y, int width, int height);
	~Enemigo();
};

Enemigo::Enemigo(int x, int y, int width, int height) : Movil(x, y, width, height, 0.35,
	(rand() % 2? -10 : 10), 0, 3, 3)
{
}

Enemigo::~Enemigo()
{
}