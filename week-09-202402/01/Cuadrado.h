#pragma once
#include "Figuras.h"

class CCuadrado:public CFigura
{
private:
	double lado1;
public:
	CCuadrado(double,int,int);
	~CCuadrado();

	void Dibujar(Graphics^ G) override;
	Rectangle getRectangle();
};


