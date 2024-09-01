#pragma once
#include "Personal.h"

class VectorPersonal
{
private:
	int numPersonal;
	Personal** personal;

public:
	VectorPersonal();
	~VectorPersonal();
	void agregarPersonal(Personal* persona);
	int getNumPersonal();
	Personal* getDatosPersonal(int indice);
};

VectorPersonal::VectorPersonal()
{
	numPersonal = 0;
	personal = nullptr;
}

VectorPersonal::~VectorPersonal()
{
	if (personal != nullptr)
	{
		for (int i = 0; i < numPersonal; i++)
		{
			delete personal[i];
		}
		delete[] personal;
	}
}

void VectorPersonal::agregarPersonal(Personal* persona)
{
	Personal** temp = new Personal * [numPersonal + 1];
	for (int i = 0; i < numPersonal; i++)
	{
		temp[i] = personal[i];
	}
	temp[numPersonal] = persona;
	numPersonal++;
	delete[] personal;
	personal = temp;
}

int VectorPersonal::getNumPersonal()
{
	return numPersonal;
}

Personal* VectorPersonal::getDatosPersonal(int indice)
{
	if (indice < 0 || indice >= numPersonal)
	{
		cout << "Indice fuera de rango!!" << endl;
		return nullptr;
	}
	return personal[indice];
}