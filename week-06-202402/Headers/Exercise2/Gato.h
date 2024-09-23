#pragma once
#include "Entidad.h"

class Gato : public Entidad
{
private:
	int color;

public:
	Gato(float x, float y);
	void Mover() override;
	void Dibujar() override;
};

Gato::Gato(float x, float y) : Entidad(8, 3)
{
	this->x = x;
	this->y = y;
	dx = 1;
	dy = 1;
	velocidad = 1.2;
	color = 14;
}

void Gato::Mover()
{
	char tecla;
	if (_kbhit())
	{
		tecla = toupper(_getch());
		switch (tecla)
		{
		case 'W': //Arriba
			if (y > 1)
			{
				y -= dy * velocidad;
			}
			break;
		case 'A': //Izquierda
			if (x > 1)
			{
				x -= dx * velocidad;
			}
			break;
		case 'D': //Derecha
			if (x + ancho < ANCHO_CONSOLA)
			{
				x += dx * velocidad;
			}
			break;
		case 'S': //Abajo
			if (y + alto < ALTO_CONSOLA - 8)
			{
				y += dy * velocidad;
			}
			break;
		}
	}
}

void Gato::Dibujar()
{
	Console::ForegroundColor = ConsoleColor(color);
	Console::SetCursorPosition(x, y);
	cout << " /\\_/\\";
	Console::SetCursorPosition(x, y + 1);
	cout << "( o.o )";
	Console::SetCursorPosition(x, y + 2);
	cout << " > ^ <";
	Console::ResetColor();
}