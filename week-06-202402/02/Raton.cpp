#include "Raton.h"

int pos[2] = { 1,-1 };

Raton::Raton() : Entidad(rand() % 70, rand() % 40+1), dx(pos[rand() % 2]), dy(pos[rand() % 2]), velocidad(0.1 + static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * (0.9)), visible(false) {}

void Raton::borrar() {
	System::Console::SetCursorPosition(x, y);
	cout << "       ";
}

void Raton::mover() {
	if (x < 1 || x>70) dx *= -1;
	if (y < 1 || y>39) dy *= -1;
	x += dx * velocidad;
	y += dy * velocidad;
}

void Raton::mover(int gatoX, int gatoY) {
    float distanciaX = x - gatoX;
    float distanciaY = y - gatoY;
    float distancia = sqrt(distanciaX * distanciaX + distanciaY * distanciaY);

    if (distancia < 10) {
        if (distanciaX < 0) dx = -fabs(dx);
        else dx = fabs(dx); 

        if (distanciaY < 0) dy = -fabs(dy);
        else dy = fabs(dy);
    }

    if (x < 1 || x > 70) dx *= -1;
    if (y < 1 || y > 39) dy *= -1;
    x += dx * velocidad;
    y += dy * velocidad;
}

void Raton::dibujar() {
    if (visible) {
        System::Console::SetCursorPosition(x, y);
        cout << "--(_c'>";
    }
}