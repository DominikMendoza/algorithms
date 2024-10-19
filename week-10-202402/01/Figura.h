#pragma once
#include "iostream"

using namespace System;
using namespace System::Drawing;

class Figura
{
protected:
	int x, y;
	int rval = rand() % 256;
	int gval = rand() % 256;
	int bval = rand() % 256;
	int dx,dy;
public:
	Figura();
	~Figura();
	virtual void dibujar(Graphics^ g) = 0;
	virtual void mover(Graphics^ g) = 0;
	int getR() { return rval; }
	int getG() { return gval; }
	int getB() { return bval; }
};