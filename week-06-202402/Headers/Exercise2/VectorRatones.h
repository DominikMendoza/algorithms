#pragma once
#include "Raton.h"

class VectorRatones
{
private:
	vector<Raton*> ratones;

public:
	VectorRatones();
	~VectorRatones();
	void AgregarRaton(Raton* nuevoRaton);
	void EliminarRaton(int indice);
	Raton* obtenerRaton(int indice);
	int getCantidadRatones();
};

VectorRatones::VectorRatones() {}

VectorRatones::~VectorRatones()
{
	for (int i = 0; i < ratones.size(); i++)
	{
		delete ratones[i];
	}
	ratones.clear();
}

void VectorRatones::AgregarRaton(Raton* nuevoRaton)
{
	ratones.push_back(nuevoRaton);
}

void VectorRatones::EliminarRaton(int indice)
{
	if (indice >= 0 && indice < ratones.size())
	{
		delete ratones[indice];
		ratones.erase(ratones.begin() + indice);
	}
}

Raton* VectorRatones::obtenerRaton(int indice)
{
	if (indice >= 0 && indice < ratones.size()) {
		return ratones[indice];
	}
	return nullptr;
}

int VectorRatones::getCantidadRatones()
{
	return ratones.size();
}