#pragma once
#include "Figura.hpp"
#define PI 3.1416
class Elipse : public Figura
{
private:

public:
	Elipse(int x, int y, int radio);
	~Elipse();
	void dibujar(Graphics^ g) override;
	double getArea() override;
};

Elipse::Elipse(int x, int y, int radio) : Figura(x, y, radio, radio)
{
}

Elipse::~Elipse()
{
}

void Elipse::dibujar(Graphics^ g)
{
	SolidBrush^ brocha = gcnew SolidBrush(Color::Blue);
	g->FillEllipse(brocha, x, y, lado1, lado2);
}

double Elipse::getArea()
{
	return PI * lado1 * lado2;
}
