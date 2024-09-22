#include "Gato.h"

Gato::Gato(float x, float y) : Entidad(x, y,8,3) {}

void Gato::mover() {
    char tecla;
    if (_kbhit()) {
        tecla = toupper(_getch());
        switch (tecla) {
        case 72:
        case 'W':
            if (y > 1)
            {
                y--;
            }
            break;
        case 75:
        case 'A':
            if (x > 1)
            {
                x--;
            }
            break;
        case 77:
        case 'D':
            if (x < 79)
            {
                x++;
            }
            break;
        case 80:
        case 'S':
            if (y < 40)
            {
                y++;
            }
            break;
        }
    }
}

void Gato::dibujar() {
    System::Console::SetCursorPosition(x, y);
    cout << " /\\_/\\";
    System::Console::SetCursorPosition(x, y + 1);
    cout << "( o.o )";
    System::Console::SetCursorPosition(x, y + 2);
    cout << " > ^ <";
}