#pragma once
#include <iostream>
#define WIDTH 80
#define HEIGHT 40
using namespace System;
using namespace std;

class Movil
{
protected:
	int x, y, dx, dy;
	int ancho, alto;
	bool visible;
public:
	Movil(int x, int y);
	~Movil();
	void borrar();
	virtual void mover();
	virtual void dibujar();
	void animar();
	bool intersectar(Movil* obj);
	int getX();
	int getY();
	void setVisible(bool visible);
};

Movil::Movil(int x, int y)
{
	this->x = x;
	this->y = y;
	dx = 0;
	dy = 0;
	ancho = 0;
	alto = 0;
	visible = 1;
}

Movil::~Movil()
{
}

void Movil::borrar()
{
	for (int i = 0; i < ancho; i++)
	{
		for (int j = 0; j < alto; j++)
		{
			Console::SetCursorPosition(x + i, y + j);
			cout << " ";
		}
	}
}

void Movil::mover()
{
}

void Movil::dibujar()
{
}

void Movil::animar()
{
	if (!visible) return;
	borrar();
	mover();
	dibujar();
}

bool Movil::intersectar(Movil* obj)
{
	return (x < obj->x + obj->ancho && obj->x < x + ancho &&
		y < obj->y + obj->alto && obj->y < y + alto);
}

int Movil::getX()
{
	return this->x;
}

int Movil::getY()
{
	return this->y;
}

void Movil::setVisible(bool visible)
{
	this->visible = visible;
}
