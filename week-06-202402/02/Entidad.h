#pragma once
#include "iostream"
using namespace std;
class Entidad
{
public:
	Entidad(float x, float y);
	virtual void borrar() = 0;
	virtual void mover() = 0;
	virtual void dibujar() = 0;
	float getX() { return x; }
	float getY() { return y; }
protected:
	float x, y;
};
