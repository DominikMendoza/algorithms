#pragma once
#include "Figura.h"

ref class Triangulo : public Figura
{
private:
	int lado;

public:
	Triangulo(int x, int y, int dx, int dy, Color color, int lado);
	void Mover(Graphics^ g) override;
	void Dibujar(Graphics^ g) override;
	int getLado();
};

Triangulo::Triangulo(int x, int y, int dx, int dy, Color color, int lado) : Figura(x, y, dx, dy, color)
{
	this->lado = lado;
}

void Triangulo::Mover(Graphics^ g)
{
	if (x < 0 || x + lado >= g->VisibleClipBounds.Width)
	{
		dx *= -1;
	}
	if (y < 0 || y - (lado * sqrt(3) / 2) < 0 || y >= g->VisibleClipBounds.Height)
	{
		dy *= -1;
	}
	x += dx;
	y += dy;
}

void Triangulo::Dibujar(Graphics^ g)
{
	cli::array<Point>^ puntos = gcnew cli::array<Point>(3)
	{
		Point(x, y),
		Point(x + lado, y),
		Point(x + (lado / 2), y - (lado * sqrt(3) / 2))
	};
	SolidBrush^ brocha = gcnew SolidBrush(color);
	g->FillPolygon(brocha, puntos);
}

int Triangulo::getLado()
{
	return lado;
}