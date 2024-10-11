#pragma once
#include "iostream"

using namespace std;
using namespace System::Drawing;

ref class Triangulo
{
private:
	int x;
	int y;
	int lado;
	Color color;
	int dy;
	bool visible;

public:
	Triangulo(int x, int y, int lado, Color color);
	void DibujarTriangulo(Graphics^ g);
	void MoverTriangulo();
	int getX();
	int getY();
	int getLado();
	void setVisible(bool visible);
	bool isVisible();
	Rectangle mascara();
};

Triangulo::Triangulo(int x, int y, int lado, Color color)
{
	this->x = x;
	this->y = y;
	this->lado = lado;
	this->color = color;
	dy = 5;
	visible = true;
} 

void Triangulo::DibujarTriangulo(Graphics^ g)
{
	if (visible)
	{
		cli::array<System::Drawing::Point>^ puntos = gcnew cli::array<System::Drawing::Point>(3)
		{
				System::Drawing::Point(x, y),
				System::Drawing::Point(x + lado, y),
				System::Drawing::Point(x + (lado / 2), y - (lado * sqrt(3) / 2))
		};

		SolidBrush^ brocha = gcnew SolidBrush(color);
		g->FillPolygon(brocha, puntos);
	}
}

void Triangulo::MoverTriangulo()
{
	y += dy;
}

int Triangulo::getX()
{
	return x;
}

int Triangulo::getY()
{
	return y;
}

int Triangulo::getLado()
{
	return lado;
}

void Triangulo::setVisible(bool visible)
{
	this->visible = visible;
}

bool Triangulo::isVisible()
{
	return visible;
}

Rectangle Triangulo::mascara()
{
	int altura = (lado * sqrt(3) / 2);
	return Rectangle(x, y - altura, lado, altura); 
}