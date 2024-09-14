#pragma once
#include "Avion.h"

class AvionTipo9 : public Avion
{
private:
	int color;
	float fase;
	float yInicial;

public:
	AvionTipo9();
	void Dibujar() override;
	void Mover() override;
};

AvionTipo9::AvionTipo9() : Avion(3.7, 17, 4)
{
	x = ANCHO_CONSOLA - ancho;
	y = RandInt(0, ALTO_CONSOLA - alto + 1);
	yInicial = y;
	dx = -1;
	color = 7;
	fase = 0;
}

void AvionTipo9::Dibujar()
{
	Console::ForegroundColor = ConsoleColor(color);
	Console::SetCursorPosition(x, y);
	cout << "    ____        ";
	Console::SetCursorPosition(x, y + 1);
	cout << "| __\\_\\_o____/_|";
	Console::SetCursorPosition(x, y + 2);
	cout << "<[___\\_\\_-----<";
	Console::SetCursorPosition(x, y + 3);
	cout << "|";
	Console::ResetColor();
}

void AvionTipo9::Mover()
{
	x += dx * velocidad;
	y = yInicial + sin(fase) * 5;
	fase += 0.5;
	if (x <= 0)
	{
		x = 0;
		movimiento = false;
	}
	if (y < 0)
	{
		y = 0;
	}
	if (y + alto > ALTO_CONSOLA)
	{
		y = ALTO_CONSOLA - alto;
	}
}