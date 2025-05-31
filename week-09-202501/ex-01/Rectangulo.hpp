#pragma once
#include "Figura.hpp"

class Rectangulo : public Figura
{
private:

public:
	Rectangulo(int x, int y, int lado1, int lado2);
	~Rectangulo();
	void dibujar(Graphics^ g) override;
	double getArea() override;
};

Rectangulo::Rectangulo(int x, int y, int lado1, int lado2) : Figura(x, y, lado1, lado2)
{
}

Rectangulo::~Rectangulo()
{
}

void Rectangulo::dibujar(Graphics^ g)
{
	SolidBrush^ brocha = gcnew SolidBrush(Color::Red);
	g->FillRectangle(brocha, x, y, lado1, lado2);
}

double Rectangulo::getArea()
{
	return lado1 * lado2;
}
