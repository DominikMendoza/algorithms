#include "Persona.h"

Persona::Persona(float x, float y) : x(x), y(y), ancho(1), alto(1) {}

void Persona::borrar() {
    for (int i = 0; i < alto; i++) {
        System::Console::SetCursorPosition(x, y + i);
        for (int j = 0; j < ancho; j++) {
            cout << " ";
        }
    }
}

void Persona::mover() {
    char tecla;
    if (_kbhit()) {
        tecla = _getch();
        switch (tecla) {
        case 72:
            if (y > 1)
            {
                y--;
            }
            break;
        case 75:
            if (x > 1)
            {
                x--;
            }
            break;
        case 77:
            if (x < 79)
            {
                x++;
            }
            break;
        case 80:
            if (y < 59)
            {
                y++;
            }
            break;
        }
    }
}

void Persona::dibujar() {
    System::Console::ForegroundColor = System::ConsoleColor::Green;
    System::Console::SetCursorPosition(x, y);
    cout << (char)219;
    System::Console::ResetColor();
}
