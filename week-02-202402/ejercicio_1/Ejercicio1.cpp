#include "ControladoraEclipse.h"

using namespace System;

void Ventana()
{
    Console::SetWindowSize(72, 40);
}

void MostrarMenu()
{
    cout << "\t\t\tECLIPSE\n";
    cout << "\t=============================================\n";
    cout << "\t1. Registrar Datos\n";
    cout << "\t2. Modificar Datos\n";
    cout << "\t3. Eliminar Datos\n";
    cout << "\t4. Reporte Eclipses\n";
    cout << "\t5. Reporte Eclipses Visibles Europa\n";
    cout << "\t6. Reporte Eclipses Ocasionaron Sismos\n";
    cout << "\t7. Reporte Eclipses Noche\n";
    cout << "\t8. Salir\n";
}

int main()
{
    Controladora* controladora = new Controladora();
    int opcion;

    Ventana();

    do
    {
        MostrarMenu();
        cout << "\tIngrese Opcion: "; cin >> opcion;
        system("cls");

        switch (opcion)
        {
        case 1:
            system("cls");
            controladora->RegistroDatos();
            cout << "\nSE INGRESO CON EXITO LOS DATOS DEL ECLIPSE!!" << endl;
            system("pause>0");
            break;
        case 2:
            system("cls");
            if (!controladora->existenEclipses())
            {
                cout << "NO HAY ECLIPSES REGISTRADOS. POR FAVOR REGISTRE LOS DATOS DE UN ECLIPSE." << endl;
            }
            else
            {
                controladora->ModificarDatos();
            }
            system("pause>0");
            break;
        case 3:
            system("cls");
            if (!controladora->existenEclipses())
            {
                cout << "NO HAY ECLIPSES REGISTRADOS. POR FAVOR REGISTRE LOS DATOS DE UN ECLIPSE." << endl;
            }
            else
            {
                controladora->EliminarDatos();
            }
            system("pause>0");
            break;
        case 4:
            system("cls");
            if (!controladora->existenEclipses())
            {
                cout << "NO HAY ECLIPSES REGISTRADOS. POR FAVOR REGISTRE LOS DATOS DE UN ECLIPSE." << endl;
            }
            else
            {
                controladora->ReporteTodosEclipses();
            }
            system("pause>0");
            break;
        case 5:
            system("cls");
            if (!controladora->existenEclipses())
            {
                cout << "NO HAY ECLIPSES REGISTRADOS. POR FAVOR REGISTRE LOS DATOS DE UN ECLIPSE." << endl;
            }
            else
            {
                controladora->ReporteEclipsesEuropa();
            }
            system("pause>0");
            break;
        case 6:
            system("cls");
            if (!controladora->existenEclipses())
            {
                cout << "NO HAY ECLIPSES REGISTRADOS. POR FAVOR REGISTRE LOS DATOS DE UN ECLIPSE." << endl;
            }
            else
            {
                controladora->ReporteEclipsesSismos();
            }
            system("pause>0");
            break;
        case 7:
            system("cls");
            if (!controladora->existenEclipses())
            {
                cout << "NO HAY ECLIPSES REGISTRADOS. POR FAVOR REGISTRE LOS DATOS DE UN ECLIPSE." << endl;
            }
            else
            {
                controladora->ReporteEclipsesNoche();
            }
            system("pause>0");
            break;
        case 8:
            delete controladora;
            break;
        default:
            cout << "Opcion Invalida!" << endl;
        }
        system("cls");
    } while (opcion != 8);

    return 0;
}

