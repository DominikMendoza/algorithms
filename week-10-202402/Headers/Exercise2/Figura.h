#pragma once
#include "Utilidades.h"

enum class TipoFigura { Cuadrado, Circulo, Triangulo };

ref class Figura
{
protected:
	float x;
	float y;
	float dx;
	float velocidad;
	Color color;
	TipoFigura tipo;
	
public:
	Figura(float x, float y, float dx, float velocidad, Color color, TipoFigura tipo);
	void Mover();
	virtual void Dibujar(Graphics^ g);
	float getX();
	float getY();
	TipoFigura getTipoFigura();
};

Figura::Figura(float x, float y, float dx, float velocidad, Color color, TipoFigura tipo)
{
	this->x = x;
	this->y = y;
	this->dx = dx;
	this->color = color;
	this->velocidad = velocidad;
	this->tipo = tipo;
}

void Figura::Mover()
{
	x += dx * velocidad;
}

void Figura::Dibujar(Graphics^ g){}

float Figura::getX()
{
	return x;
}

float Figura::getY()
{
	return y;
}

TipoFigura Figura::getTipoFigura()
{
	return tipo;
}