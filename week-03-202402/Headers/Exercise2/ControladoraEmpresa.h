#pragma once
#include "Encuesta.h"

class Controladora
{
private:
	int numEncuestas;
	Encuesta** encuestas;

public:
	Controladora();
	~Controladora();
	//void GenerarEncuestas(Encuesta* encuesta); //PARA 1 POR 1
	void GenerarEncuestas();
	void MostrarEncuestas();
	void EliminarEncuestas();
	bool existenEncuestas();
};

Controladora::Controladora()
{
	numEncuestas = 0;
	encuestas = nullptr;
}

Controladora::~Controladora()
{
	if (encuestas != nullptr)
	{
		for (int i = 0; i < numEncuestas; i++)
		{
			delete encuestas[i];
		}
		delete[] encuestas;
	}
}

//SOLO PARA GENERAR 1 POR 1
//void Controladora::GenerarEncuestas(Encuesta* encuesta)
//{
//	Encuesta** temp = new Encuesta * [numEncuestas + 1];
//	for (int i = 0; i < numEncuestas; i++)
//	{
//		temp[i] = encuestas[i];
//	}
//	temp[numEncuestas] = encuesta;
//	numEncuestas++;
//	delete[] encuestas;
//	encuestas = temp;
//}

void Controladora::GenerarEncuestas()
{
	int cantidad;
	do
	{
		cout << "Ingrese la cantidad de encuestas a generar: "; cin >> cantidad;
	} while (cantidad < 1);
	Encuesta** temp = new Encuesta * [numEncuestas + cantidad];
	for (int i = 0; i < numEncuestas; i++)
	{
		temp[i] = encuestas[i];
	}
	for (int i = 0; i < cantidad; i++)
	{
		temp[numEncuestas + i] = new Encuesta();
	}
	numEncuestas += cantidad;
	delete[] encuestas;
	encuestas = temp;
	cout << "\nSE GENERARON " << cantidad << " ENCUESTAS EXITOSAMENTE!!\n";
}

void Controladora::MostrarEncuestas()
{
	cout << "\t\tTODAS LAS ENCUESTAS GENERADAS\n\n";
	for (int i = 0; i < numEncuestas; i++)
	{
		cout << "Encuesta #" << i + 1 << ": " << endl;
		encuestas[i]->mostrarEncuesta();
		cout << endl;
	}
}

void Controladora::EliminarEncuestas()
{
	int indiceEliminar = -1;
	string DNI;
	cout << "Ingrese el DNI de la encuesta a eliminar: "; cin >> DNI;
	for (int i = 0; i < numEncuestas; i++)
	{
		if (encuestas[i]->getDNI() == DNI)
		{
			indiceEliminar = i;
			break;
		}
	}
	if (indiceEliminar == -1)
	{
		cout << endl << "DNI NO ENCONTRADO!!" << endl;
		return;
	}
	delete encuestas[indiceEliminar];  
	Encuesta** temp = new Encuesta * [numEncuestas - 1];
	for (int i = 0, j = 0; i < numEncuestas; i++)
	{
		if (i != indiceEliminar)  
		{
			temp[j++] = encuestas[i];
		}
	}
	numEncuestas--;
	delete[] encuestas;
	encuestas = temp;
	cout << endl << "SE HA ELIMINADO LA ENCUESTA CON EXITO!!" << endl;
}

bool Controladora::existenEncuestas()
{
	return numEncuestas > 0;
}