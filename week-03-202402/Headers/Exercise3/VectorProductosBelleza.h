#pragma once
#include "ProductoBelleza.h"

class VectorProductos
{
private:
	int numProductos;
	Producto** productos;

public:
	VectorProductos();
	~VectorProductos();
	void agregarProducto(Producto* producto);
	int getNumProductos();
	bool existeCodProducto(int codProducto);
	void reducirCantidadProducto(int codProducto, int cantidadReducir);
	Producto* getDatosProducto(int indice);
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

int VectorProductos::getNumProductos()
{
	return numProductos;
}

Producto* VectorProductos::getDatosProducto(int indice)
{
	if (indice < 0 || indice >= numProductos)
	{
		cout << "Indice fuera de rango!!" << endl;
		return nullptr;
	}
	return productos[indice];
}

void VectorProductos::reducirCantidadProducto(int codProducto, int cantidadReducir)
{
	for (int i = 0; i < numProductos; i++)
	{
		if (productos[i]->getCodProducto() == codProducto)
		{
			int nuevaCantidad = productos[i]->getCantidad() - cantidadReducir;
			productos[i]->setCantidad(nuevaCantidad);
			return;
		}
	}
}

bool VectorProductos::existeCodProducto(int codProducto)
{
	for (int i = 0; i < numProductos; i++)
	{
		if (productos[i]->getCodProducto() == codProducto)
		{
			return true;
		}
	}
	return false;
}