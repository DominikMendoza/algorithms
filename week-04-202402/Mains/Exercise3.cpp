#include "Controladora.h"

int main()
{
    srand(time(nullptr));
    Ventana();
    Controladora* controladora = new Controladora();
    controladora->Iniciar();

    delete controladora;

    system("pause>0");
    return 0;
}
