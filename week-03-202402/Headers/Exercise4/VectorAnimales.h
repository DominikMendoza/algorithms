#pragma once
#include "Animal.h"

class VectorAnimales
{
private:
	int numAnimales;
	Animal** animales;

public:
	VectorAnimales();
	~VectorAnimales();
	void agregarAnimales(Animal* animal);
	int getNumAnimales();
	Animal* getDatosAnimales(int indice);
};

VectorAnimales::VectorAnimales()
{
	numAnimales = 0;
	animales = nullptr;
}

VectorAnimales::~VectorAnimales()
{
	if (animales != nullptr)
	{
		for (int i = 0; i < numAnimales; i++)
		{
			delete animales[i];
		}
		delete[] animales;
	}
}

void VectorAnimales::agregarAnimales(Animal* animal)
{
	Animal** temp = new Animal * [numAnimales + 1];
	for (int i = 0; i < numAnimales; i++)
	{
		temp[i] = animales[i];
	}
	temp[numAnimales] = animal;
	numAnimales++;
	delete[] animales;
	animales = temp;
}

int VectorAnimales::getNumAnimales()
{
	return numAnimales;
}

Animal* VectorAnimales::getDatosAnimales(int indice)
{
	if (indice < 0 || indice >= numAnimales)
	{
		cout << "Indice fuera del rango!!" << endl;
		return nullptr;
	}
	return animales[indice];
}