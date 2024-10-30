#pragma once
#include "iostream"

using namespace System::Drawing;

enum Tecla
{
	Derecha, Izquierda, Arriba, Abajo, Ninguno
};

class Hulk
{
private:
	int x;
	int y;
	int dx;
	int dy;
	int alto;
	int ancho;
	int fila;
	int columna;
	Tecla tecla;

public:
	Hulk();
	void DibujarHulk(Graphics^ g, Bitmap^ imgHulk);
	void MoverHulk(Graphics^ g);
	void setTecla(Tecla tecla);
	int getX();
	int getY();
};

Hulk::Hulk()
{
	x = 450;
	y = 200;
	dx = 0;
	dy = 0;
	fila = 0;
	columna = 0;
	tecla = Ninguno;
}

void Hulk::DibujarHulk(Graphics^ g, Bitmap^ img)
{
	ancho = img->Width / 4;
	alto = img->Height / 4;
	Rectangle frame = Rectangle(ancho * columna, alto * fila, ancho, alto);
	Rectangle zoom = Rectangle(x, y, ancho * 2, alto * 2);
	g->DrawImage(img, zoom, frame, GraphicsUnit::Pixel);
}

void Hulk::MoverHulk(Graphics^ g)
{
	switch (tecla)
	{
	case Arriba:
		dx = 0; dy = -1; fila = 3; columna++; if (columna > 3) columna = 0;
		break;
	case Abajo:
		dx = 0; dy = 1; fila = 0; columna++; if (columna > 3) columna = 0;
		break;
	case Derecha:
		dx = 1; dy = 0; fila = 2; columna++; if (columna > 3) columna = 0;
		break;
	case Izquierda:
		dx = -1; dy = 0; fila = 1; columna++; if (columna > 3) columna = 0;
		break;
	case Ninguno:
		dx = 0; dy = 0; fila = 0; columna = 0;
		break;
	}
	if (x < 0 || x + ancho + 10 >= g->VisibleClipBounds.Width || y < 0 || y + alto + 20 >= g->VisibleClipBounds.Height)
	{
		x = 450;
		y = 200;
	}
	x += dx;
	y += dy;
}

void Hulk::setTecla(Tecla tecla)
{
	this->tecla = tecla;
}

int Hulk::getX()
{
	return x;
}

int Hulk::getY()
{
	return y;
}