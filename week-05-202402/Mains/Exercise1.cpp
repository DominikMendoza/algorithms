#include "ControladoraPlanVacaciones.h"

using namespace System;

void Ventana()
{
	Console::SetWindowSize(82, 40);
}

void MostrarMenu()
{
	cout << "\t\t\tPLAN DE VACACIONES\n";
	cout << "\t=======================================================\n";
	cout << "\t1. Registrar Plan De Vacaciones\n";
	cout << "\t2. Mostrar Todos los Planes de Vacaciones\n";
	cout << "\t3. Mostrar Planes de Vacaciones en un intervalo fecha\n";
	cout << "\t4. Mostrar Planes de Vacaciones con el mismo hotel\n";
	cout << "\t5. Mostrar Boletos para cada Plan de Vacaciones\n";
	cout << "\t6. Salir\n";
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
			controladora->RegistroPlanDeVacaciones();
			cout << "\nSE INGRESO CON EXITO LOS DATOS DEL PLAN DE VACACIONES!!" << endl;
			system("pause>0");
			break;
		case 2:
			system("cls");
			if (!controladora->existenPlanesDeVacaciones())
			{
				cout << "NO HAY PLANES DE VACACIONES REGISTRADOS. POR FAVOR REGISTRE LOS DATOS DE UN PLAN." << endl;
			}
			else
			{
				controladora->MostrarTodosPlanesVacaciones();
			}
			system("pause>0");
			break;
		case 3:
			system("cls");
			if (!controladora->existenPlanesDeVacaciones())
			{
				cout << "NO HAY PLANES DE VACACIONES REGISTRADOS. POR FAVOR REGISTRE LOS DATOS DE UN PLAN." << endl;
			}
			else
			{
				controladora->MostrarPlanVacacionesEnIntervaloFecha();
			}
			system("pause>0");
			break;
		case 4:
			system("cls");
			if (!controladora->existenPlanesDeVacaciones())
			{
				cout << "NO HAY PLANES DE VACACIONES REGISTRADOS. POR FAVOR REGISTRE LOS DATOS DE UN PLAN." << endl;
			}
			else
			{
				controladora->MostrarPlanVacacionesMismoHotel();
			}
			system("pause>0");
			break;
		case 5:
			system("cls");
			if (!controladora->existenPlanesDeVacaciones())
			{
				cout << "NO HAY PLANES DE VACACIONES REGISTRADOS. POR FAVOR REGISTRE LOS DATOS DE UN PLAN." << endl;
			}
			else
			{
				controladora->MostrarBoletosCadaPlanVacaciones();
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
