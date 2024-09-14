#pragma once
#include "Avion.h"

class AvionTipo8 : public Avion
{
private:
	int color;
	int pasoActual;
	int numPasos;

public:
	AvionTipo8();
	void Dibujar() override;
	void Mover() override;
};

AvionTipo8::AvionTipo8() : Avion(2.5, 18, 2)
{
	x = RandInt(0, ANCHO_CONSOLA - ancho + 1);
	dx = 1;
	dy = 1;
	color = 1;
	pasoActual = 0;
	numPasos = 1;
}

void AvionTipo8::Dibujar()
{
	Console::ForegroundColor = ConsoleColor(color);
	Console::SetCursorPosition(x, y);
	cout << "      \\ . /";
	Console::SetCursorPosition(x, y + 1);
	cout << ".______(*)______.";
	Console::ResetColor();
}

void AvionTipo8::Mover()
{
	x += dx * velocidad;
	y += dy * velocidad;
	if (y + alto >= ALTO_CONSOLA)
	{
		movimiento = false;
	}
	if (x + ancho >= ANCHO_CONSOLA)
	{
		x = ANCHO_CONSOLA - ancho;
		dx *= -1;
	}
	else if (x <= 0)
	{
		x = 0;
		dx *= -1;
	}
	pasoActual++;
	if (pasoActual == numPasos)
	{
		dx *= -1;
		pasoActual = 0;
	}
}