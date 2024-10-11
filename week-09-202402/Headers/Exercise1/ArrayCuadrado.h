#pragma once
#include "Cuadrado.h"

class ArrayCuadrado
{
private:
	vector<Cuadrado*> cuadrados;

public:
	ArrayCuadrado();
	~ArrayCuadrado();
	void agregarCuadrado(Cuadrado* cuadrado);
	Cuadrado* obtenerCuadrado(int indice);
	int getCantidadCuadrados();
	void dibujarTodos(System::Windows::Forms::PaintEventArgs^ e);
};

ArrayCuadrado::ArrayCuadrado() {}

ArrayCuadrado::~ArrayCuadrado()
{
	for (int i = 0; i < cuadrados.size(); i++)
	{
		delete cuadrados[i];
	}
	cuadrados.clear();
}

void ArrayCuadrado::agregarCuadrado(Cuadrado* cuadrado)
{
	cuadrados.push_back(cuadrado);
}

Cuadrado* ArrayCuadrado::obtenerCuadrado(int indice)
{
	if (indice >= 0 && indice < cuadrados.size())
	{
		return cuadrados[indice];
	}
	return nullptr;
}

int ArrayCuadrado::getCantidadCuadrados()
{
	return cuadrados.size();
}

void ArrayCuadrado::dibujarTodos(System::Windows::Forms::PaintEventArgs^ e)
{
	for (int i = 0; i < cuadrados.size(); i++)
	{
		cuadrados[i]->Dibujar(e);
	}
}