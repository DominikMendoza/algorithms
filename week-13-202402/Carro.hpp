#pragma once
#include <iostream>
using namespace System::Drawing;

class Carro
{
private:
	int x, y, dx;
	int idx, idy;
	int width, height;
public:
	Carro(int width, int height);
	~Carro();
	void move(Graphics^ g);
	void changeAnimation(int opc);
	void draw(Graphics^ g, Bitmap^ bmp);

};

Carro::Carro(int width, int height)
{
	x = y = 100;
	dx = 5;
	idx = idy = 0;
	this->width = width;
	this->height = height;
}

Carro::~Carro()
{
}

void Carro::move(Graphics^ g)
{
	idx++;
	if (idx >= 5) {
		idx = 0;
		idy = 0;
	}
}

void Carro::changeAnimation(int opc)
{
	idy = opc;
	idx = 0;
}

void Carro::draw(Graphics^ g, Bitmap^ bmp)
{
	Rectangle sectionShow = Rectangle(idx * width, idy * height, width, height);
	Rectangle sectionForm = Rectangle(x, y, width, height);
	g->DrawImage(bmp, sectionForm, sectionShow, GraphicsUnit::Pixel);
}
