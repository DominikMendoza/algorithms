#pragma once
#include "COvni.hpp"
class COBeta : public COvni
{
private:

public:
	COBeta(int x, int y);
	~COBeta();
	void dibujar();
};

COBeta::COBeta(int x, int y) : COvni(x, y, 11, 3)
{
}

COBeta::~COBeta()
{
}

void COBeta::dibujar()
{
	//if (!visible) return;
	Console::ForegroundColor = ConsoleColor::White;
	System::Console::SetCursorPosition(this->x, this->y);
	cout << "   .---.";
	System::Console::SetCursorPosition(this->x, this->y + 1);
	cout << " _/__~0_\\_";
	System::Console::SetCursorPosition(this->x, this->y + 2);
	cout << "(_________)";
}
