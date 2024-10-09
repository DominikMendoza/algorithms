#pragma once
#include "Utilidades.h"

class Terrestre
{
protected:
	float x;
	float y;
	float dx;
	float dy;
	float velocidad;
	int ancho;
	int alto;

public:
	Terrestre(int ancho, int alto);
	void Borrar();
	virtual void Mover();
	virtual void Dibujar();
	float getX();
	float getY();
	int getAncho();
	int getAlto();
};

Terrestre::Terrestre(int ancho, int alto)
{
	x = 0;
	y = 0;
	dx = 0;
	dy = 0;
	velocidad = 0;
	this->ancho = ancho;
	this->alto = alto;
}

void Terrestre::Borrar()
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

void Terrestre::Mover() {}

void Terrestre::Dibujar() {}

float Terrestre::getX()
{
	return x;
}

float Terrestre::getY()
{
	return y;
}

int Terrestre::getAncho()
{
	return ancho;
}

int Terrestre::getAlto()
{
	return alto;
}