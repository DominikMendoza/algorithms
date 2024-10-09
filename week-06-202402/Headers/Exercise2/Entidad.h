#pragma once
#include "Utilidades.h"

class Entidad
{
protected:
	float x;
	float y;
	float dx;
	float dy;
	int ancho;
	int alto;
	float velocidad;

public:
	Entidad(int ancho, int alto);
	void Borrar();
	virtual void Mover();
	virtual void Dibujar();
	float getX();
	float getY();
	int getAncho();
	int getAlto();
};

Entidad::Entidad(int ancho, int alto)
{
	this->ancho = ancho;
	this->alto = alto;
	x = 0;
	y = 0;
	dx = 0;
	dy = 0;
	velocidad = 0;
}

void Entidad::Borrar()
{
	for (int i = 0; i < alto; i++)
	{
		Console::SetCursorPosition(x, y + i);
		for (int j = 0; j < ancho; j++)
		{
			cout << " ";
		}
	}
}

void Entidad::Mover() {}

void Entidad::Dibujar() {}

float Entidad::getX()
{
	return x;
}

float Entidad::getY()
{
	return y;
}

int Entidad::getAlto()
{
	return alto;
}

int Entidad::getAncho()
{
	return ancho;
}