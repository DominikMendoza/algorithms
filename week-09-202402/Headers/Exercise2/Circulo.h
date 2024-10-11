#pragma once
#include "iostream"

using namespace std;
using namespace System::Drawing;

ref class Circulo
{
private:
	int x;
	int y;
	double diametro;
	Color color;
	int dx;
	bool visible;

public:
	Circulo(int x, int y, double diametro, Color color);
	void DibujarCirculo(Graphics^ g);
	void MoverCirculo();
	int getX();
	int getY();
	double getDiametro();
	void setVisible(bool visible);
	bool isVisible();
	Rectangle mascara();
};

Circulo::Circulo(int x, int y, double diametro, Color color)
{
	this->x = x;
	this->y = y;
	this->diametro = diametro;
	this->color = color;
	dx = 5;
	visible = true;
}

void Circulo::DibujarCirculo(Graphics^ g)
{
	if (visible)
	{
		SolidBrush^ brocha = gcnew SolidBrush(color);
		g->FillEllipse(brocha, x, y, diametro, diametro);
	}
}

void Circulo::MoverCirculo()
{
	x += dx;
}

int Circulo::getX()
{
	return x;
}

int Circulo::getY()
{
	return y;
}

double Circulo::getDiametro()
{
	return diametro;
}

void Circulo::setVisible(bool visible)
{
	this->visible = visible;
}

bool Circulo::isVisible()
{
	return visible;
}

Rectangle Circulo::mascara()
{
	return Rectangle(x, y, diametro, diametro);
}