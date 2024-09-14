#pragma once
#include "Chasis.h"
#include "Llanta.h"
#include "Utilidades.h"

class Carro
{
private:
	float x;
	float y;
	float dx;
	float velocidad;
	int color;
	int ancho;
	int alto;
	Llanta** llantas;
	Chasis* chasis;
	int numllantas;

public:
	Carro(float x, float y, int color);
	~Carro();
	void Borrar();
	void Mover();
	void Dibujar();
	bool LlegoMeta();
};

Carro::Carro(float x, float y, int color)
{
	this->x = x;
	this->y = y;
	this->color = color;
	dx = 1;
	ancho = 5;
	alto = 3;
	velocidad = RandFloat(0.1, 1);
	numllantas = 4;
	chasis = new Chasis(x, y + 1, ancho);
	llantas = new Llanta * [numllantas];
	llantas[0] = new Llanta(x, y);
	llantas[1] = new Llanta(x, y + 2);
	llantas[2] = new Llanta(x + 2, y);
	llantas[3] = new Llanta(x + 2, y + 2);
}

Carro::~Carro()
{
	delete chasis;
	for (int i = 0; i < numllantas; i++)
	{
		delete llantas[i];
	}
	delete[] llantas;
}

void Carro::Borrar()
{
	chasis->BorrarChasis();
	for (int i = 0; i < numllantas; i++)
	{
		llantas[i]->BorrarLlanta();
	}
}

void Carro::Mover()
{
	x += dx * velocidad;
	chasis->MoverChasis(velocidad);
	for (int i = 0; i < numllantas; i++)
	{
		llantas[i]->MoverLlanta(velocidad);
	}
}

void Carro::Dibujar()
{
	Console::ForegroundColor = ConsoleColor(color);
	chasis->DibujarChasis();
	for (int i = 0; i < numllantas; i++)
	{
		llantas[i]->DibujarLlanta();
	}
	Console::ResetColor();
}

bool Carro::LlegoMeta()
{
	return x + ancho >= ANCHO_CONSOLA;
}
