#pragma once
#include "Motorizado.h"

class ListaMotorizados
{
private:
	int numMotorizados;
	Motorizado** motorizados;

public:
	ListaMotorizados();
	~ListaMotorizados(); 
	void agregarMotorizado(Motorizado* motorizado);
	void eliminarMotorizado(string placa);
	void mostrarMotorizados();
	void motorizadosMapi();
	void motorizadosGlopo();
	int getNumMotorizados();
};

ListaMotorizados::ListaMotorizados()
{
	numMotorizados = 0;
	motorizados = nullptr;
}

ListaMotorizados::~ListaMotorizados()
{
	if (motorizados != nullptr)
	{
		for (int i = 0; i < numMotorizados; i++)
		{
			delete motorizados[i];
		}
		delete[] motorizados;
	}
}

int ListaMotorizados::getNumMotorizados()
{
	return numMotorizados;
}

void ListaMotorizados::agregarMotorizado(Motorizado* motorizado)
{
	Motorizado** temp = new Motorizado * [numMotorizados + 1];
	for (int i = 0; i < numMotorizados; i++)
	{
		temp[i] = motorizados[i];
	}
	temp[numMotorizados] = motorizado;
	numMotorizados++;
	delete[] motorizados;
	motorizados = temp;
}

void ListaMotorizados::eliminarMotorizado(string placa)
{
	bool placaEncontrada = false;
	for (int i = 0; i < numMotorizados; i++)
	{
		if (motorizados[i]->getPlaca() == placa)
		{
			delete motorizados[i];
			for (int j = i; j < numMotorizados - 1; j++)
			{
				motorizados[j] = motorizados[j + 1];
			}
			numMotorizados--;
			placaEncontrada = true;
			cout << endl << "SE ELIMINO EL MOTORIZADO CON EXITO!!" << endl;
			break;
		}
	}
	if (!placaEncontrada)
	{
		cout << endl << "PLACA NO ENCONTRADA" << endl;
	}
}

void ListaMotorizados::mostrarMotorizados()
{
	cout << "\t\t\tTOTAL DE MOTORIZADOS\n\n";
	for (int i = 0; i < numMotorizados; i++)
	{
		motorizados[i]->mostrarMotorizado();
		cout << endl;
	}
}

void ListaMotorizados::motorizadosMapi()
{
	bool hayMapi = false;
	for (int i = 0; i < numMotorizados; i++)
	{
		if (motorizados[i]->getEmpresa() == "Mapi")
		{
			if (!hayMapi)
			{
				cout << "\t\t\tMOTORIZADOS DE MAPI\n\n";
				hayMapi = true;
			}
			motorizados[i]->mostrarMotorizado();
			cout << endl;
		}
	}
	if (!hayMapi)
	{
		cout << "NO HAY MOTORIZADOS EN MAPI!!" << endl;
	}
}

void ListaMotorizados::motorizadosGlopo()
{
	bool hayGlopo = false;
	for (int i = 0; i < numMotorizados; i++)
	{
		if (motorizados[i]->getEmpresa() == "Glopo")
		{
			if (!hayGlopo)
			{
				cout << "\t\t\tMOTORIZADOS DE GLOPO\n\n";
				hayGlopo = true;
			}
			motorizados[i]->mostrarMotorizado();
			cout << endl;
		}
	}
	if (!hayGlopo)
	{
		cout << "NO HAY MOTORIZADOS EN GLOPO!!" << endl;
	}
}