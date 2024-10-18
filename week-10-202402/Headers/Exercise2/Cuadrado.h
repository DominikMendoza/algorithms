#pragma once
#include "Figura.h"

ref class Cuadrado : public Figura
{
private:
	float lado;

public:
	Cuadrado(float x, float y, float dx, float velocidad, Color color, float lado);
	void Dibujar(Graphics^ g) override;
};

Cuadrado::Cuadrado(float x, float y, float dx, float velocidad, Color color, float lado) : Figura(x, y, dx, velocidad, color, TipoFigura::Cuadrado)
{
	this->lado = lado;
}

void Cuadrado::Dibujar(Graphics^ g)
{
	Pen^ pen = gcnew Pen(color, 2);
	g->DrawRectangle(pen, x, y, lado, lado);
}