#pragma once
#include "Figura.h"

ref class Triangulo : public Figura
{
private:
	float lado;

public:
	Triangulo(float x, float y, float dx, float velocidad, Color color, float lado);
	void Dibujar(Graphics^ g) override;
};

Triangulo::Triangulo(float x, float y, float dx, float velocidad, Color color, float lado) : Figura(x, y, dx, velocidad, color, TipoFigura::Triangulo)
{
	this->lado = lado;
}

void Triangulo::Dibujar(Graphics^ g)
{
	cli::array<Point>^ puntos = gcnew cli::array<Point>(3)
	{
		Point(x, y),
		Point(x + lado, y),
		Point(x + (lado / 2), y - (lado * sqrt(3) / 2))
	};
	Pen^ pen = gcnew Pen(color, 2);
	g->DrawPolygon(pen, puntos);
}