#pragma once
#include "CFigura.hpp"
class CElipse : public CFigura
{
private:
public:
	CElipse(float x, float y, float dx);
	~CElipse();
	void dibujar(Graphics^ g) override;
	string getNombre() override;
};

CElipse::CElipse(float x, float y, float dx) : CFigura(x, y, dx)
{
}

CElipse::~CElipse()
{
}

void CElipse::dibujar(Graphics^ g)
{
	Pen^ pencil = gcnew Pen(Color::Green, 2);
	g->DrawEllipse(pencil, x, y, width, height);
}

string CElipse::getNombre()
{
	return "Elipse";
}
