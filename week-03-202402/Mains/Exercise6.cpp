#include "ControladoraTriangulo.h"

void Ventana()
{
    Console::SetWindowSize(170, 40);
    Console::CursorVisible = false;
}

void MostrarMenu()
{
    cout << "\t\t\t\t\t\t\t\t\t\tMENU\n";
    cout << "\t\t\t\t\t\t\t\t====================================\n";
    cout << "\t\t\t\t\t\t\t\t1. Triangulo Equilatero Horario\n";
    cout << "\t\t\t\t\t\t\t\t2. Triangulo Rectangulo Horario\n";
    cout << "\t\t\t\t\t\t\t\t3. Salir\n";
}

int main()
{
    Controladora* controladora = new Controladora();
    int opcion;

    Ventana();
    
    do
    {
        MostrarMenu();
        cout << "\t\t\t\t\t\t\t\tIngrese Opcion: "; cin >> opcion;
        system("cls");

        switch (opcion)
        {
        case 1:
            system("cls");
            controladora->TrianguloEquilateroHorario();
            system("pause>0");
            break;
        case 2:
            system("cls");
            controladora->TrianguloRectanguloHorario();
            system("pause>0");
            break;
        case 3:
            delete controladora;
            break;
        default:
            cout << "Opcion Invalida!" << endl;
        }
        system("cls");
    } while (opcion != 3);

    return 0;
}