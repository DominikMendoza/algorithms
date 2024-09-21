#include "Bicicleta.h"

Bicicleta::Bicicleta(float x, float y) : Terrestre(x, y, 0.3, 0.1) {}

void Bicicleta::borrar() {
	System::Console::SetCursorPosition(x, y);
	cout << "    ";
	System::Console::SetCursorPosition(x, y + 1);
	cout << "      ";
}

void Bicicleta::mover() {
	if (x < 1 || x > 73) velocidad *= -1;
	x += velocidad;
}

void Bicicleta::dibujar() {
	System::Console::ForegroundColor = System::ConsoleColor::Gray;
	if (velocidad < 1) {
		System::Console::SetCursorPosition(x, y);
		cout << ".._\\";
		System::Console::SetCursorPosition(x, y + 1);
		cout << "(o)(o)";
	}
	else if (x > 73){
		System::Console::SetCursorPosition(x, y);
		cout << "/_..";
		System::Console::SetCursorPosition(x, y + 1);
		cout << "(o)(o)";
	}
	System::Console::ResetColor();
}

void Bicicleta::cambiarVelocidad(float velocidad){}
