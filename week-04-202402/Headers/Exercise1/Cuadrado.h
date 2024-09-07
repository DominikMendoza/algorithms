#pragma once
#include "Utilidades.h"

class Cuadrado
{
private:
	int x;
	int y;
	int dx;
	int dy;
	int color;
	int alto;
	int ancho;
	char forma;

public:
	Cuadrado();
	void Borrar();
	void Mover();
	void Dibujar();
	void CambiarColor();
};

Cuadrado::Cuadrado()
{
	x = 0;
	y = 0;
	dx = 1;
	dy = 0;
	color = RandInt(1, 15);
	alto = 2;
	ancho = 2;
	forma = 219;
}

void Cuadrado::Borrar()
{
	for (int i = 0; i < ancho; i++)
	{
		for (int j = 0; j < alto; j++)
		{
			Console::SetCursorPosition(x + i, y + j); cout << " ";
		}
	}
}

void Cuadrado::Dibujar()
{
	Console::ForegroundColor = ConsoleColor(color);
	for (int i = 0; i < ancho; i++)
	{
		for (int j = 0; j < alto; j++)
		{
			Console::SetCursorPosition(x + i, y + j); cout << forma;
		}
	}
	Console::ResetColor();
}

void Cuadrado::Mover()
{
	x += dx;
	y += dy;
	if (x + ancho >= ANCHO_PANTALLA && y == 0)
	{
		dx = 0;
		dy = 1;
	}
	else if (x + ancho >= ANCHO_PANTALLA && y + alto >= ALTO_PANTALLA)
	{
		dx = -1;
		dy = 0;
	}
	else if (x == 0 && y + alto >= ALTO_PANTALLA)
	{
		dx = 0;
		dy = -1;
	}
	else if (x == 0 && y == 0)
	{
		dx = 1;
		dy = 0;
	}
}

void Cuadrado::CambiarColor()
{
	color = RandInt(1, 15);
}