#pragma once
#include "Figura.h"

class Linea : public Figura
{
private:
	double longitud;
	int x;
	int y;

public:
	Linea(double longitud, int x, int y);
	void Dibujar(System::Windows::Forms::PaintEventArgs^ e) override;
};

Linea::Linea(double longitud, int x, int y)
{
	this->longitud = longitud;
	this->x = x;
	this->y = y;
}

void Linea::Dibujar(System::Windows::Forms::PaintEventArgs^ e)
{
	Pen^ pen = gcnew Pen(Color::Black, 2);
	e->Graphics->DrawLine(pen, x, y, x + longitud, y);
}