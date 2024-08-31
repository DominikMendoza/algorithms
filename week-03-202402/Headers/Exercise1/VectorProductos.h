#pragma once
#include "Producto.h"

class VectorProductos
{
private:
	int numProductos;
	Producto** productos;

public:
	VectorProductos();
	~VectorProductos();
	void agregarProducto(Producto* producto);
	void eliminarProducto(int indice);
	int getNumProductos();
	void modificarProducto(int indice, Producto* nuevoProducto);
	Producto* obtenerDatosProducto(int indice);
};

VectorProductos::VectorProductos()
{
	numProductos = 0;
	productos = nullptr;
}

VectorProductos::~VectorProductos()
{
	if (productos != nullptr)
	{
		for (int i = 0; i < numProductos; i++)
		{
			delete productos[i];
		}
		delete[] productos;
	}
}

void VectorProductos::agregarProducto(Producto* producto)
{
	Producto** temp = new Producto * [numProductos + 1];
	for (int i = 0; i < numProductos; i++)
	{
		temp[i] = productos[i];
	}
	temp[numProductos] = producto;
	numProductos++;
	delete[] productos;
	productos = temp;
}

void VectorProductos::eliminarProducto(int indice)
{
	if (indice < 0 || indice >= numProductos)
	{
		cout << endl << "Indice fuera de rango!!" << endl;
		return;
	}
	delete productos[indice];
	Producto** temp = new Producto * [numProductos - 1];
	for (int i = 0, j = 0; i < numProductos; i++)
	{
		if (i != indice)
		{
			temp[j++] = productos[i];
		}
	}
	numProductos--;
	delete[] productos;
	productos = temp;
}

void VectorProductos::modificarProducto(int indice, Producto* nuevoProducto)
{
	if (indice < 0 || indice >= numProductos)
	{
		cout << endl << "Indice fuera de rango!" << endl;
		return;
	}
	delete productos[indice];
	productos[indice] = nuevoProducto;
}

int VectorProductos::getNumProductos()
{
	return numProductos;
}

Producto* VectorProductos::obtenerDatosProducto(int indice)
{
	if (indice < 0 || indice >= numProductos)
	{
		cout << "Indice fuera de rango" << endl;
		return nullptr;
	}
	return productos[indice];
}