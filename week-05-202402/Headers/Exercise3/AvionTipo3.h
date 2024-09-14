#pragma once
#include "Avion.h"

class AvionTipo3 : public Avion
{
private:
	int color;
	void calcularIncrementos(float x1, float y1, float x2, float y2);

public:
	AvionTipo3();
	void Dibujar() override;
	void Mover() override;
};

AvionTipo3::AvionTipo3() : Avion(1.3, 20, 3)
{
	x = ANCHO_CONSOLA - ancho;
	calcularIncrementos(x, y, 0, ALTO_CONSOLA - alto);
	color = 6;
}

void AvionTipo3::calcularIncrementos(float x1, float y1, float x2, float y2)
{
	float difX = x2 - x1;
	float difY = y2 - y1;
	float steps = max(abs(difX), abs(difY));
	dx = difX / steps;
	dy = difY / steps;
}

void AvionTipo3::Dibujar()
{
	Console::ForegroundColor = ConsoleColor(color);
	Console::SetCursorPosition(x, y);
	cout << "       __|__";
	Console::SetCursorPosition(x, y + 1);
	cout << "________(*)________";
	Console::SetCursorPosition(x, y + 2);
	cout << "       o/ \\o";
	Console::ResetColor();
}

void AvionTipo3::Mover()
{
	x += dx * velocidad;
	y += dy * velocidad;
	if (y + alto >= ALTO_CONSOLA || x <= 0)
	{
		movimiento = false;
	}
}