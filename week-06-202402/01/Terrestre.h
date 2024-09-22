#pragma once
#include "iostream"
using namespace std;
class Terrestre
{
public:
	Terrestre(float x, float y, float maxVel, float minVel, int ancho, int alto);
	void borrar();
	virtual void mover() = 0;
	virtual void dibujar() = 0;
	virtual void cambiarVelocidad(float cantidad) = 0;
	float getX() { return x; }
	float getY() { return y; }
	int getAncho() { return ancho; }
	int getAlto() { return alto; }
protected:
	float x, y, velocidad;
	int ancho, alto;
};

