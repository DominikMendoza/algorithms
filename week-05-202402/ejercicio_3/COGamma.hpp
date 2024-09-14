#pragma once
#include "COvni.hpp"
class COGamma : public COvni
{
private:

public:
	COGamma(int x, int y);
	~COGamma();
	void dibujar();
};

COGamma::COGamma(int x, int y) : COvni(x, y, 19, 10)
{
}

COGamma::~COGamma()
{
}

void COGamma::dibujar()
{
	//if (!visible) return;
	Console::ForegroundColor = ConsoleColor::Green;
	System::Console::SetCursorPosition(x, y);
	std::cout << "         .";
	System::Console::SetCursorPosition(x, y + 1);
	std::cout << "         |";
	System::Console::SetCursorPosition(x, y + 2);
	std::cout << "      .-\" ^ \"-.";
	System::Console::SetCursorPosition(x, y + 3);
	std::cout << "     /_....._\\";
	System::Console::SetCursorPosition(x, y + 4);
	std::cout << " .-\"`         `\"-.";
	System::Console::SetCursorPosition(x, y + 5);
	std::cout << "(  ooo  ooo  ooo  )";
	System::Console::SetCursorPosition(x, y + 6);
	std::cout << " '-.,_________,.-'";
	System::Console::SetCursorPosition(x, y + 7);
	std::cout << "     /       \\";
	System::Console::SetCursorPosition(x, y + 8);
	std::cout << "   _/         \\_";
	System::Console::SetCursorPosition(x, y + 9);
	std::cout << "  `\"`         `\"`";
}
