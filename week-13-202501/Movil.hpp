#pragma once
#include <iostream>
using namespace std;
using namespace System;
using namespace System::Drawing;

class Movil
{
protected:
	int x, y, width, height;
	int dx, dy;
	int idx, idy;
	float zoom;
public:
	Movil(int width, int height);
	~Movil();
	void dibujar(Graphics^ g, Bitmap^ bmp);
	virtual void mover(Graphics^ g, char tecla) = 0;
	Rectangle getRectangle();
	bool estaColisionandoCon(Movil* obj);
};

Movil::Movil(int width, int height)
{
	x = y = dx = dy = idx = idy = 0;
	zoom = 1.0;
	this->width = width;
	this->height = height;
}

Movil::~Movil()
{
}

void Movil::dibujar(Graphics^ g, Bitmap^ bmp)
{
	Rectangle section = Rectangle(idx * width, idy * height, width, height);
	Rectangle zoom = Rectangle(x, y, width * this->zoom, height * this->zoom);
	g->DrawImage(bmp, zoom, section, GraphicsUnit::Pixel);
}

Rectangle Movil::getRectangle()
{
	return Rectangle(x, y, width * zoom, height * zoom);
}

bool Movil::estaColisionandoCon(Movil* obj)
{
	return obj->getRectangle().IntersectsWith(this->getRectangle());
}
