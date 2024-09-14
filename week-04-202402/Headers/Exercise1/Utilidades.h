#pragma once
#include "iostream"
#include "conio.h"
#define ANCHO_PANTALLA 80
#define ALTO_PANTALLA 40

using namespace System;
using namespace std;

int RandInt(int min, int max)
{
	return rand() % (max - min + 1) + min;
}

void Ventana()
{
	Console::SetWindowSize(ANCHO_PANTALLA, ALTO_PANTALLA);
	Console::CursorVisible = false;
}