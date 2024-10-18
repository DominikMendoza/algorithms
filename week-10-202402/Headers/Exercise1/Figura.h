#pragma once
#include "Utilidades.h"

ref class Figura
{
protected:
	int x;
	int y;
	int dx;
	int dy;
	Color color;

public:
	Figura(int x, int y, int dx, int dy, Color color);
	virtual void Mover(Graphics^ g);
	virtual void Dibujar(Graphics^ g);
	int getX();
	int getY();
};

Figura::Figura(int x, int y, int dx, int dy, Color color)
{
	this->x = x;
	this->y = y;
	this->dx = dx;
	this->dy = dy;
	this->color = color;
}

void Figura::Mover(Graphics^ g){}

void Figura::Dibujar(Graphics^ g){}

int Figura::getX()
{
	return x;
}

int Figura::getY()
{
	return y;
}