#pragma once
#include "CFigura.hpp"
class CRectangulo : public CFigura
{
private:
public:
	CRectangulo(float x, float y, float dx);
	~CRectangulo();
	void dibujar(Graphics^ g) override;
	string getNombre() override;
};

CRectangulo::CRectangulo(float x, float y, float dx) : CFigura(x, y, dx)
{
}

CRectangulo::~CRectangulo()
{
}

void CRectangulo::dibujar(Graphics^ g)
{
	Pen^ pencil = gcnew Pen(Color::Red, 2);
	g->DrawRectangle(pencil, x, y, width, height);
}

string CRectangulo::getNombre()
{
	return "Rectangulo";
}
