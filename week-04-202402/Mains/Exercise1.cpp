#include "VectorCuadrados.h"

int main()
{
    srand(time(nullptr));
    Ventana();
    VectorCuadrados* vectorcuadrados = new VectorCuadrados();
    vectorcuadrados->agregarCuadrado(new Cuadrado());

    while (true)
    {
        for (int i = 0; i < vectorcuadrados->getNumCuadrados(); i++)
        {
            vectorcuadrados->obtenerDatosCuadrado(i)->Borrar();
        }
        if (_kbhit())
        {
            char tecla = _getch();
            if (tecla == 'a')
            {
                vectorcuadrados->agregarCuadrado(new Cuadrado());
            }
            else if (tecla == 'e')
            {
                vectorcuadrados->eliminarPrimerCuadrado();
            }
            else if (tecla == 'c')
            {
                vectorcuadrados->cambiarColorCuadrados();
            }
        }
        for (int i = 0; i < vectorcuadrados->getNumCuadrados(); i++)
        {
            vectorcuadrados->obtenerDatosCuadrado(i)->Mover();
            vectorcuadrados->obtenerDatosCuadrado(i)->Dibujar();
        }
        _sleep(50);
    }
    
    delete vectorcuadrados;

    system("pause>0");
    return 0;
}