#pragma once
#include "COvni.hpp"
class COAlfa : public COvni
{
private:

public:
	COAlfa(int x, int y);
	~COAlfa();
	void dibujar();
};

COAlfa::COAlfa(int x, int y) : COvni(x, y, 19, 5)
{
}

COAlfa::~COAlfa()
{
}

void COAlfa::dibujar()
{
	//if (!visible) return;
	Console::ForegroundColor = ConsoleColor::Yellow;
	System::Console::SetCursorPosition(this->x, this->y);
	cout << "      _.---._";
	System::Console::SetCursorPosition(this->x, this->y + 1);
	cout << "       .' '.";
	System::Console::SetCursorPosition(this->x, this->y + 2);
	cout << "_.-~===========~-._";
	System::Console::SetCursorPosition(this->x, this->y + 3);
	cout << "(_________________)";
	System::Console::SetCursorPosition(this->x, this->y + 4);
	cout << "     \\_______/";
}
