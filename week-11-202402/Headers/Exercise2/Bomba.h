#pragma once
#include "Utilidades.h"

class Bomba
{
private:
	int x;
	int y;
	int dy;
	int ancho;
	int alto;

public:
	Bomba();
	void DibujarBomba(Graphics^ g, Bitmap^ imgBomba);
	void MoverBomba();
	Rectangle mascara();
};

Bomba::Bomba()
{
	y = 0;
	x = RandInt(0, 1000);
	ancho = 40;
	alto = 40;
	dy = RandInt(5, 15);
}

void Bomba::DibujarBomba(Graphics^ g, Bitmap^ imgBomba)
{
	g->DrawImage(imgBomba, x, y, ancho, alto);
}

void Bomba::MoverBomba()
{
	y += dy;
}

Rectangle Bomba::mascara()
{
	return Rectangle(x, y, ancho, alto);
}