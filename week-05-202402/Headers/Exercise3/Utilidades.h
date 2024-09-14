#pragma once
#include "iostream"
#include "conio.h"
#define ANCHO_CONSOLA 140
#define ALTO_CONSOLA 40

using namespace std;
using namespace System;

int RandInt(int min, int max)
{
	return rand() % (max - min + 1) + min;
}

float RandFloat(float min, float max)
{
	return min + static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * (max - min);
}

void Ventana()
{
	Console::SetWindowSize(ANCHO_CONSOLA, ALTO_CONSOLA);
	Console::CursorVisible = false;
}