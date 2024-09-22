#include "Bus.h"

Bus::Bus(float x, float y) : Terrestre(x, y, 0.9, 0.7, 20, 4) {}

void Bus::mover() {
	if (x < 1) x = 60;
	x -= velocidad;
}

void Bus::dibujar() {
	System::Console::SetCursorPosition(x, y);
	cout << "   ____________";
	System::Console::SetCursorPosition(x, y+1);
	cout << "_/_|[][][][][][][]|";
	System::Console::SetCursorPosition(x, y+2);
	cout << " (                |";
	System::Console::SetCursorPosition(x, y+3);
	cout << "=--OO          OO-=";
}

void Bus::cambiarVelocidad(float cantidad) {
	if (velocidad >= 0.5 && velocidad <= 1) velocidad += cantidad;
	else velocidad = 0.8;
}