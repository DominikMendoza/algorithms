#include "Rectangulo.h"

CRectangulo::CRectangulo(int _x, int _y, double _base, double _altura):CFigura(_x,_y),base(_base), altura(_altura){}

CRectangulo::~CRectangulo(){}

void CRectangulo::Dibujar(Graphics^ G)
{
	G->DrawRectangle(Pens::Peru,getRectangle());
}

Rectangle CRectangulo::getRectangle()
{
	return Rectangle(x,y,base*2,altura*2);
}
