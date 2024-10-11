#pragma once
#include "Figura.h"

class Rectangulo : public Figura
{
private:
	double ancho;
	double largo;
	int x;
	int y;

public:
	Rectangulo(double ancho, double largo, int x, int y);
	double CalcularArea() override;
	void Dibujar(System::Windows::Forms::PaintEventArgs^ e) override;
};

Rectangulo::Rectangulo(double ancho, double largo, int x, int y)
{
	this->ancho = ancho;
	this->largo = largo;
	this->x = x;
	this->y = y;
}

double Rectangulo::CalcularArea()
{
	return ancho * largo;
}

void Rectangulo::Dibujar(System::Windows::Forms::PaintEventArgs^ e)
{
	Pen^ pen = gcnew Pen(Color::Black, 2);
	e->Graphics->DrawRectangle(pen, x, y, largo, ancho);
}