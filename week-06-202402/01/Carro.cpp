#include "Carro.h"

Carro::Carro(float x, float y) : Terrestre(x, y, 0.6, 0.4) {}

void Carro::borrar() {
	System::Console::SetCursorPosition(x, y);
	cout << "          ";
	System::Console::SetCursorPosition(x, y + 1);
	cout << "         ";
	System::Console::SetCursorPosition(x, y + 2);
	cout << "       ";
}

void Carro::mover() {
	if (x > 65) x = 0;
	x += velocidad;
}

void Carro::dibujar() {
	System::Console::SetCursorPosition(x, y);
	cout << " ____|~\\_ ";
	System::Console::SetCursorPosition(x, y + 1);
	cout << "[____|_|-";
	System::Console::SetCursorPosition(x, y + 2);
	cout << "(_) (_)";
}

void Carro::cambiarVelocidad(float cantidad) {
	if (velocidad >= 0.2 && velocidad <= 0.7) velocidad += cantidad;
	else velocidad = 0.5;
}