#include "ControladoraDiagnosticoAnimal.h"

using namespace System;

void Ventana()
{
    Console::SetWindowSize(82, 40);
}

void MostrarMenu()
{
    cout << "\t\t\t\tMENU\n";
    cout << "\t\t=====================================\n";
    cout << "\t\t1. Insertar Personal\n";
    cout << "\t\t2. Insertar Animal\n";
    cout << "\t\t3. Realizar Diagnostico\n";
    cout << "\t\t4. Reportes Diagnosticos\n";
    cout << "\t\t5. Reportes Animales\n";
    cout << "\t\t6. Salir\n";
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
            controladora->InsertarPersonal();
            cout << endl << "PERSONAL INGRESADO CON EXITO!!" << endl;
            system("pause>0");
            break;
        case 2:
            system("cls");
            if (!controladora->existePersonal())
            {
                cout << "PRIMERO DEBE INGRESAR COMO MINIMO UN PERSONAL!!" << endl;
            }
            else
            {
                controladora->InsertarAnimal();
                cout << endl << "ANIMAL INGRESADO CON EXITO!!" << endl;
            }
            system("pause>0");
            break;
        case 3:
            system("cls");
            if (!controladora->existeAnimal() || !controladora->existePersonal())
            {
                cout << "DEBE INGRESAR AL MENOS UN ANIMAL Y UN PERSONAL ANTES DE REALIZAR UN DIAGNOSTICO!!" << endl;
            }
            else
            {
                controladora->RealizarDiagnostico();
            }
            system("pause>0");
            break;
        case 4:
            system("cls");
            if (!controladora->existeDiagnostico())
            {
                cout << "DEBE REALIZAR PRIMERO UN DIAGNOSTICO COMO MINIMO!!" << endl;
            }
            else
            {
                controladora->ReporteDiagnosticos();
            }
            system("pause>0");
            break;
        case 5:
            system("cls");
            if (!controladora->existeAnimal())
            {
                cout << "NO HAY ANIMALES REGISTRADOS!!" << endl;
            }
            else
            {
                controladora->ReporteAnimales();
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
