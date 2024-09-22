#include "Terrestre.h"

Terrestre::Terrestre(float x, float y, float maxVel, float minVel, int ancho, int alto) {
	this->x = x;
	this->y = y;
	this->velocidad = minVel + static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * (maxVel  - minVel);
	this->ancho = ancho;
	this->alto = alto;
}

void Terrestre::borrar() {
	for (int i = 0; i < alto; i++) {
		System::Console::SetCursorPosition(x, y + i);
		for (int j = 0; j < ancho; j++) {
			cout << " ";
		}
	}
}