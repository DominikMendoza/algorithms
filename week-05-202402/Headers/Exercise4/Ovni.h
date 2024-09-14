#pragma once
#include "iostream"
#include "string"
#include "conio.h"
#include "vector"
#define ANCHO_CONSOLA 140
#define ALTO_CONSOLA 40

using namespace std;
using namespace System;

class Ovni
{
protected:
	float x;
	float y;
	float dy;
	float velocidad;
	int ancho;
	int alto;

public:
	Ovni(float velocidad, int ancho, int alto);
	void Borrar();
	bool Mover();
};

Ovni::Ovni(float velocidad, int ancho, int alto)
{
	this->ancho = ancho;
	this->alto = alto;
	this->velocidad = velocidad;
	dy = 1;
	x = 0;
	y = 0;
}

void Ovni::Borrar()
{
	for (int i = 0; i < ancho; i++)
	{
		for (int j = 0; j < alto; j++)
		{
			Console::SetCursorPosition(static_cast<int>(x) + i, static_cast<int>(y) + j); cout << " ";
		}
	}
}

bool Ovni::Mover()
{
	y += dy * velocidad;
	if (y + alto > ALTO_CONSOLA)
	{
		Borrar();
		return true;  
	}
	return false;
}