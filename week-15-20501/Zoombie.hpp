#pragma once
#include "Bloque.hpp"
class Zoombie : public Movil
{
private:
	int vidas;
public:
	Zoombie(int x, int y, int width, int height, int vidas);
	~Zoombie();
	void mover(Graphics^ g, char tecla) override;
	bool puedeMoverse(Graphics^ g, char tecla, vector<Bloque*>& bloques);
	Rectangle getRectangleAfterMove(char tecla);
	void disminuirVidas();
	int getVidas();
};

Zoombie::Zoombie(int x, int y, int width, int height, int vidas) : Movil(width, height)
{
	this->x = x;
	this->y = y;
	this->vidas = vidas;
	zoom = 0.7;
	dx = dy = 5;
}

Zoombie::~Zoombie()
{
}

void Zoombie::mover(Graphics^ g, char tecla)
{
	switch (tecla)
	{
	case 'S': {
		if (y + dy + height * zoom > g->VisibleClipBounds.Height) return;
		y += dy;
		idy = 0;
		break;
	}
	case 'A': {
		if (x - dx < 0) return;
		x -= dx;
		idy = 1;
		break;
	}
	case 'D': {
		if (x + dx + width * zoom > g->VisibleClipBounds.Width) return;
		x += dx;
		idy = 2;
		break;
	}
	case 'W': {
		if (y - dy < 0) return;
		y -= dy;
		idy = 3;
		break;
	}
	}
	idx++;
	if (idx > 3) {
		idx = 0;
	}
}

bool Zoombie::puedeMoverse(Graphics^ g, char tecla, vector<Bloque*>& bloques)
{
	Rectangle nextPosition = getRectangleAfterMove(tecla);

	if (nextPosition.X < 0 || nextPosition.Y < 0 ||
		nextPosition.Right > g->VisibleClipBounds.Width || nextPosition.Bottom > g->VisibleClipBounds.Height) {
		return false;
	}

	for (int i = 0; i < bloques.size(); i++) {
		if (bloques[i]->getRectangle().IntersectsWith(nextPosition)) {
			return false;
		}
	}

	return true;
}

Rectangle Zoombie::getRectangleAfterMove(char tecla)
{
	int nextX = x, nextY = y;

	switch (tecla) {
	case 'W': nextY -= dy; break;
	case 'S': nextY += dy; break;
	case 'A': nextX -= dx; break;
	case 'D': nextX += dx; break;
	}

	return Rectangle(nextX, nextY, width * zoom, height * zoom);
}

void Zoombie::disminuirVidas()
{
	this->vidas--;
}

int Zoombie::getVidas()
{
	return this->vidas;
}
