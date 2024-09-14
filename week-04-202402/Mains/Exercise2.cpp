#include "Competencia.h"

int main()
{
    srand(time(nullptr));
    Ventana();
    Competencia* competencia = new Competencia();
    competencia->Iniciar();

    delete competencia;

    system("pause>0");
    return 0;
}