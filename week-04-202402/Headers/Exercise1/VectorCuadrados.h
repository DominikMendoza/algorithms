#pragma once
#include "Cuadrado.h"

class VectorCuadrados
{
private:
	int numCuadrados;
	Cuadrado** cuadrados;

public:
	VectorCuadrados();
	~VectorCuadrados();
	void agregarCuadrado(Cuadrado* cuadrado);
	void eliminarPrimerCuadrado();
	void cambiarColorCuadrados();
	int getNumCuadrados();
	Cuadrado* obtenerDatosCuadrado(int indice);
};

VectorCuadrados::VectorCuadrados()
{
	numCuadrados = 0;
	cuadrados = nullptr;
}

VectorCuadrados::~VectorCuadrados()
{
	if (cuadrados != nullptr)
	{
		for (int i = 0; i < numCuadrados; i++)
		{
			delete cuadrados[i];
		}
		delete[] cuadrados;
	}
}

void VectorCuadrados::agregarCuadrado(Cuadrado* cuadrado)
{
	Cuadrado** temp = new Cuadrado * [numCuadrados + 1];
	for (int i = 0; i < numCuadrados; i++)
	{
		temp[i] = cuadrados[i];
	}
	temp[numCuadrados] = cuadrado;
	numCuadrados++;
	delete[] cuadrados;
	cuadrados = temp;
}

void VectorCuadrados::eliminarPrimerCuadrado()
{
	if (numCuadrados == 0)
	{
		return; 
	}
	delete cuadrados[0];
	Cuadrado** temp = new Cuadrado * [numCuadrados - 1];
	for (int i = 0; i < numCuadrados - 1; i++)
	{
		temp[i] = cuadrados[i + 1];
	}
	numCuadrados--;
	delete[] cuadrados;
	cuadrados = temp;
}

void VectorCuadrados::cambiarColorCuadrados()
{
	for (int i = 0; i < numCuadrados; i++)
	{
		cuadrados[i]->CambiarColor();
	}
}

int VectorCuadrados::getNumCuadrados()
{
	return numCuadrados;
}

Cuadrado* VectorCuadrados::obtenerDatosCuadrado(int indice)
{
	if (indice < 0 || indice >= numCuadrados)
	{
		return nullptr;
	}
	return cuadrados[indice];
}