#include "Triangulo.h"

CTriangulo::CTriangulo(int _x, int _y, int _dx, int _dy, int _color, bool _Visible, double _lado):CFigura(_x, _y, _dx, _dy, _color, _Visible), lado(_lado){}

CTriangulo::~CTriangulo(){}

void CTriangulo::Borrar(Graphics^ G)
{
	G->DrawEllipse(Pens::White, getRectangle());
}

void CTriangulo::Mover(Graphics^ G)
{
	if (y + dY<0 || y  + dY>G->VisibleClipBounds.Height) { dY *= -1; }
	y += dY;
}

void CTriangulo::Dibujar(Graphics^ G)
{
	int x2 = x + lado;
	int y2 = y;
	int x3 = x + lado / 2;
	int y3 = y - (int)(lado * sqrt(3) / 2);
	G->DrawLine(Pens::Peru, x, y, x2, y2);
	G->DrawLine(Pens::Peru, x2, y2, x3, y3);
	G->DrawLine(Pens::Peru, x3, y3, x, y);
	//G->DrawEllipse(Pens::Peru, getRectangle());
}

double CTriangulo::getLado()
{
	return lado;
}

void CTriangulo::setVisible(bool V)
{
	Visible = V;
}

bool CTriangulo::isVisible()
{
	return Visible;
}

Rectangle CTriangulo::getRectangle()
{
	return Rectangle(x, y, lado * 2, lado * 2);
}
