#pragma once
#include "Utilidades.h"

class Avion
{
protected:
	float x;
	float y;
	float dx;
	float dy;
	float velocidad;
	int alto;
	int ancho;
	bool movimiento;

public:
	Avion(float velocidad, int ancho, int alto);
	void Borrar();
	virtual void Mover();
	virtual void Dibujar();
	bool estaEnMovimiento();
};

Avion::Avion(float velocidad, int ancho, int alto)
{
	this->velocidad = velocidad;
	this->ancho = ancho;
	this->alto = alto;
	x = 0;
	y = 0;
	dx = 0;
	dy = 0;
	movimiento = true;
}

void Avion::Borrar()
{
	for (int i = 0; i < ancho; i++)
	{
		for (int j = 0; j < alto; j++)
		{
			Console::SetCursorPosition(static_cast<int>(x) + i, static_cast<int>(y) + j); cout << " ";
		}
	}
}

void Avion::Dibujar() {}

void Avion::Mover() {}

bool Avion::estaEnMovimiento()
{
	return movimiento;
}