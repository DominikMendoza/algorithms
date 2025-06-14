#pragma once
#include <iostream>

using namespace std;
using namespace System::Drawing;

class Hulk
{
private:
	int x, y, width, height;
	int dx, dy;
	int idx, idy;
	float zoom;
public:
	Hulk(int width, int height, float zoom);
	~Hulk();
	void draw(Graphics^ g, Bitmap^ bmp);
	void mover(Graphics^ g, char tecla);
};

Hulk::Hulk(int width, int height, float zoom)
{
	x = y = 100;
	dx = dy = 5;
	idx = 3;
	idy = 1;
	this->width = width;
	this->height = height;
	this->zoom = zoom;
}

Hulk::~Hulk()
{
}

void Hulk::draw(Graphics^ g, Bitmap^ bmp)
{
	Rectangle section = Rectangle(idx * width, idy * height, width, height);
	Rectangle zoom = Rectangle(x, y, width * this->zoom, height * this->zoom);
	g->DrawImage(bmp, zoom, section, GraphicsUnit::Pixel);
}

void Hulk::mover(Graphics^ g, char tecla)
{
	switch (tecla)
	{
		case 'W': {
			if (y - dy < 0) return;
			idy = 3;
			y -= dy;
			break;
		}
		case 'A': {
			if (x - dx < 0) return;
			idy = 1;
			x -= dx;
			break;
		}
		case 'S': {
			if (y + height * zoom + dy > g->VisibleClipBounds.Height) return;
			idy = 0;
			y += dy;
			break;
		}
		case 'D': {
			if (x + width * zoom  + dx > g->VisibleClipBounds.Width) return;
			idy = 2;
			x += dx;
			break;
		}
	}
	idx++;
	if (idx > 3) idx = 0;
}
