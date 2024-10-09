#pragma once
#include "Terrestre.h"

class Carro : public Terrestre
{
private:
	int color;

public:
	Carro(float x, float y);
	void Mover() override;
	void Dibujar() override;
};

Carro::Carro(float x, float y) : Terrestre(11, 3)
{
	this->x = x;
	this->y = y;
	dx = 1;
	dy = 0;
	velocidad = RandFloat(2.2, 3.2);
	color = 6;
}

void Carro::Mover()
{
	if (x > ANCHO_CONSOLA - ancho)
	{
		x = 0;
	}
	x += dx * velocidad;
	y += dy * velocidad;
}

void Carro::Dibujar()
{
	Console::ForegroundColor = ConsoleColor(color);
	Console::SetCursorPosition(x, y);
	cout << " ____|~\\_ ";
	Console::SetCursorPosition(x, y + 1);
	cout << "[____|_|-";
	Console::SetCursorPosition(x, y + 2);
	cout << "(_) (_)";
	Console::ResetColor();
}