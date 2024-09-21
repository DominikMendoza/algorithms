#pragma once
#include "Avion.h"

class AvionTipo4 : public Avion
{
private:
	int color;

public:
	AvionTipo4();
	void Dibujar() override;
	void Mover() override;
};

AvionTipo4::AvionTipo4() : Avion(1.8, 14, 3)
{
	dy = 1;
	dx = 1;
	color = 8;
}

void AvionTipo4::Dibujar()
{
	Console::ForegroundColor = ConsoleColor(color);
	Console::SetCursorPosition(x, y);
	cout << "    __!__";
	Console::SetCursorPosition(x, y + 1);
	cout << "_____(_)_____";
	Console::SetCursorPosition(x, y + 2);
	cout << "   !  !  !";
	Console::ResetColor();
}

void AvionTipo4::Mover()
{
	x += dx * velocidad;
	y += dy * velocidad;
	if (y + alto >= ALTO_CONSOLA || y < 0)
	{
		dy *= -1;
	}
	if (x + ancho >= ANCHO_CONSOLA)
	{
		movimiento = false;
	}
}