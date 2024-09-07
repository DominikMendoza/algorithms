#pragma once
#include <iostream>
#define WIDTH 80
#define HEIGHT 40
using namespace System;
using namespace std;

class CCuadrado
{
private:
	int x, y, dx, dy;
	int color;
public:
	CCuadrado(int x, int y, int dx, int dy);
	~CCuadrado();
	void borrar();
	void mover();
	void dibujar();
	void animar();
	void cambiarColor();
	CCuadrado* obtenerPosicionAnterior();

};

CCuadrado::CCuadrado(int x, int y, int dx, int dy)
	:x(x), y(y), dx(dx), dy(dy)
{
	color = rand() % 15 + 1;
}

CCuadrado::~CCuadrado()
{
}

void CCuadrado::borrar()
{
	Console::SetCursorPosition(x, y);
	cout << " ";
}

void CCuadrado::mover()
{
	if (x == WIDTH - 1 && y == 0) {
		dx = 0;
		dy = 1;
	}
	if (x == WIDTH - 1 && y == HEIGHT - 1) {
		dx = -1;
		dy = 0;
	}
	if (x == 0 && y == HEIGHT - 1) {
		dx = 0;
		dy = -1;
	}
	if (x == 0 && y == 0) {
		dx = 1;
		dy = 0;
	}
	x += dx;
	y += dy;
}

void CCuadrado::dibujar()
{
	Console::SetCursorPosition(x, y);
	Console::ForegroundColor = ConsoleColor(color);
	cout << char(219);
}

void CCuadrado::animar()
{
	borrar();
	mover();
	dibujar();
}

void CCuadrado::cambiarColor()
{
	this->color = rand() % 15 + 1;
}

CCuadrado* CCuadrado::obtenerPosicionAnterior()
{
	return new CCuadrado(x - dx, y - dy, dx, dy);
}
