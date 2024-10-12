#pragma once
#include <iostream>
using namespace System::Drawing;
class CFigura
{
protected:
	int x, y;
	int color;
	int desplazamiento;
	bool visible;
public:
	CFigura(int x, int y, int color, int desplazamiento);
	~CFigura();
	virtual void dibujar(Graphics^ g);
	virtual void mover(Graphics^ g);
	int getX();
	int getY();
	void setVisible(bool visible);
	bool isVisible();
	virtual Rectangle* getRectangle();
};

CFigura::CFigura(int x, int y, int color, int desplazamiento)
	: x(x), y(y), color(color), desplazamiento(desplazamiento)
{
	visible = true;
}

CFigura::~CFigura()
{
}

void CFigura::dibujar(Graphics^ g)
{
}

void CFigura::mover(Graphics^ g)
{
}

int CFigura::getX()
{
	return this->x;
}

int CFigura::getY()
{
	return this->y;
}

void CFigura::setVisible(bool visible)
{
	this->visible = visible;
}

bool CFigura::isVisible()
{
	return this->visible;
}

Rectangle* CFigura::getRectangle()
{
	return nullptr;
}
