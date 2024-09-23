#pragma once
#include "Utilidades.h"

class Persona
{
private:
    float x;
    float y;
    float dx;
    float dy;
    int alto;
    int ancho;
    int color;
	char forma;

public:
	Persona(float x, float y);
	void Borrar();
	void Mover();
	void Dibujar();
	float getX();
	float getY();
	int getAncho();
	int getAlto();
};

Persona::Persona(float x, float y)
{
	this->x = x;
	this->y = y;
	dx = 1;
	dy = 1;
	ancho = 1;
	alto = 1;
	color = 10;
	forma = 254;
}

void Persona::Borrar()
{
	for (int i = 0; i < alto; i++) 
	{
		Console::SetCursorPosition(x, y + i);
		for (int j = 0; j < ancho; j++) 
		{
			cout << " ";
		}
	}
}

void Persona::Mover()
{
	char tecla;
	if (_kbhit())
	{
		tecla = _getch();
		switch (tecla)
		{
		case 72: //Arriba
			if (y >= 1) 
			{
				y -= dy;
			}
			break;
		case 75: //Izquierda
			if (x > 1) 
			{
				x -= dx;
			}
			break;
		case 77: //Derecha
			if (x + ancho < ANCHO_CONSOLA) 
			{
				x += dx;
			}
			break;
		case 80: //Abajo
			if (y + alto < ALTO_CONSOLA)
			{
				y += dy;
			}
			break;
		}
	}
}

void Persona::Dibujar()
{
	Console::ForegroundColor = ConsoleColor(color);
	Console::SetCursorPosition(x, y); cout << forma;
	Console::ResetColor();
}

float Persona::getX()
{
	return x;
}

float Persona::getY()
{
	return y;
}

int Persona::getAlto()
{
	return alto;
}

int Persona::getAncho()
{
	return ancho;
}