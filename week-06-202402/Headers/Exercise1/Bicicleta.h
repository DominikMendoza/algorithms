#pragma once
#include "Terrestre.h"

class Bicicleta : public Terrestre
{
private: 
	int color;

public:
	Bicicleta(float x, float y);
	void Mover() override;
	void Dibujar() override;
};

Bicicleta::Bicicleta(float x, float y) : Terrestre(7, 2)
{
	this->x = x;
	this->y = y;
	dx = 1;
	dy = 0;
	velocidad = RandFloat(1.1, 2.1);
	color = 3;
}

void Bicicleta::Mover()
{
	if (x < 1 || x > ANCHO_CONSOLA - ancho) 
	{
		dx *= -1;
	}
	x += dx * velocidad;
	y += dy * velocidad;
}

void Bicicleta::Dibujar()
{
	Console::ForegroundColor = ConsoleColor(color);
	if (dx == 1) 
	{
		Console::SetCursorPosition(x, y);
		cout << ".._\\";
		Console::SetCursorPosition(x, y + 1);
		cout << "(o)(o)";
	}
	else if (dx == -1)
	{
		Console::SetCursorPosition(x, y);
		cout << "/_..";
		Console::SetCursorPosition(x, y + 1);
		cout << "(o)(o)";
	}
	Console::ResetColor();
}