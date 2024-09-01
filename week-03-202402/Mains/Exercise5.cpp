#include "ControladoraDelivery.h"

using namespace System;

void Ventana()
{
    Console::SetWindowSize(78, 40);
}

void MostrarMenu()
{
    cout << "\t\t\t\tMENU\n";
    cout << "\t\t=====================================\n";
    cout << "\t\t1. AGREGAR MOTORIZADO\n";
    cout << "\t\t2. ELIMINAR MOTORIZADO\n";
    cout << "\t\t3. MOSTRAR TODOS LOS MOTORIZADOS\n";
    cout << "\t\t4. MOTORIZADOS MAPI\n";
    cout << "\t\t5. MOTORIZADOS GLOPO\n";
    cout << "\t\t6. SALIR\n";
}

int main()
{
    Controladora* controladora = new Controladora();
    int opcion;

    Ventana();

    do
    {
        MostrarMenu();
        cout << "\t\tIngrese Opcion: "; cin >> opcion;
        system("cls");

        switch (opcion)
        {
        case 1:
            system("cls");
            controladora->AgregarMotorizado();
            cout << "\nSE INGRESO CON EXITO LOS DATOS DEL MOTORIZADO!!" << endl;
            system("pause>0");
            break;
        case 2:
            system("cls");
            if (!controladora->existenMotorizados())
            {
                cout << "NO HAY MOTORIZADOS REGISTRADOS. POR FAVOR REGISTRE LOS DATOS DE UN MOTORIZADO." << endl;
            }
            else
            {
                controladora->EliminarMotorizado();
            }
            system("pause>0");
            break;
        case 3:
            system("cls");
            if (!controladora->existenMotorizados())
            {
                cout << "NO HAY MOTORIZADOS REGISTRADOS. POR FAVOR REGISTRE LOS DATOS DE UN MOTORIZADO." << endl;
            }
            else
            {
                controladora->MostrarTodosMotorizados();
            }
            system("pause>0");
            break;
        case 4:
            system("cls");
            if (!controladora->existenMotorizados())
            {
                cout << "NO HAY MOTORIZADOS REGISTRADOS. POR FAVOR REGISTRE LOS DATOS DE UN MOTORIZADO." << endl;
            }
            else
            {
                controladora->MotorizadosMapi();
            }
            system("pause>0");
            break;
        case 5:
            system("cls");
            if (!controladora->existenMotorizados())
            {
                cout << "NO HAY MOTORIZADOS REGISTRADOS. POR FAVOR REGISTRE LOS DATOS DE UN MOTORIZADO." << endl;
            }
            else
            {
                controladora->MotorizadosGlopo();
            }
            system("pause>0");
            break;
        case 6:
            delete controladora;
            break;
        default:
            cout << "Opcion Invalida!" << endl;
        }
        system("cls");
    } while (opcion != 6);

    return 0;
}