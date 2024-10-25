#pragma once
#include "iostream"

using namespace System;
using namespace System::Drawing;

class Figura
{
protected:
	int x, y;
	int dx;
	float velocidad;
public:
	Figura(int x, int y);
	~Figura();
	virtual void dibujar(Graphics^ g) = 0;
	virtual void mover(Graphics^ g) = 0;

	int getX() { return x; }
};