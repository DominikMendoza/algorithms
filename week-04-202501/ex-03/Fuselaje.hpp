#pragma once
#include <iostream>
using namespace System;
using namespace std;

class Fuselaje
{
private:
public:
	Fuselaje();
	~Fuselaje();
	void borrar(int x, int y);
	void dibujar(int x, int y);
};

Fuselaje::Fuselaje()
{
}

Fuselaje::~Fuselaje()
{
}

void Fuselaje::borrar(int x, int y)
{
	Console::SetCursorPosition(x, y);
	cout << "         ";
}

void Fuselaje::dibujar(int x, int y)
{
	Console::SetCursorPosition(x, y);
	cout << "---oOo---";
}
