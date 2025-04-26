#pragma once
#include <iostream>
using namespace System;
using namespace std;

class Chasis
{
private:
public:
	Chasis();
	~Chasis();
	void borrar(int x, int y);
	void dibujar(int x, int y);
};

Chasis::Chasis()
{
}

Chasis::~Chasis()
{
}

void Chasis::borrar(int x, int y)
{
	Console::SetCursorPosition(x, y);
	for (int i = 0; i < 5; i++)
	{
		cout << " ";
	}
}

void Chasis::dibujar(int x, int y)
{
	Console::SetCursorPosition(x, y);
	for (int i = 0; i < 5; i++)
	{
		cout << char(220);
	}
}
