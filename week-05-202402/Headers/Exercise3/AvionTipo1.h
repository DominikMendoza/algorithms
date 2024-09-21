#pragma once
#include "Avion.h"

class AvionTipo1 : public Avion
{
private:
	int color;
	int pasoActual;
	int numPasos;

public:
	AvionTipo1();
	void Dibujar() override;
	void Mover() override;
};

AvionTipo1::AvionTipo1() : Avion(0.6, 13, 3)
{
	x = RandInt(0, ANCHO_CONSOLA - ancho + 1);
	dx = 1;
	dy = 1;
	color = 3;
	numPasos = 20;
	pasoActual = 0;
}

void AvionTipo1::Dibujar() 
{
	Console::ForegroundColor = ConsoleColor(color);
	Console::SetCursorPosition(x, y);
	cout << " -----------";
	Console::SetCursorPosition(x, y + 1);
	cout << " _\\__(_)__/_";
	Console::SetCursorPosition(x, y + 2);
	cout << "    ./ \\.";
	Console::ResetColor();
}

void AvionTipo1::Mover()
{
	x += dx * velocidad;
	y += dy * velocidad;
	if (y + alto >= ALTO_CONSOLA)
	{
		movimiento = false;
	}
	if (x + ancho >= ANCHO_CONSOLA)  
	{
		x = ANCHO_CONSOLA - ancho;   
		dx *= -1;                    
	}
	else if (x <= 0)                 
	{
		x = 0;                       
		dx *= -1;                    
	}
	pasoActual++;
	if (pasoActual == numPasos)
	{
		dx *= -1;
		pasoActual = 0;
	}
}