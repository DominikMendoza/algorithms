#pragma once
#include "Figura.h"

ref class Elipse : public Figura
{
private:
	int ejemayor;
	int ejemenor;

public:
	Elipse(int x, int y, int dx, int dy, Color color, int ejemayor, int ejemenor);
	void Mover(Graphics^ g) override;
	void Dibujar(Graphics^ g) override;
	int getEjeMayor();
	int getEjeMenor();
};

Elipse::Elipse(int x, int y, int dx, int dy, Color color, int ejemayor, int ejemenor) : Figura(x, y, dx, dy, color)
{
	this->ejemayor = ejemayor;
	this->ejemenor = ejemenor;
}

void Elipse::Mover(Graphics^ g)
{
	if (x < 0 || x + ejemayor >= g->VisibleClipBounds.Width)
	{
		dx *= -1;
	}
	if (y < 0 || y + ejemenor >= g->VisibleClipBounds.Height)
	{
		dy *= -1;
	}
	x += dx;
	y += dy;
}

void Elipse::Dibujar(Graphics^ g)
{
	SolidBrush^ brocha = gcnew SolidBrush(color);
	g->FillEllipse(brocha, x, y, ejemayor, ejemenor);
}

int Elipse::getEjeMayor()
{
	return ejemayor;
}

int Elipse::getEjeMenor()
{
	return ejemenor;
}