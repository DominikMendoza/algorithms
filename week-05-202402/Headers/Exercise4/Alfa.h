#pragma once
#include "Ovni.h"

class Alfa : public Ovni
{
private:
	int color;

public:
	Alfa();
	void DibujarAlfa();
};

Alfa::Alfa() : Ovni(1.5, 19, 5)
{
	color = 14;
}

void Alfa::DibujarAlfa()
{
	Console::ForegroundColor = ConsoleColor(color);
	Console::SetCursorPosition(x, y);
	cout << "      _.---._";
	Console::SetCursorPosition(x, y + 1);
	cout << "       .' '.";
	Console::SetCursorPosition(x, y + 2);
	cout << "_.-~===========~-._";
	Console::SetCursorPosition(x, y + 3);
	cout << "(_________________)";
	Console::SetCursorPosition(x, y + 4);
	cout << "     \\_______/";
	Console::ResetColor();
}