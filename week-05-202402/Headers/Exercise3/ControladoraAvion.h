#pragma once
#include "AvionTipo1.h"
#include "AvionTipo2.h"
#include "AvionTipo3.h"
#include "AvionTipo4.h"
#include "AvionTipo5.h"
#include "AvionTipo6.h"
#include "AvionTipo7.h"
#include "AvionTipo8.h"
#include "AvionTipo9.h"

class Controladora
{
private:
	Avion* avionSeleccionado;

public:
	Controladora();
	~Controladora();
	void mostrarMenu();
	void elegirAvion(int tipo);
	void SimularVuelo();
};

Controladora::Controladora()
{
	avionSeleccionado = nullptr;
}

Controladora::~Controladora()
{
	if (avionSeleccionado != nullptr)
	{
		delete avionSeleccionado;
	}
}

void Controladora::elegirAvion(int tipo)
{
	switch (tipo)
	{
	case 1: 
		avionSeleccionado = new AvionTipo1(); 
		break;
	case 2:
		avionSeleccionado = new AvionTipo2();
		break;
	case 3:
		avionSeleccionado = new AvionTipo3();
		break;
	case 4:
		avionSeleccionado = new AvionTipo4();
		break;
	case 5:
		avionSeleccionado = new AvionTipo5();
		break;
	case 6:
		avionSeleccionado = new AvionTipo6();
		break;
	case 7:
		avionSeleccionado = new AvionTipo7();
		break;
	case 8:
		avionSeleccionado = new AvionTipo8();
		break;
	case 9: 
		avionSeleccionado = new AvionTipo9();
		break;
	}
}

void Controladora::SimularVuelo()
{
	system("cls");
	if (avionSeleccionado != nullptr)
	{
		while (avionSeleccionado->estaEnMovimiento())
		{
			avionSeleccionado->Borrar();
			avionSeleccionado->Mover();
			avionSeleccionado->Dibujar();
			_sleep(80);
		}
	}
}

void Controladora::mostrarMenu()
{
	int opcion;
	Ventana();
	do
	{
		system("cls");
		cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tSeleccione el tipo de avion para sobrevolar las Lineas de Nazca:\n";
		cout << "\t\t\t\t1. Avion Tipo 1\n";
		cout << "\t\t\t\t2. Avion Tipo 2\n";
		cout << "\t\t\t\t3. Avion Tipo 3\n";
		cout << "\t\t\t\t4. Avion Tipo 4\n";
		cout << "\t\t\t\t5. Avion Tipo 5\n";
		cout << "\t\t\t\t6. Avion Tipo 6\n";
		cout << "\t\t\t\t7. Avion Tipo 7\n";
		cout << "\t\t\t\t8. Avion Tipo 8\n";
		cout << "\t\t\t\t9. Avion Tipo 9\n";
		cout << "\t\t\t\t10. Salir\n";
		cout << "\t\t\t\tIngrese Opcion: "; cin >> opcion;
		system("cls");
		if (opcion >= 1 && opcion <= 9)
		{
			elegirAvion(opcion);
			SimularVuelo();
		}
	} while (opcion != 10);
}