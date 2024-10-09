#include "Circulo.h"

CCirculo::CCirculo(int _x, int _y, double _radio) : CFigura(_x, _y), radio(_radio) {}

CCirculo::~CCirculo() {}

Rectangle CCirculo::getRectangle()
{
    return Rectangle(x, y, radio * 2, radio*2);
}

void CCirculo::Dibujar(Graphics^ G)
{
    G->DrawEllipse(Pens::Black, getRectangle());
}


