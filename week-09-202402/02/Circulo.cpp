#include "Circulo.h"

CCirculo::CCirculo(int _x = 0, int _y = ((rand()%80+70)), int _dx = 1, int _dy = 0, int _color = 1, bool _Visible = 1, double _radio = 80) :CFigura(_x, _y, _dx, _dy, _color, _Visible), radio(_radio) {}

CCirculo::~CCirculo(){}

void CCirculo::Borrar(Graphics^ G)
{
	G->DrawEllipse(Pens::White, getRectangle());
}

void CCirculo::Mover(Graphics^ G)
{
	if (x+dX<0 || x+(radio*2)+ dX>G->VisibleClipBounds.Width) { dX *= -1; }
	x += dX;
}

void CCirculo::Dibujar(Graphics^ G)
{
	G->DrawEllipse(Pens::Black, getRectangle());
}

double CCirculo::getDiametro()
{
	return (radio*2);
}

void CCirculo::setVisible(bool V)
{
	Visible = V;
}

bool CCirculo::isVisible()
{
	return Visible;
}

Rectangle CCirculo::getRectangle()
{
	return Rectangle(x, y, radio * 2, radio * 2);
}
