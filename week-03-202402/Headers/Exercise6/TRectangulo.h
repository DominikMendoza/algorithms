#pragma once
#include "iostream"

using namespace System;
using namespace std;

class TRectangulo
{
private:
	int lado1;
	//int lado2;
	char caracter;

public:
	//TRectangulo(char caracter, int lado1, int lado2);
	TRectangulo(char caracter, int lado1);
	void DibujarRectangulo(int posX, int posY);
	void RealizarProcedimientoTR();
};

TRectangulo::TRectangulo(char caracter, int lado1)
{
	this->lado1 = lado1;
	this->caracter = caracter;
}

//TRectangulo::TRectangulo(char caracter, int lado1, int lado2)
//{
//	this->lado1 = lado1;
//	this->lado2 = lado2;
//	this->caracter = caracter;
//}

void TRectangulo::DibujarRectangulo(int posX, int posY)
{
	Console::SetCursorPosition(posX, posY); cout << caracter;
	_sleep(100);
}

void TRectangulo::RealizarProcedimientoTR()
{
	int posinicialarriba = 0;
	int posX = 1;
	int posY = posinicialarriba;

	Console::SetCursorPosition(posX, posY);
	for (int i = 0; i < lado1; i++)
	{
		DibujarRectangulo(posX, posY);
		posX += 2;
		posY += 1;
	}
	for (int i = 0; i < lado1; i++)
	{
		if (i == 0)
		{
			DibujarRectangulo(posX, posY); 
		}
		posX -= 2;
		DibujarRectangulo(posX, posY);
	}
	for (int i = 0; i < lado1; i++) 
	{
		posY -= 1;
		DibujarRectangulo(posX, posY);
	}
}