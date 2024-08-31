#include "ControladoraEmpresa.h"

using namespace System;

void Ventana()
{
    Console::SetWindowSize(72, 35);
}

void MostrarMenu()
{
    cout << "\t\tENCUESTA DE VENTA DE LECHE EN SUPERMERCADOS\n";
    cout << "\t======================================================\n";
    cout << "\t1] GENERAR DATOS DE LOS ENCUESTADOS\n";
    cout << "\t2] MOSTRAR DATOS DE LOS ENCUESTADOS\n";
    cout << "\t3] ELIMINAR DATOS DE UN ENCUESTADO\n";
    cout << "\t4] SALIR\n";
}

int main()
{
    srand(time(nullptr));
    Controladora* controladora = new Controladora();
    int opcion;

    Ventana();

    do
    {
        MostrarMenu();
        cout << "\tIngrese opcion: "; cin >> opcion;
        system("cls");

        switch (opcion)
        {
        case 1:
        {
            system("cls");
            controladora->GenerarEncuestas();
            system("pause>0");
            break;
        }
        case 2:
        {
            system("cls");
            if (!controladora->existenEncuestas())
            {
                cout << "NO HAY ENCUESTAS GENERADAS. POR FAVOR GENERE PRIMERO UNA ENCUESTA." << endl;
            }
            else
            {
                controladora->MostrarEncuestas();
            }
            system("pause>0");
            break;
        }
        case 3:
        {
            system("cls");
            if (!controladora->existenEncuestas())
            {
                cout << "NO HAY ENCUESTAS GENERADAS. POR FAVOR GENERE PRIMERO UNA ENCUESTA." << endl;
            }
            else
            {
                controladora->EliminarEncuestas();
            }
            system("pause>0");
            break;
        }
        case 4:
        {
            delete controladora;
            break;
        }
        default:
            cout << "Opcion Invalida!" << endl;
        }
        system("cls");
    } while (opcion != 4);

    return 0;
}