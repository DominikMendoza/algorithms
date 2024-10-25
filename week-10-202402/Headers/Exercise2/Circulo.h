#pragma once
#include "Figura.h"

ref class Circulo : public Figura
{
private:
	float radio;

public:
	Circulo(float x, float y, float dx, float velocidad, Color color, float radio);
	void Dibujar(Graphics^ g) override;
};

Circulo::Circulo(float x, float y, float dx, float velocidad, Color color, float radio) : Figura(x, y, dx, velocidad, color, TipoFigura::Circulo)
{
	this->radio = radio;
}

void Circulo::Dibujar(Graphics^ g)
{
	Pen^ pen = gcnew Pen(color, 2);
	g->DrawEllipse(pen, x, y, radio, radio);
}