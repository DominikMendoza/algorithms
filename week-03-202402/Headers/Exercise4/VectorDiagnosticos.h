#pragma once
#include "Diagnostico.h"

class VectorDiagnosticos
{
private:
	int numDiagnosticos;
	Diagnostico** diagnosticos;

public:
	VectorDiagnosticos();
	~VectorDiagnosticos();
	void agregarDiagnosticos(Diagnostico* diagnostico);
	int getNumDiagnosticos();
	Diagnostico* getDatosDiagnosticos(int indice);
};

VectorDiagnosticos::VectorDiagnosticos()
{
	numDiagnosticos = 0;
	diagnosticos = nullptr;
}

VectorDiagnosticos::~VectorDiagnosticos()
{
	if (diagnosticos != nullptr)
	{
		for (int i = 0; i < numDiagnosticos; i++)
		{
			delete diagnosticos[i];
		}
		delete[] diagnosticos;
	}
}

void VectorDiagnosticos::agregarDiagnosticos(Diagnostico* diagnostico)
{
	Diagnostico** temp = new Diagnostico * [numDiagnosticos + 1];
	for (int i = 0; i < numDiagnosticos; i++)
	{
		temp[i] = diagnosticos[i];
	}
	temp[numDiagnosticos] = diagnostico;
	numDiagnosticos++;
	delete[] diagnosticos;
	diagnosticos = temp;
}

int VectorDiagnosticos::getNumDiagnosticos()
{
	return numDiagnosticos;
}

Diagnostico* VectorDiagnosticos::getDatosDiagnosticos(int indice)
{
	if (indice < 0 || indice >= numDiagnosticos)
	{
		cout << "Indice fuera de rango!!" << endl;
		return nullptr;
	}
	return diagnosticos[indice];
}