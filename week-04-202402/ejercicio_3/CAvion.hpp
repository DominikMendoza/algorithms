#pragma once
// el objeto compuesto maneja posicion y dimensiones
#include "CAlas.hpp"
#include "CFuselaje.hpp"
#include "CTrenAterrizaje.hpp"
#define WIDTH 80
#define HEIGHT 40
using namespace System;

class CAvion
{
private:
	int x, y, dx, dy;
	int ancho, alto;
	CAlas* alas;
	CFuselaje* fuselaje;
	CTrenAterrizaje* trenAterrizaje;
public:
	CAvion(int x, int y);
	~CAvion();
	void borrar();
	void mover();
	void dibujar();
	void animar();
};

CAvion::CAvion(int x, int y)
{
	this->x = x;
	this->y = y;
	this->dx = 0;
	this->dy = 1;
	this->alto = 3;
	this->ancho = 10;
	this->alas = new CAlas();
	this->fuselaje = new CFuselaje();
	this->trenAterrizaje = new CTrenAterrizaje();
}

CAvion::~CAvion()
{
}

void CAvion::borrar()
{
	Console::SetCursorPosition(x, y);
	alas->borrar();
	Console::SetCursorPosition(x, y + 1);
	fuselaje->borrar();
	Console::SetCursorPosition(x, y + 2);
	trenAterrizaje->borrar();
}

void CAvion::mover()
{
	do
	{
		dx = rand() % 3 - 1;
	} while (x + dx < 0 || x + dx + ancho > WIDTH);

	if (y + alto == HEIGHT) {
		dy = 0;
		dx = 0;
	}
	x += dx;
	y += dy;
}

void CAvion::dibujar()
{
	Console::SetCursorPosition(x, y);
	alas->dibujar();
	Console::SetCursorPosition(x, y + 1);
	fuselaje->dibujar();
	Console::SetCursorPosition(x, y + 2);
	trenAterrizaje->dibujar();
}

void CAvion::animar()
{
	borrar();
	mover();
	dibujar();
}
