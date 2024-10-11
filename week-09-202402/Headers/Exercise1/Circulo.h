#pragma once
#include "Figura.h"

class Circulo : public Figura
{
private:
	double radio;
	int x;
	int y;

public:
	Circulo(double radio, int x, int y);
	double CalcularArea() override;
	void Dibujar(System::Windows::Forms::PaintEventArgs^ e) override;
};

Circulo::Circulo(double radio, int x, int y)
{
	this->radio = radio;
	this->x = x;
	this->y = y;
}

double Circulo::CalcularArea()
{
	return 3.1416 * radio * radio;
}

void Circulo::Dibujar(System::Windows::Forms::PaintEventArgs^ e)
{
	Pen^ pen = gcnew Pen(Color::Black, 2);
	e->Graphics->DrawEllipse(pen, x, y, radio * 2, radio * 2);
}