#pragma once
#include "iostream"
using namespace std;
class Entidad
{
public:
	Entidad(float x, float y, int ancho, int alto);
	void borrar();
	virtual void mover() = 0;
	virtual void dibujar() = 0;
	float getX() { return x; }
	float getY() { return y; }
	int getAncho() { return ancho; }
	int getAlto() { return alto; }
protected:
	float x, y;
	int ancho, alto;
};
