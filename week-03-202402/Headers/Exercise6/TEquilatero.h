#pragma once
#include "iostream"

using namespace System;
using namespace std;

class TEquilatero
{
private:
	char caracter;
	int lado;

public:
	TEquilatero(char caracter, int lado);
	void DibujarEquilatero(int posX, int posY);
	void RealizarProcedimientoTE();
};

TEquilatero::TEquilatero(char caracter, int lado)
{
	this->caracter = caracter;
	this->lado = lado;
}

void TEquilatero::DibujarEquilatero(int posX, int posY)
{
	Console::SetCursorPosition(posX, posY); cout << caracter;
	_sleep(100);
}

void TEquilatero::RealizarProcedimientoTE()
{
	int posinicialarriba = 6;
	int posX = 1;
	int posY = lado + posinicialarriba;
	Console::SetCursorPosition(posX, posY);
	for (int i = 0; i < lado; i++)
	{
		DibujarEquilatero(posX, posY);
		posY -= 1;
		posX += 1;
		Console::SetCursorPosition(posX, posY);
		if (posY == posinicialarriba) 
		{
			DibujarEquilatero(posX, posY);
		}
	}
	for (int i = 0; i < lado; i++)
	{
		posY += 1;
		posX += 1;
		DibujarEquilatero(posX, posY);
	}
	for (int i = 0; i < lado; i++)
	{
		posX -= 2; 
		DibujarEquilatero(posX, posY);
	}
}