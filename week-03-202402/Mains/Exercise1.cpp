#include "ControladoraAlmacen.h"

using namespace System;

void Ventana()
{
    Console::SetWindowSize(120, 40);
}

void MostrarMenu()
{
    cout << "\t\t\t\t\t\t\tMENU\n";
    cout << "\t\t====================================================================================\n";
    cout << "\t\t1. Insertar Producto\n";
    cout << "\t\t2. Insertar Proveedor\n";
    cout << "\t\t3. Modificar Producto\n";
    cout << "\t\t4. Mostrar Productos Categoria A y Proveedor Natura\n";
    cout << "\t\t5. Eliminar Productos con Proveedor Herbalife\n";
    cout << "\t\t6. Eliminar Productos Vencidos\n";
    cout << "\t\t7. Reportes (mostrar todos los productos en stock con sus respectivos proveedores)\n";
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
            if (!controladora->existenProveedores())
            {
                cout << "NO HAY PROVEEDORES REGISTRADOS. POR FAVOR, INGRESE UN PROVEEDOR!!" << endl;
            }
            else
            {
                controladora->InsertarProducto();
                cout << endl << "SE INGRESO CON EXITO EL PRODUCTO!!" << endl;
            }
            system("pause>0");
            break;
        case 2:
            system("cls");
            controladora->InsertarProveedor();
            cout << endl << "SE INGRESO CON EXITO EL PROVEEDOR!!" << endl;
            system("pause>0");
            break;
        case 3:
            system("cls");
            if (!controladora->existenProductos())
            {
                cout << "NO HAY PRODUCTOS REGISTRADOS. POR FAVOR, INGRESE UN PRODUCTO!!" << endl;
            }
            else
            {
                controladora->ModificarProducto();
            }
            system("pause>0");
            break;
        case 4:
            system("cls");
            if (!controladora->existenProductos() || !controladora->existenProveedores())
            {
                cout << "DEBE HABERSE REGISTRADO POR LO MENOS UN PRODUCTO Y UN PROVEEDOR!!" << endl;
            }
            else
            {
                controladora->MostrarProductosCategoriaANatura();
            }
            system("pause>0");
            break;
        case 5:
            system("cls");
            if (!controladora->existenProductos() || !controladora->existenProveedores())
            {
                cout << "DEBE HABERSE REGISTRADO POR LO MENOS UN PRODUCTO Y UN PROVEEDOR!!" << endl;
            }
            else
            {
                controladora->EliminarProductosProveedorHerbalife();
            }
            system("pause>0");
            break;
        case 6:
            system("cls");
            if (!controladora->existenProductos())
            {
                cout << "NO HAY PRODUCTOS REGISTRADOS. POR FAVOR, INGRESE UN PRODUCTO!!" << endl;
            }
            else
            {
                controladora->EliminarProductosVencidos();
            }
            system("pause>0");
            break;
        case 7:
            system("cls");
            if (!controladora->existenProductos() || !controladora->existenProveedores())
            {
                cout << "DEBE HABERSE REGISTRADO POR LO MENOS UN PRODUCTO Y UN PROVEEDOR!!" << endl;
            }
            else
            {
                controladora->Reportes();
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
