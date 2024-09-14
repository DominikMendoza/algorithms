#pragma once
#include "Ovni.h"

class Beta : public Ovni
{
private:
	int color;

public:
	Beta();
	void DibujarBeta();
};

Beta::Beta() : Ovni(2.5, 11, 3)
{
	x = ANCHO_CONSOLA / 2 - ancho / 2;
	color = 12;
}

void Beta::DibujarBeta()
{
	Console::ForegroundColor = ConsoleColor(color);
	Console::SetCursorPosition(x, y);
	cout << "  .---.";
	Console::SetCursorPosition(x, y + 1);
	cout << "_/__~0_\\_";
	Console::SetCursorPosition(x, y + 2);
	cout << "(_________)";
	Console::ResetColor();
}