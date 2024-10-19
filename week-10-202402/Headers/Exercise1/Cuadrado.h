#pragma once
#include "Figura.h"

ref class Cuadrado : public Figura
{
private:
	int lado;

public:
	Cuadrado(int x, int y, int dx, int dy, Color color, int lado);
	void Mover(Graphics^ g) override;
	void Dibujar(Graphics^ g) override;
	int getLado();
};

Cuadrado::Cuadrado(int x, int y, int dx, int dy, Color color, int lado) : Figura(x, y, dx, dy, color)
{
	this->lado = lado;
}

void Cuadrado::Mover(Graphics^ g)
{
	if (x < 0 || x + lado >= g->VisibleClipBounds.Width)
	{
		dx *= -1;
	}
	if (y < 0 || y + lado >= g->VisibleClipBounds.Height)
	{
		dy *= -1;
	}
	x += dx;
	y += dy;
}

void Cuadrado::Dibujar(Graphics^ g)
{
	SolidBrush^ brocha = gcnew SolidBrush(color);
	g->FillRectangle(brocha, x, y, lado, lado);
}

int Cuadrado::getLado()
{
	return lado;
}