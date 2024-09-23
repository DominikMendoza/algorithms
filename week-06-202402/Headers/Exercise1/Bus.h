#pragma once
#include "Terrestre.h"

class Bus : public Terrestre
{
private: 
	int color;

public:
	Bus(float x, float y);
	void Mover() override;
	void Dibujar() override;
};

Bus::Bus(float x, float y) : Terrestre(20, 4)
{
	this->x = x;
	this->y = y;
	dx = -1;
	dy = 0;
	velocidad = RandFloat(3.3, 4.3);
	color = 11;
}

void Bus::Mover()
{
	if (x < 1) 
	{
		x = ANCHO_CONSOLA - ancho; 
	}
	x += dx * velocidad;
	y += dy * velocidad;
}

void Bus::Dibujar()
{
	Console::ForegroundColor = ConsoleColor(color);
	Console::SetCursorPosition(x, y);
	cout << "   ____________";
	Console::SetCursorPosition(x, y + 1);
	cout << "_/_|[][][][][][][]|";
	Console::SetCursorPosition(x, y + 2);
	cout << " (                |";
	Console::SetCursorPosition(x, y + 3);
	cout << "=--OO          OO-=";
	Console::ResetColor();
}