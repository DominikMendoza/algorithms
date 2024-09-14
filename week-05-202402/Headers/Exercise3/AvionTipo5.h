#pragma once
#include "Avion.h"

class AvionTipo5 : public Avion
{
private:
	int color;
	int fase;
	void calcularIncrementos(float x1, float y1, float x2, float y2);

public:
	AvionTipo5();
	void Dibujar() override;
	void Mover() override;
};

AvionTipo5::AvionTipo5() : Avion(2.2, 16, 3)
{
	dx = 1;
	color = 10;
	fase = 0;
}

void AvionTipo5::Dibujar()
{
	Console::ForegroundColor = ConsoleColor(color);
	Console::SetCursorPosition(x, y);
	cout << "     __!__";
	Console::SetCursorPosition(x, y + 1);
	cout << "-----< * >-----";
	Console::SetCursorPosition(x, y + 2);
	cout << "    o  O  o";
	Console::ResetColor();
}

void AvionTipo5::calcularIncrementos(float x1, float y1, float x2, float y2)
{
	float difX = x2 - x1;
	float difY = y2 - y1;
	float steps = max(abs(difX), abs(difY));
	dx = difX / steps;
	dy = difY / steps;
}

void AvionTipo5::Mover()
{
	x += dx * velocidad;
	y += dy * velocidad;
	if (fase == 0 && x + ancho >= ANCHO_CONSOLA)
	{
		x = ANCHO_CONSOLA - ancho;
		fase = 1;
		calcularIncrementos(x, y, 0, ALTO_CONSOLA - alto);
	}
	else if (fase == 1 && x <= 0 && y + alto >= ALTO_CONSOLA)
	{
		x = 0;
		y = ALTO_CONSOLA - alto;
		fase = 2;
		calcularIncrementos(x, y, ANCHO_CONSOLA - ancho, ALTO_CONSOLA - alto);
	}
	else if (fase == 2 && x + ancho >= ANCHO_CONSOLA)
	{
		x = ANCHO_CONSOLA - ancho;
		movimiento = false;
	}
}