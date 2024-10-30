#pragma once
#include "iostream"

using namespace System::Drawing;

enum Tecla
{
	Espacio, Izquierda, Derecha, Ninguno
};

class Mario
{
private:
	int x;
	int y;
	int dx;
	int dy;
	int fila;
	int columna;
	int ancho;
	int alto;
	int alturaInicial;
	Tecla tecla;
	bool enElAire;
 	const int velocidadSalto = -35;
	const int gravedad = 7;

public:
	Mario();
	void DibujarMario(Graphics^ g, Bitmap^ img);
	void MoverMario(int& scrollX);
	void setTecla(Tecla tecla);
	bool isEnElAire();
};

Mario::Mario()
{
	x = 12;
	y = 468;
	dx = 0;
	dy = 0;
	fila = 0;
	columna = 0;
	tecla = Ninguno;
	enElAire = false;
}

void Mario::DibujarMario(Graphics^ g, Bitmap^ img)
{
	ancho = img->Width / 4;
	alto = img->Height / 4;
	Rectangle frame = Rectangle(ancho * columna, alto * fila, ancho, alto);
	Rectangle zoom = Rectangle(x, y, ancho, alto);
	g->DrawImage(img, zoom, frame, GraphicsUnit::Pixel);
}

void Mario::MoverMario(int& scrollX)
{
	int limiteIzquierdo = 0;
	int limiteDerecho = 575; //Calculo del ancho del background al inicio para el scroll
	if (!enElAire)
	{
		switch (tecla)
		{
		case Derecha:
			dx = 10; dy = 0; fila = 2; columna++; if (columna > 3) columna = 0;
			break;
		case Izquierda:
			dx = -10; dy = 0; fila = 1; columna++; if (columna > 3) columna = 0;
			break;
		case Espacio:
			if (y == 468) dy = -35;
			break;
		case Ninguno:
			dx = 0;
			break;
		}
	}
	else
	{
		dx = 0;
	}
	if (tecla == Espacio && !enElAire) 
	{ 
		dy = velocidadSalto; 
		enElAire = true; 
		alturaInicial = y; 
	}
	if (enElAire) 
	{
		dy += gravedad; 
		y += dy; 
		if (y >= 468) 
		{ 
			y = 468; 
			dy = 0;
			enElAire = false; 
		}
	}
	//Scroll
	if (x <= limiteIzquierdo && dx < 0) 
	{
		x = limiteIzquierdo;
		if (scrollX > 0) scrollX += dx;  
	}
	else if (x >= limiteDerecho && dx > 0)
	{
		x = limiteDerecho;
		scrollX += dx; 
	}
	else 
	{
		x += dx;  
	}
}

void Mario::setTecla(Tecla tecla)
{
	this->tecla = tecla;
}

bool Mario::isEnElAire()
{
	return enElAire;
}