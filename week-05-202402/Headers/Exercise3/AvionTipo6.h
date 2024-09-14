#pragma once
#include "Avion.h"

class AvionTipo6 : public Avion
{
private:
	int color;
	void calcularIncrementos(float x1, float y1, float x2, float y2);
	int fase;

public:
	AvionTipo6();
	void Dibujar() override;
	void Mover() override;
};

AvionTipo6::AvionTipo6() : Avion(2.5, 18, 4)
{
	x = ANCHO_CONSOLA - ancho;
	y = ALTO_CONSOLA - alto;
	color = 12;
	calcularIncrementos(x, y, 0, 0);
	fase = 0;
}

void AvionTipo6::calcularIncrementos(float x1, float y1, float x2, float y2)
{
	float difX = x2 - x1;
	float difY = y2 - y1;
	float steps = max(abs(difX), abs(difY));
	dx = difX / steps;
	dy = difY / steps;
}

void AvionTipo6::Dibujar()
{
	Console::ForegroundColor = ConsoleColor(color);
	Console::SetCursorPosition(x, y);
	cout << "        .";
	Console::SetCursorPosition(x, y + 1);
	cout << "._______|_______.";
	Console::SetCursorPosition(x, y + 2);
	cout << "      \\(*)/";
	Console::SetCursorPosition(x, y + 3);
	cout << "      o/ \\o";
	Console::ResetColor();
}

void AvionTipo6::Mover()
{
	x += dx * velocidad;
	y += dy * velocidad;
	if (fase == 0 && x <= 0 && y <= 0)
	{
		fase = 1;
		calcularIncrementos(x, y, 0, ALTO_CONSOLA - alto);
	}
	else if (fase == 1 && y + alto >= ALTO_CONSOLA)
	{
		fase = 2;
		calcularIncrementos(x, y, ANCHO_CONSOLA - ancho, 0);
	}
	else if (fase == 2 && x + ancho >= ANCHO_CONSOLA && y <= 0)
	{
		movimiento = false;
	}
}