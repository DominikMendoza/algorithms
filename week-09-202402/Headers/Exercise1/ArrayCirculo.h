#pragma once
#include "Circulo.h"

class ArrayCirculo
{
private:
	vector<Circulo*> circulos;

public:
	ArrayCirculo();
	~ArrayCirculo();
	void agregarCirculo(Circulo* circulo);
	Circulo* obtenerCirculo(int indice);
	int getCantidadCirculos();
	void dibujarTodos(System::Windows::Forms::PaintEventArgs^ e);
};

ArrayCirculo::ArrayCirculo(){}

ArrayCirculo::~ArrayCirculo()
{
	for (int i = 0; i < circulos.size(); i++)
	{
		delete circulos[i];
	}
	circulos.clear();
}

void ArrayCirculo::agregarCirculo(Circulo* circulo)
{
	circulos.push_back(circulo);
}

Circulo* ArrayCirculo::obtenerCirculo(int indice)
{
	if (indice >= 0 && indice < circulos.size())
	{
		return circulos[indice];
	}
	return nullptr;
}

int ArrayCirculo::getCantidadCirculos()
{
	return circulos.size();
}

void ArrayCirculo::dibujarTodos(System::Windows::Forms::PaintEventArgs^ e)
{
	for (int i = 0; i < circulos.size(); i++)
	{
		circulos[i]->Dibujar(e);
	}
}