#include "CFigura.hpp"

class CFantasma : public CFigura
{
private:
	int color;
public:
	CFantasma(int x, int y);
	~CFantasma();
	void mover() override;
	void dibujar() override;
};

CFantasma::CFantasma(int x, int y) : CFigura(x, y, 7, 6)
{
	this->color = 11 + rand() % 2;
	if (rand() % 2) {
		this->dx = (rand() % 2) ? 1 : -1;
		this->dy = 0;
	}
	else {
		this->dy = (rand() % 2) ? 1 : -1;
		this->dx = 0;
	}
}

CFantasma::~CFantasma()
{
}

void CFantasma::mover()
{
	if (x + dx < 0 || x + dx + ancho >= WIDTH) {
		dx *= -1;
	}
	if (y + dy < 0 || y + dy + alto >= HEIGHT) {
		dy *= -1;
	}
	x += dx;
	y += dy;
}

void CFantasma::dibujar()
{
	Console::ForegroundColor = ConsoleColor(color);
	Console::SetCursorPosition(x, y);
	cout << " ____ ";
	Console::SetCursorPosition(x, y + 1);
	cout << "| o o |";
	Console::SetCursorPosition(x, y + 2);
	cout << "|  ^  |";
	Console::SetCursorPosition(x, y + 3);
	cout << "| ----|";
	Console::SetCursorPosition(x, y + 4);
	cout << "|     |";
	Console::SetCursorPosition(x, y + 5);
	cout << "|_____|";
	Console::ResetColor();
}
