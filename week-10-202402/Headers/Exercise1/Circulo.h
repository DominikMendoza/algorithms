#pragma once
#include "Figura.h"

ref class Circulo : public Figura
{
private:
	int radio;

public:
	Circulo(int x, int y, int dx, int dy, Color color, int radio);
	void Mover(Graphics^ g) override;
	void Dibujar(Graphics^ g) override;
	int getRadio();
};

Circulo::Circulo(int x, int y, int dx, int dy, Color color, int radio) : Figura(x, y, dx, dy, color)
{
	this->radio = radio;
}

void Circulo::Mover(Graphics^ g)
{
	if (x < 0 || x + radio >= g->VisibleClipBounds.Width)
	{
		dx *= -1;
	}
	if (y < 0 || y + radio >= g->VisibleClipBounds.Height)
	{
		dy *= -1;
	}
	x += dx;
	y += dy;
}

void Circulo::Dibujar(Graphics^ g)
{
	SolidBrush^ brocha = gcnew SolidBrush(color);
	g->FillEllipse(brocha, x, y, radio, radio);
}

int Circulo::getRadio()
{
	return radio;
}