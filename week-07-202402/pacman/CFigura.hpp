#pragma once
#include <iostream>
#include <conio.h>
#define WIDTH 80
#define HEIGHT 40
using namespace System;
using namespace std;

class CFigura
{
protected:
	float x, y, dx, dy;
	int ancho, alto;
public:
	CFigura(int x, int y, int ancho, int alto);
	~CFigura();
	void borrar();
	virtual void mover();
	virtual void dibujar();
	void animar();
	bool instersectar(CFigura* f);
};

CFigura::CFigura(int x, int y, int ancho, int alto)
{
	this->x = x;
	this->y = y;
	this->ancho = ancho;
	this->alto = alto;
}

CFigura::~CFigura()
{
}

void CFigura::borrar()
{
	for (int i = 0; i < ancho; i++)
	{
		for (int j = 0; j < alto; j++)
		{
			Console::SetCursorPosition(x + i, y + j);
			cout << ' ';
		}
	}
}

void CFigura::mover()
{
}

void CFigura::dibujar()
{
}

void CFigura::animar()
{
	borrar();
	mover();
	dibujar();
}

bool CFigura::instersectar(CFigura* f)
{
	return (x <= f->x + f->ancho && f->x <= x + ancho &&
		y <= f->y + f->alto && f->y <= y + alto);
}
