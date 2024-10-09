#pragma once
#include "Eclipse.h"

class VectorEclipses
{
private:
	int numEclipses;
	Eclipse** eclipses;

public:
	VectorEclipses();
	~VectorEclipses();
	void RegistrarEclipse(Eclipse* eclipse);
	void ModificarEclipse(int indice, Eclipse* nuevoEclipse);
	void EliminarEclipse(int indice);
	int getNumEclipses();
	Eclipse* obtenerDatosEclipse(int indice);
};

VectorEclipses::VectorEclipses()
{
	numEclipses = 0;
	eclipses = nullptr;
}

VectorEclipses::~VectorEclipses()
{
	if (eclipses != nullptr)
	{
		for (int i = 0; i < numEclipses; i++)
		{
			delete eclipses[i];
		}
		delete[] eclipses;
	}
}

void VectorEclipses::RegistrarEclipse(Eclipse* eclipse)
{
	Eclipse** temp = new Eclipse * [numEclipses + 1];
	for (int i = 0; i < numEclipses; i++)
	{
		temp[i] = eclipses[i];
	}
	temp[numEclipses] = eclipse;
	numEclipses++;
	delete[] eclipses;
	eclipses = temp;
}

void VectorEclipses::ModificarEclipse(int indice, Eclipse* nuevoEclipse)
{
	if (indice < 0 || indice >= numEclipses)
	{
		cout << endl << "Indice fuera de rango!" << endl;
		return;
	}
	delete eclipses[indice];
	eclipses[indice] = nuevoEclipse;
}

void VectorEclipses::EliminarEclipse(int indice)
{
	if (indice < 0 || indice >= numEclipses)
	{
		cout << endl << "Indice fuera de rango!" << endl;
		return;
	}
	delete eclipses[indice];
	Eclipse** temp = new Eclipse * [numEclipses - 1];
	for (int i = 0, j = 0; i < numEclipses; i++)
	{
		if (i != indice)
		{
			temp[j++] = eclipses[i];
		}
	}
	numEclipses--;
	delete[] eclipses;
	eclipses = temp;
}

int VectorEclipses::getNumEclipses()
{
	return numEclipses;
}

Eclipse* VectorEclipses::obtenerDatosEclipse(int indice)
{
	if (indice < 0 || indice >= numEclipses)
	{
		cout << endl << "Indice fuera de rango!" << endl;
		return nullptr;
	}
	return eclipses[indice];
}