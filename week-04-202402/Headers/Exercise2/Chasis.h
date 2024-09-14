#pragma once
#include "Utilidades.h"

class Chasis
{
private:
	float x;
	float y;
	float dx;
	int ancho;
	char forma;

public:
	Chasis(float x, float y, int ancho);
	void BorrarChasis();
	void DibujarChasis();
	void MoverChasis(float velocidad);
};

Chasis::Chasis(float x, float y, int ancho)
{
	this->x = x;
	this->y = y;
	this->ancho = ancho;
	forma = 220;
	dx = 1;
}

void Chasis::BorrarChasis()
{
	for (int i = 0; i < ancho; i++)
	{
		Cursor(x + i, y); cout << " ";
	}
}

void Chasis::DibujarChasis()
{
	for (int i = 0; i < ancho; i++)
	{
		Cursor(x + i, y); cout << forma;
	}
}

void Chasis::MoverChasis(float velocidad)
{
	x += dx * velocidad;
}