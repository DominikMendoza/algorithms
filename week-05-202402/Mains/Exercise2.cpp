#include "ControladoraPasante.h"

void Ventana()
{
    Console::SetWindowSize(80, 40);
}

void MostrarMenu()
{
    cout << "\t\t\t\t\tMENU\n";
    cout << "\t====================================================================\n";
    cout << "\t1. Registrar Pasante\n";
    cout << "\t2. Verificar Universidad Proporsiona Mayoria Pasantes\n";
    cout << "\t3. Visualizar Promedio Notas de Estudiantes para Seleccionar Pasantes\n";
    cout << "\t4. Mostrar Pasantes\n";
    cout << "\t5. Salir\n";
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
        cout << "\tIngrese Opcion: "; cin >> opcion;
        system("cls");

        switch (opcion)
        {
        case 1:
            system("cls");
            controladora->AgregarPasante();
            cout << "\nSE INGRESO CON EXITO LOS DATOS DEL PASANTE!!" << endl;
            system("pause>0");
            break;
        case 2:
            system("cls");
            controladora->VerificarUniversidadMayoriaPasantesEmpresa();
            system("pause>0");
            break;
        case 3:
            system("cls");
            controladora->VisualizarPromedioNotasEstudiantesSelecPasantes();
            system("pause>0");
            break;
        case 4:
            system("cls");
            controladora->MostrarPasantes();
            system("pause>0");
            break;
        case 5:
            delete controladora;
            break;
        default:
            cout << "Opcion Invalida!" << endl;
        }
        system("cls");
    } while (opcion != 5);
      
    return 0;
}