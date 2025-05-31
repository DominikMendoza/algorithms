#pragma once
#include <iostream>
using namespace System::Drawing;
using namespace std;

class Figura
{
protected:
	int x, y;
	int lado1, lado2;
public:
	Figura(int x, int y, int lado1, int lado2);
	~Figura();
	virtual void dibujar(Graphics^ g) = 0;
	virtual double getArea() = 0;
};

Figura::Figura(int x, int y, int lado1, int lado2)
{
	this->x = x;
	this->y = y;
	this->lado1 = lado1;
	this->lado2 = lado2;
}

Figura::~Figura()
{
}