#pragma once
#include <iostream>

using namespace std;
using namespace System::Drawing;

class Bomba
{
private:
	int x, y, width, height;
	int idx, idy;
	float zoom;
public:
	Bomba(int x, int y, int width, int height, float zoom);
	~Bomba();
	void draw(Graphics^ g, Bitmap^ bmp);
	void mover();
	Rectangle getHitbox();
	void actualizarCoordenadas(Graphics^ g);
};

Bomba::Bomba(int x, int y, int width, int height, float zoom)
{
	this->x = x;
	this->y = y;
	idx = idy = 0;
	this->width = width;
	this->height = height;
	this->zoom = zoom;
}

Bomba::~Bomba()
{
}

void Bomba::draw(Graphics^ g, Bitmap^ bmp)
{
	Rectangle section = Rectangle(idx * width, idy * height, width, height);
	Rectangle zoom = Rectangle(x, y, width * this->zoom, height * this->zoom);
	g->DrawImage(bmp, zoom, section, GraphicsUnit::Pixel);
}

void Bomba::mover()
{
	idx++;
	if (idx > 2) {
		idx = 0;
	}
}

Rectangle Bomba::getHitbox()
{
	return Rectangle(x, y, width * zoom, height * zoom);
}

void Bomba::actualizarCoordenadas(Graphics^ g)
{
	int limDerecha = g->VisibleClipBounds.Width - (width * zoom);
	int limAbajo = g->VisibleClipBounds.Height - (height * zoom);
	x = rand() % limDerecha;
	y = rand() % limAbajo;
}
