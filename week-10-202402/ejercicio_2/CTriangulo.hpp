#pragma once
#include "CFigura.hpp"
class CTriangulo : public CFigura
{
private:
public:
	CTriangulo(float x, float y, float dx);
	~CTriangulo();
	void dibujar(Graphics^ g) override;
	string getNombre() override;
};

CTriangulo::CTriangulo(float x, float y, float dx) : CFigura(x, y, dx)
{
}

CTriangulo::~CTriangulo()
{
}

void CTriangulo::dibujar(Graphics^ g)
{
	Pen^ pencil = gcnew Pen(Color::Blue, 2);
	cli::array<Point>^ points = {
		Point(x + width / 2, y),
		Point(x, y + height),
		Point(x + width, y + height)
	};
	g->DrawPolygon(pencil, points);
	/*
	g->DrawLine(pencil, x, y, x, y + height);
	g->DrawLine(pencil, x, y + height, x + width, y + height);
	g->DrawLine(pencil, x + width, y + height, x, y);
	*/
}

string CTriangulo::getNombre()
{
	return "Triangulo";
}
