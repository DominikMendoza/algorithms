#pragma once
#include "Elipse.h"

class ArrayElipse
{
private:
	vector<Elipse*> elipses;

public:
	ArrayElipse();
	~ArrayElipse();
	void agregarElipse(Elipse* elipse);
	Elipse* obtenerElipse(int indice);
	int getCantidadElipses();
	void dibujarTodos(System::Windows::Forms::PaintEventArgs^ e);
};

ArrayElipse::ArrayElipse() {}

ArrayElipse::~ArrayElipse()
{
	for (int i = 0; i < elipses.size(); i++)
	{
		delete elipses[i];
	}
	elipses.clear();
}

void ArrayElipse::agregarElipse(Elipse* elipse)
{
	elipses.push_back(elipse);
}

Elipse* ArrayElipse::obtenerElipse(int indice)
{
	if (indice >= 0 && indice < elipses.size())
	{
		return elipses[indice];
	}
	return nullptr;
}

int ArrayElipse::getCantidadElipses()
{
	return elipses.size();
}

void ArrayElipse::dibujarTodos(System::Windows::Forms::PaintEventArgs^ e)
{
	for (int i = 0; i < elipses.size(); i++)
	{
		elipses[i]->Dibujar(e);
	}
}