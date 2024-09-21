#pragma once
#include "iostream"
using namespace std;
class Terrestre
{
public:
	Terrestre(float x, float y, float maxVel, float minVel);
	virtual void borrar() = 0;
	virtual void mover() = 0;
	virtual void dibujar() = 0;
	virtual void cambiarVelocidad(float cantidad) = 0;
	float getX() { return x; }
	float getY() { return y; }
protected:
	float x, y, velocidad;
};

