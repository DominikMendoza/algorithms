#pragma once
#include <iostream>
#define WIDTH 80
#define HEIGHT 40
using namespace System;
using namespace std;

class COvni
{
protected:
	int x, y, dx, dy, ancho, alto;
	bool visible;
public:
	COvni(int x, int y, int ancho, int alto);
	~COvni();
	void borrar();
	void mover();
	virtual void dibujar();
	void animar();
	void mostrarDatos();
	bool isVisible();
};

COvni::COvni(int x, int y, int ancho, int alto)
{
	this->x = x;
	this->y = y;
	this->ancho = ancho;
	this->alto = alto;
	this->dx = 0;
	this->dy = 1;
	this->visible = true;
}

COvni::~COvni()
{
}

void COvni::borrar()
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

void COvni::mover()
{
	if (y + dy + alto > HEIGHT) {
		dy = 0;
		this->visible = false;
	}
	x += dx;
	y += dy;
}

void COvni::dibujar()
{
}

void COvni::animar()
{
	borrar();
	mover();
	dibujar();
}

void COvni::mostrarDatos()
{
	cout << "x: " << x << endl;
	cout << "y: " << y << endl;
	cout << "ancho: " << ancho << endl;
	cout << "alto: " << alto << endl;
}

bool COvni::isVisible()
{
	return this->visible;
}
