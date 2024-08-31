#pragma once
#include "Proveedor.h"

class VectorProveedores
{
private:
	int numProveedores;
	Proveedor** proveedores;

public:
	VectorProveedores();
	~VectorProveedores();
	void agregarProveedor(Proveedor* proveedor);
	int getNumProveedores();
	Proveedor* obtenerDatosProveedor(int indice);
};

VectorProveedores::VectorProveedores()
{
	numProveedores = 0;
	proveedores = nullptr;
}

VectorProveedores::~VectorProveedores()
{
	if (proveedores != nullptr)
	{
		for (int i = 0; i < numProveedores; i++)
		{
			delete proveedores[i];
		}
		delete[] proveedores;
	}
}

void VectorProveedores::agregarProveedor(Proveedor* proveedor)
{
	Proveedor** temp = new Proveedor* [numProveedores + 1];
	for (int i = 0; i < numProveedores; i++)
	{
		temp[i] = proveedores[i];
	}
	temp[numProveedores] = proveedor;
	numProveedores++;
	delete[] proveedores;
	proveedores = temp;
}

int VectorProveedores::getNumProveedores()
{
	return numProveedores;
}

Proveedor* VectorProveedores::obtenerDatosProveedor(int indice)
{
	if (indice < 0 || indice >= numProveedores)
	{
		cout << "Indice fuera de rango" << endl;
		return nullptr;
	}
	return proveedores[indice];
}
