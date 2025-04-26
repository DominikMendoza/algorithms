#pragma once
#include "Avion.hpp"

class ArrAvion
{
private:
	Avion** elementos;
	int cantidad;
public:
	ArrAvion() {
		elementos = nullptr;
		cantidad = 0;
	}
	~ArrAvion() {}

	void agregarElemento(Avion* pntrElemento) {
		Avion** tpm = new Avion * [cantidad + 1];
		for (int i = 0; i < cantidad; i++)
		{
			tpm[i] = elementos[i];
		}
		tpm[cantidad] = pntrElemento;

		delete[] elementos;
		elementos = tpm;
		cantidad++;
	}

	void animarAviones() {
		for (int i = 0; i < cantidad; i++)
		{
			elementos[i]->borrar();
			elementos[i]->mover();
			elementos[i]->dibujar();
		}
	}

	int size() {
		return this->cantidad;
	}
};