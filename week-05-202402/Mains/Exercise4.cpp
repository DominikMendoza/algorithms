#include "ControladoraOvni.h"

void Ventana()
{
    Console::SetWindowSize(ANCHO_CONSOLA, ALTO_CONSOLA);
    Console::CursorVisible = false;
}

int main()
{
    Ventana();
    Controladora* controladora = new Controladora();
    controladora->IniciarAnimacion();

    delete controladora;
    
    system("pause>0");
    return 0;
}