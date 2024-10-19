#pragma once
#include <iostream>
#include <string>
using namespace std;
using namespace System::Drawing;
class CFigura
{
protected:
	float x, y, dx;
	float width, height;
public:
	CFigura(float x, float y, float dx);
	~CFigura();
	void mover(Graphics^ g);
	virtual void dibujar(Graphics^ g);
	float getXAncho();
	void resetar();
	virtual string getNombre();
};

CFigura::CFigura(float x, float y, float dx)
	:x(x), y(y), dx(dx)
{

	this->width = this->height = 30;
}

CFigura::~CFigura()
{
}

void CFigura::mover(Graphics^ g)
{
	if (x + dx + this->width >= g->VisibleClipBounds.Width) {
		dx = 0;
	}
	x += dx;
}

void CFigura::dibujar(Graphics^ g)
{
	Pen^ pencil = gcnew Pen(Color::Blue, 8);
	g->DrawEllipse(pencil, x, y, width, height);
	//g->DrawRectangle(pencil, x, y, width, height);
}

float CFigura::getXAncho()
{
	return this->x + this->width;
}

void CFigura::resetar()
{
	this->x = 0;
	this->dx = rand() % 15 + 5;
}

string CFigura::getNombre()
{
	return "Nombre raro";
}
