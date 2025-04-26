#pragma once
#include <iostream>
using namespace System;
using namespace std;

class Llanta
{
private:
public:
	Llanta();
	~Llanta();
	void borrar(int x, int y);
	void dibujar(int x, int y);
};

Llanta::Llanta()
{
}

Llanta::~Llanta()
{
}

void Llanta::borrar(int x, int y)
{
	Console::SetCursorPosition(x, y);
	cout << " ";
}

void Llanta::dibujar(int x, int y)
{
	Console::SetCursorPosition(x, y);
	cout << char(219);
}
