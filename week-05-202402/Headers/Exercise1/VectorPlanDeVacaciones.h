#pragma once
#include "PlanDeVacaciones.h"

class VectorPlanDeVacaciones
{
private:
	int numPlanesDeVacaciones;
	PlanDeVacaciones** planesdevacaciones;

public:
	VectorPlanDeVacaciones();
	~VectorPlanDeVacaciones();
	void agregarPlanDeVacaciones(PlanDeVacaciones* plandevacaciones);
	int getNumPlanesDeVacaciones();
	PlanDeVacaciones* obtenerDatosPlanDeVacaciones(int indice);
};

VectorPlanDeVacaciones::VectorPlanDeVacaciones()
{
	numPlanesDeVacaciones = 0;
	planesdevacaciones = nullptr;
}

VectorPlanDeVacaciones::~VectorPlanDeVacaciones()
{
	if (planesdevacaciones != nullptr)
	{
		for (int i = 0; i < numPlanesDeVacaciones; i++)
		{
			delete planesdevacaciones[i];
		}
		delete[] planesdevacaciones;
	}
}

void VectorPlanDeVacaciones::agregarPlanDeVacaciones(PlanDeVacaciones* plandevacaciones)
{
	PlanDeVacaciones** temp = new PlanDeVacaciones * [numPlanesDeVacaciones + 1];
	for (int i = 0; i < numPlanesDeVacaciones; i++)
	{
		temp[i] = planesdevacaciones[i];
	}
	temp[numPlanesDeVacaciones] = plandevacaciones;
	numPlanesDeVacaciones++;
	delete[] planesdevacaciones;
	planesdevacaciones = temp;
}

int VectorPlanDeVacaciones::getNumPlanesDeVacaciones()
{
	return numPlanesDeVacaciones;
}

PlanDeVacaciones* VectorPlanDeVacaciones::obtenerDatosPlanDeVacaciones(int indice)
{
	if (indice < 0 || indice >= numPlanesDeVacaciones)
	{
		cout << endl << "Indice fuera de rango!!" << endl;
		return nullptr;
	}
	return planesdevacaciones[indice];
}