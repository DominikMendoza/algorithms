#pragma once
#include "Utilidades.h"

class Llanta
{
private:
	float x;
	float y;
	float dx;
	char forma;

public:
	Llanta(int x, int y);
	void BorrarLlanta();
	void DibujarLlanta();
	void MoverLlanta(float velocidad);
};

Llanta::Llanta(int x, int y)
{
	this->x = x;
	this->y = y;
	forma = 220; //Deberia ser 219 pero lo cambie para que se vea mejor
	dx = 1;
}

void Llanta::BorrarLlanta() 
{
	Cursor(x, y); cout << " ";
}

void Llanta::DibujarLlanta()
{
	Cursor(x, y); cout << forma;
}

void Llanta::MoverLlanta(float velocidad)
{
	x += dx * velocidad;
}
