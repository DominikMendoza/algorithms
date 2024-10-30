#pragma once
#include "Utilidades.h"

class Fruta
{
private:
	int x;
	int y;
	int dy;
	int ancho;
	int alto;
	int fila;
	int columna;

public:
	Fruta();
	void DibujarFruta(Graphics^ g, Bitmap^ imgFrutas);
	void MoverFruta();
	Rectangle mascara();
};

Fruta::Fruta()
{
	x = RandInt(0, 1000);
	y = 0;
	dy = RandInt(5, 15);
	fila = RandInt(0, 3);
	columna = RandInt(0, 3);
}

void Fruta::DibujarFruta(Graphics^ g, Bitmap^ imgFrutas)
{
	ancho = imgFrutas->Width / 4;
	alto = imgFrutas->Height / 4;
	Rectangle frame = Rectangle(columna * ancho, fila * alto, ancho, alto);
	Rectangle zoom = Rectangle(x, y, ancho * 0.2, alto * 0.2);
	g->DrawImage(imgFrutas, zoom, frame, GraphicsUnit::Pixel);
}

void Fruta::MoverFruta()
{
	y += dy;
}

Rectangle Fruta::mascara()
{
	return Rectangle(x, y, ancho * 0.2, alto * 0.2);
}