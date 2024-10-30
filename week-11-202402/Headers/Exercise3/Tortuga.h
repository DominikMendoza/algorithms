#pragma once
#include "Utilidades.h"

class Tortuga
{
private:
	int x;
	int y;
	int velocidad;
	int dx;
	int fila;
	int columna;
	int ancho;
	int alto;

public:
	Tortuga(int x, int y);
	void DibujarTortuga(Graphics^ g, Bitmap^ img);
	void MoverTortuga();
	Rectangle mascara();
};

Tortuga::Tortuga(int x, int y)
{
	this->x = x;
	this->y = y;
	dx = 1;
	velocidad = RandInt(2, 10);
	fila = 0;
	columna = 0;
}

void Tortuga::DibujarTortuga(Graphics^ g, Bitmap^ img)
{
	ancho = img->Width / 4;
	alto = img->Height / 3;
	Rectangle frame = Rectangle(ancho * columna, alto * fila, ancho, alto);
	Rectangle zoom = Rectangle(x, y, ancho * 0.3, alto * 0.3);
	g->DrawImage(img, zoom, frame, GraphicsUnit::Pixel);
}

void Tortuga::MoverTortuga()
{
	x += dx * velocidad;
	columna++;
	if (columna > 3)
	{
		fila++;
		columna = 0;
		if (fila > 2)
		{
			fila = 0;
			columna = 0;
		}
	}
}

Rectangle Tortuga::mascara()
{
	return Rectangle(x + 20, y, ancho * 0.3 - 50, alto * 0.3);
}