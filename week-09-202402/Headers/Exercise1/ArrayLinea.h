#pragma once
#include "Linea.h"

class ArrayLinea
{
private:
	vector<Linea*> lineas;

public:
	ArrayLinea();
	~ArrayLinea();
	void agregarLinea(Linea* linea);
	Linea* obtenerLinea(int indice);
	int getCantidadLineas();
	void dibujarTodos(System::Windows::Forms::PaintEventArgs^ e);
};

ArrayLinea::ArrayLinea() {}

ArrayLinea::~ArrayLinea()
{
	for (int i = 0; i < lineas.size(); i++)
	{
		delete lineas[i];
	}
	lineas.clear();
}

void ArrayLinea::agregarLinea(Linea* linea)
{
	lineas.push_back(linea);
}

Linea* ArrayLinea::obtenerLinea(int indice)
{
	if (indice >= 0 && indice < lineas.size())
	{
		return lineas[indice];
	}
	return nullptr;
}

int ArrayLinea::getCantidadLineas()
{
	return lineas.size();
}

void ArrayLinea::dibujarTodos(System::Windows::Forms::PaintEventArgs^ e)
{
	for (int i = 0; i < lineas.size(); i++)
	{
		lineas[i]->Dibujar(e);
	}
}