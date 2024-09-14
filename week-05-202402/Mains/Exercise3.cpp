#include "ControladoraAvion.h"

int main()
{
    srand(time(nullptr));
    Controladora* controladora = new Controladora();
    controladora->mostrarMenu();

    delete controladora;

    system("pause>0");
    return 0;
}