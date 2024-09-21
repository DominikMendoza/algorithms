#pragma once
#include "Ovni.h"

class Gamma : public Ovni
{
private:
	int color;

public:
	Gamma();
	void DibujarGamma();
};

Gamma::Gamma() : Ovni(3.5, 19, 10)
{
	x = ANCHO_CONSOLA - ancho;
	color = 11;
}

void Gamma::DibujarGamma()
{
	Console::ForegroundColor = ConsoleColor(color);
	Console::SetCursorPosition(x, y);
	cout << "         .";
	Console::SetCursorPosition(x, y + 1);
	cout << "         |";
	Console::SetCursorPosition(x, y + 2);
	cout << "      .-\" ^ \"-.";
	Console::SetCursorPosition(x, y + 3);
	cout << "     /_....._\\";
	Console::SetCursorPosition(x, y + 4);
	cout << " .-\"`         `\"-.";
	Console::SetCursorPosition(x, y + 5);
	cout << "(  ooo  ooo  ooo  )";
	Console::SetCursorPosition(x, y + 6);
	cout << " '-.,_________,.-'";
	Console::SetCursorPosition(x, y + 7);
	cout << "     /       \\";
	Console::SetCursorPosition(x, y + 8);
	cout << "   _/         \\_";
	Console::SetCursorPosition(x, y + 9);
	cout << "  `\"`         `\"`";
	Console::ResetColor();
}