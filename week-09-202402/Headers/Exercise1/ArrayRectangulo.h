#pragma once
#include "Rectangulo.h"

class ArrayRectangulo
{
private:
	vector<Rectangulo*> rectangulos;

public:
	ArrayRectangulo();
	~ArrayRectangulo();
	void agregarRectangulo(Rectangulo* rectangulo);
	Rectangulo* obtenerRectangulo(int indice);
	int getCantidadRectangulos();
	void dibujarTodos(System::Windows::Forms::PaintEventArgs^ e);
};

ArrayRectangulo::ArrayRectangulo() {}

ArrayRectangulo::~ArrayRectangulo()
{
	for (int i = 0; i < rectangulos.size(); i++)
	{
		delete rectangulos[i];
	}
	rectangulos.clear();
}

void ArrayRectangulo::agregarRectangulo(Rectangulo* rectangulo)
{
	rectangulos.push_back(rectangulo);
}

Rectangulo* ArrayRectangulo::obtenerRectangulo(int indice)
{
	if (indice >= 0 && indice < rectangulos.size())
	{
		return rectangulos[indice];
	}
	return nullptr;
}

int ArrayRectangulo::getCantidadRectangulos()
{
	return rectangulos.size();
}

void ArrayRectangulo::dibujarTodos(System::Windows::Forms::PaintEventArgs^ e)
{
	for (int i = 0; i < rectangulos.size(); i++)
	{
		rectangulos[i]->Dibujar(e);
	}
}