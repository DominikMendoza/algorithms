#pragma once
#include "Figura.h"

ref class Rectangulo  : public Figura
{
private:
	int largo;
	int ancho;

public:
	Rectangulo(int x, int y, int dx, int dy, Color color, int largo, int ancho);
	void Mover(Graphics^ g) override;
	void Dibujar(Graphics^ g) override;
	int getLargo();
	int getAncho();
};

Rectangulo::Rectangulo(int x, int y, int dx, int dy, Color color, int largo, int ancho) : Figura(x, y, dx, dy, color)
{
	this->largo = largo;
	this->ancho = ancho;
}

void Rectangulo::Mover(Graphics^ g)
{
	if (x < 0 || x + largo >= g->VisibleClipBounds.Width)
	{
		dx *= -1;
	}
	if (y < 0 || y + ancho >= g->VisibleClipBounds.Height)
	{
		dy *= -1;
	}
	x += dx;
	y += dy;
}

void Rectangulo::Dibujar(Graphics^ g)
{
	SolidBrush^ brocha = gcnew SolidBrush(color);
	g->FillRectangle(brocha, x, y, largo, ancho);
}

int Rectangulo::getAncho()
{
	return ancho;
}

int Rectangulo::getLargo()
{
	return largo;
}