#pragma once
#include "CMovil.hpp"
class CRaton : public CMovil
{
private:

public:
	CRaton(float x, float y);
	~CRaton();
	void mover(CMovil* ext);
};

CRaton::CRaton(float x, float y) : CMovil(x, y, 'R')
{
	dx = 1;
	dy = 1;
}

CRaton::~CRaton()
{
}

void CRaton::mover(CMovil* ext)
{
	if (this->distancia(ext) <= DIST) {
		dx = (ext->getX() < this->x ? 1 : -1);
		dy = (ext->getY() < this->y ? 1 : -1);
	}
	if (x + dx < 0 || x + dx >= WIDTH) {
		dx *= -1;
	}
	if (y + dy < 0 || y + dy >= HEIGHT) {
		dy *= -1;
	}
	x += dx;
	y += dy;
}
