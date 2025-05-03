#pragma once
#include <iostream>
#define WIDTH 80
#define HEIGHT 40
using namespace std;
using namespace System;
class Ovni
{
protected:
	int x, y, dx, dy;
	int alto, ancho;
	bool visible;
public:
	Ovni(int x, int ancho, int alto);
	~Ovni();
	void borrar();
	void mover();
	virtual void dibujar();
	void animar();
};

Ovni::Ovni(int x, int ancho, int alto)
{
	this->x = x;
	this->ancho = ancho;
	this->alto = alto;
	this->y = 0;
	this->visible = 1;
	this->dy = 1;
}

Ovni::~Ovni()
{
}

void Ovni::borrar()
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

void Ovni::mover()
{
	dx = rand() % 3 - 1;
	if (x + dx < 0 || x + ancho + dx >= WIDTH) {
		dx = 0;
	}

	if (y + alto + dy > HEIGHT) {
		dy = 0;
		this->visible = 0;
	}

	if (dy == 0) dx = 0;
	x += dx;
	y += dy;
}

void Ovni::dibujar()
{
}

void Ovni::animar()
{
	borrar();
	mover();
	if (visible) {
		dibujar();
	}
}
