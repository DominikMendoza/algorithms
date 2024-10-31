#pragma once
#include "Utilidades.h"

enum Tecla
{
	Arriba, Abajo, Izquierda, Derecha, Ninguno
};

class Soldado
{
private:
	int x;
	int y;
	int dx;
	int dy;
	int fila;
	int columna;
	int alto;
	int ancho;
	int vidas;
	Tecla tecla;

public:
	Soldado();
	void DibujarSoldado(Graphics^ g, Bitmap^ img);
	void MoverSoldado(Graphics^ g);
	void setTecla(Tecla tecla);
	int getVidas();
	Rectangle mascara();
	void BajarVida();
	void SubirVida();
};

Soldado::Soldado()
{
	x = 500;
	y = 450;
	dx = 0;
	dy = 0;
	fila = 0;
	columna = 0;
	vidas = 3;
	tecla = Ninguno;
}

void Soldado::DibujarSoldado(Graphics^ g, Bitmap^ img)
{
	ancho = img->Width / 3;
	alto = img->Height / 4;
	Rectangle frame = Rectangle(ancho * columna, alto * fila, ancho, alto);
	Rectangle zoom = Rectangle(x, y, ancho, alto);
	g->DrawImage(img, zoom, frame, GraphicsUnit::Pixel);
}

void Soldado::MoverSoldado(Graphics^ g)
{
	switch (tecla)
	{
	case Arriba:
		dx = 0; dy = -6; fila = 3; columna++; if (columna > 2) columna = 0;
		break;
	case Abajo:
		dx = 0; dy = 6; fila = 0; columna++; if (columna > 2) columna = 0;
		break;
	case Izquierda:
		dx = -6; dy = 0; fila = 1; columna++; if (columna > 2) columna = 0;
		break;
	case Derecha:
		dx = 6; dy = 0; fila = 2; columna++; if (columna > 2) columna = 0;
		break;
	case Ninguno:
		dx = 0; dy = 0; columna = 0; fila = 0;
		break;
	}
	if (x < 0)
	{
		x = 0;
	}
	if (y < 0)
	{
		y = 0;
	}
	if (x >= g->VisibleClipBounds.Width - ancho)
	{
		x = g->VisibleClipBounds.Width - ancho;
	}
	if (y >= g->VisibleClipBounds.Height - alto)
	{
		y = g->VisibleClipBounds.Height - alto;
	}
	x += dx;
	y += dy;
}

void Soldado::setTecla(Tecla tecla)
{
	this->tecla = tecla;
}

int Soldado::getVidas()
{
	return vidas;
}

Rectangle Soldado::mascara()
{
	return Rectangle(x, y, ancho, alto);
}

void Soldado::BajarVida()
{
	vidas--;
}

void Soldado::SubirVida()
{
	vidas++;
}