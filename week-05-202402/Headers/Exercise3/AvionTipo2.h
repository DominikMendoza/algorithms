#pragma once
#include "Avion.h"

class AvionTipo2 : public Avion
{
private:
	int color;
	void calcularIncrementos(float x1, float y1, float x2, float y2);

public:
	AvionTipo2();
	void Dibujar() override;
	void Mover() override;
};

AvionTipo2::AvionTipo2() : Avion(0.9, 18, 3)
{
	color = 4;
	calcularIncrementos(x, y, ANCHO_CONSOLA - ancho, ALTO_CONSOLA - alto);
}

void AvionTipo2::calcularIncrementos(float x1, float y1, float x2, float y2)
{
	float difX = x2 - x1;
	float difY = y2 - y1;
	float steps = max(abs(difX), abs(difY));
	dx = difX / steps;
	dy = difY / steps;
}

void AvionTipo2::Dibujar()
{
	Console::ForegroundColor = ConsoleColor(color);
	Console::SetCursorPosition(x, y);
	cout << "________|________";
	Console::SetCursorPosition(x, y + 1);
	cout << " _|_____0_____|_";
	Console::SetCursorPosition(x, y + 2);
	cout << "      |   |";
	Console::ResetColor();
}

void AvionTipo2::Mover()
{
	x += dx * velocidad;
	y += dy * velocidad;
	if (y + alto >= ALTO_CONSOLA || x + ancho >= ANCHO_CONSOLA)
	{
		movimiento = false;
	}
}