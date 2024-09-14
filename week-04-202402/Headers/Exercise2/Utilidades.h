#pragma once
#include "iostream"
#define ANCHO_CONSOLA 100
#define ALTO_CONSOLA 40

using namespace System;
using namespace std;

void Ventana()
{
	Console::SetWindowSize(ANCHO_CONSOLA, ALTO_CONSOLA);
	Console::CursorVisible = false;
}

void Cursor(int x, int y)
{
	Console::SetCursorPosition(x, y);
}

int RandInt(int min, int max)
{
	return rand() % (max - min + 1) + min;
}

float RandFloat(float min, float max)
{
	return min + static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * (max - min);
}