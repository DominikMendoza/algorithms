#pragma once
#include <iostream>
using namespace System;
using namespace std;

class TrenDeAterrizaje
{
private:
public:
	TrenDeAterrizaje();
	~TrenDeAterrizaje();
	void borrar(int x, int y);
	void dibujar(int x, int y);
};

TrenDeAterrizaje::TrenDeAterrizaje()
{
}

TrenDeAterrizaje::~TrenDeAterrizaje()
{
}

void TrenDeAterrizaje::borrar(int x, int y)
{
	Console::SetCursorPosition(x, y);
	cout << " ";
	Console::SetCursorPosition(x, y + 1);
	cout << " ";
}

void TrenDeAterrizaje::dibujar(int x, int y)
{
	Console::SetCursorPosition(x, y);
	cout << "*";
	Console::SetCursorPosition(x, y + 1);
	cout << "*";
}
