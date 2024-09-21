#pragma once
#include "CMovil.hpp"
class CGato : public CMovil
{
private:

public:
	CGato(float x, float y);
	~CGato();
	void mover(CMovil* ext);
};

CGato::CGato(float x, float y) : CMovil(x, y, 'G')
{
}

CGato::~CGato()
{
}

void CGato::mover(CMovil* ext)
{
	if (kbhit()) {
		char tecla = _getch();
		switch (tecla)
		{
		case UP: dy = -1; dx = 0; break;
		case DOWN: dy = 1; dx = 0; break;
		case RIGHT: dy = 0; dx = 1; break;
		case LEFT: dy = 0; dx = -1; break;
		}
	}
	if (x + dx < 0 || x + dx >= WIDTH) {
		dx = 0;
	}
	if (y + dy < 0 || y + dy >= HEIGHT) {
		dy = 0;
	}
	x += dx;
	y += dy;
	dx = dy = 0;
}
