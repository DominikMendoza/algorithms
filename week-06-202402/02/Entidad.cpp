#include "Entidad.h"

Entidad::Entidad(float x, float y, int ancho, int alto) : x(x), y(y), ancho(ancho), alto(alto) {}

void Entidad::borrar() {
    for (int i = 0; i < alto; i++) {
        System::Console::SetCursorPosition(x, y + i);
        for (int j = 0; j < ancho; j++) {
            cout << " ";
        }
    }
}