#include "ControladoraBelleza.h"

using namespace System;

void Ventana()
{
    Console::SetWindowSize(80, 40);
}

void MostrarMenu()
{
    cout << "\t\t\tTIENDA DE PRODUCTOS\n";
    cout << "\t\t=====================================\n";
    cout << "\t\t1. Ingresar Producto\n";
    cout << "\t\t2. Ingresar Cliente\n";
    cout << "\t\t3. Realizar Compra\n";
    cout << "\t\t4. Agregar Cantidad Stock\n";
    cout << "\t\t5. Mostrar Productos\n";
    cout << "\t\t6. Mostrar Clientes\n";
    cout << "\t\t7. Mostrar Compras\n";
    cout << "\t\t8. Salir\n";
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
            controladora->IngresarProducto();
            system("pause>0");
            break;
        case 2:
            system("cls");
            if (!controladora->existeProducto())
            {
                cout << "PRIMERO INGRESE UN PRODUCTO COMO MINIMO!!" << endl;
            }
            else
            {
                controladora->IngresarCliente();
            }
            system("pause>0");
            break;
        case 3:
            system("cls");
            if (!controladora->existeProducto() || !controladora->existeCliente())
            {
                cout << "DEBE INGRESAR AL MENOS UN PRODUCTO Y UN CLIENTE ANTES DE REALIZAR UNA COMPRA!!" << endl;
            }
            else
            {
                controladora->RealizarCompra();
            }
            system("pause>0");
            break;
        case 4:
            system("cls");
            if (!controladora->existeProducto())
            {
                cout << "NO HAY PRODUCTOS PARA AGREGAR CANTIDAD A ALGUN STOCK!!" << endl;
            }
            else
            {
                controladora->AgregarCantidadAStock();
            }
            system("pause>0");
            break;
        case 5:
            system("cls");
            if (!controladora->existeProducto())
            {
                cout << "NO HAY PRODUCTOS PARA MOSTRAR!!" << endl;
            }
            else
            {
                controladora->MostrarProductos();
            }
            system("pause>0");
            break;
        case 6:
            system("cls");
            if (!controladora->existeCliente())
            {
                cout << "NO HAY CLIENTES PARA MOSTRAR!!" << endl;
            }
            else
            {
                controladora->MostrarClientes();
            }
            system("pause>0");
            break;
        case 7:
            system("cls");
            if (!controladora->existeCompra())
            {
                cout << "NO HAY COMPRAS REALIZADAS PARA MOSTRAR!!" << endl;
            }
            else
            {
                controladora->MostrarCompras();
            }
            system("pause>0");
            break;
        case 8:
            delete controladora;
            break;
        default:
            cout << "Opcion Invalida!!" << endl;
        }
        system("cls");
    } while (opcion != 8);

    return 0;
}
