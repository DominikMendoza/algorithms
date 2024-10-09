#include "Elipse.h"

CElipse::CElipse(int _x, int _y, double _semiejeA, double _semiejeB):CFigura(_x, _y),semiejeA(_semiejeA),semiejeB(_semiejeB){}

CElipse::~CElipse(){}

void CElipse::Dibujar(Graphics^ G)
{
	G->DrawEllipse(Pens::Blue, getRectangle());
}

Rectangle CElipse::getRectangle()
{
	return Rectangle(x,y,semiejeA*2, semiejeB * 2);
}
