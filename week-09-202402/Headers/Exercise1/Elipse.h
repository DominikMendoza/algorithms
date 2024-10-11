#pragma once
#include "Figura.h"

class Elipse : public Figura
{
private:
	double ejemayor;
	double ejemenor;
	int x;
	int y;

public:
	Elipse(double ejemayor, double ejemenor, int x, int y);
	double CalcularArea() override;
	void Dibujar(System::Windows::Forms::PaintEventArgs^ e) override;
};

Elipse::Elipse(double ejemayor, double ejemenor, int x, int y)
{
	this->ejemayor = ejemayor;
	this->ejemenor = ejemenor;
	this->x = x;
	this->y = y;
}

double Elipse::CalcularArea()
{
	return 3.1416 * ejemayor * ejemenor;
}

void Elipse::Dibujar(System::Windows::Forms::PaintEventArgs^ e)
{
	Pen^ pen = gcnew Pen(Color::Black, 2);
	e->Graphics->DrawEllipse(pen, x, y, ejemayor * 2, ejemenor * 2);
}