#pragma once
#include "Figura.h"

class Cuadrado : public Figura
{
private:
	double lado;
	int x;
	int y;

public:
	Cuadrado(double lado, int x, int y);
	double CalcularArea() override;
	void Dibujar(System::Windows::Forms::PaintEventArgs^ e) override;
};

Cuadrado::Cuadrado(double lado, int x, int y)
{
	this->lado = lado;
	this->x = x;
	this->y = y;
}

double Cuadrado::CalcularArea()
{
	return lado * lado;
}

void Cuadrado::Dibujar(System::Windows::Forms::PaintEventArgs^ e)
{
	Pen^ pen = gcnew Pen(Color::Black, 2);
	e->Graphics->DrawRectangle(pen, x, y, lado, lado);
}