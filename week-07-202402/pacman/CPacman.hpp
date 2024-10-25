#include "CFigura.hpp"
class CPacman : public CFigura
{
private:
	int vidas;
public:
	CPacman(int x, int y);
	~CPacman();
	void mover() override;
	void dibujar() override;
	void disminuirVida(int hp);
	void aumentarVida(int hp);
};

CPacman::CPacman(int x, int y) : CFigura(x, y, 7, 5)
{
	this->dx = 0;
	this->dy = 0;
}

CPacman::~CPacman()
{
}

void CPacman::mover()
{
	if (kbhit()) {
		char tecla = getch();
		tecla = toupper(tecla);
		switch (tecla)
		{
		case 'W': dx = 0; dy = -1; break;
		case 'S': dx = 0; dy = 1; break;
		case 'A': dx = -1; dy = 0; break;
		case 'D': dx = 1; dy = 0; break;
		}
	}
	if (x + dx < 0 || x + dx + ancho >= WIDTH) {
		dx = 0;
	}
	if (y + dy < 0 || y + dy + alto >= HEIGHT) {
		dy = 0;
	}
	x += dx;
	y += dy;
}

void CPacman::dibujar()
{
	Console::ForegroundColor = ConsoleColor::Yellow;
	Console::SetCursorPosition(x, y);
	cout << "  -- ";
	Console::SetCursorPosition(x, y + 1);
	cout << " / o \\";
	Console::SetCursorPosition(x, y + 2);
	cout << "(     )";
	Console::SetCursorPosition(x, y + 3);
	cout << " \\   /";
	Console::SetCursorPosition(x, y + 4);
	cout << "  -- ";
	Console::ResetColor();
}

void CPacman::disminuirVida(int hp)
{
	this->vidas -= hp;
}

void CPacman::aumentarVida(int hp)
{
	this->vidas += hp;
}
