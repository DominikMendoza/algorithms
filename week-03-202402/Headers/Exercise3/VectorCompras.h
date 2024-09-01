#pragma once
#include "Compra.h"

class VectorCompras
{
private:
	int numCompras;
	Compra** compras;

public:
	VectorCompras();
	~VectorCompras();
	void agregarCompra(Compra* compra);
	int getNumCompras();
	bool existeIDCompra(long long idCompra);
	Compra* getDatosCompra(int indice);
};

VectorCompras::VectorCompras()
{
	numCompras = 0;
	compras = nullptr;
}

VectorCompras::~VectorCompras()
{
	if (compras != nullptr)
	{
		for (int i = 0; i < numCompras; i++)
		{
			delete compras[i];
		}
		delete[] compras;
	}
}

void VectorCompras::agregarCompra(Compra* compra)
{
	Compra** temp = new Compra * [numCompras + 1];
	for (int i = 0; i < numCompras; i++)
	{
		temp[i] = compras[i];
	}
	temp[numCompras] = compra;
	numCompras++;
	delete[] compras;
	compras = temp;
}

int VectorCompras::getNumCompras()
{
	return numCompras;
}

Compra* VectorCompras::getDatosCompra(int indice)
{
	if (indice < 0 || indice >= numCompras)
	{
		cout << "Indice fuera de rango!!" << endl;
		return nullptr;
	}
	return compras[indice];
}

bool VectorCompras::existeIDCompra(long long idCompra)
{
	for (int i = 0; i < numCompras; i++)
	{
		if (compras[i]->getIDCompra() == idCompra)
		{
			return true;
		}
	}
	return false;
}