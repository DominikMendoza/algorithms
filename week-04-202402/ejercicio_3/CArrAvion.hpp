#pragma once
#include "CAvion.hpp"

class CArrAvion
{
private:
	CAvion** elementos;
	int cantidad;
public:
	CArrAvion() {
		elementos = nullptr;
		cantidad = 0;
	}
	~CArrAvion() {}

	void agregarElemento(CAvion* pntrElemento) {
		CAvion** tpm = new CAvion * [cantidad + 1];
		for (int i = 0; i < cantidad; i++)
		{
			tpm[i] = elementos[i];
		}
		tpm[cantidad] = pntrElemento;

		delete[] elementos;
		elementos = tpm;
		cantidad++;
	}

	void animarElementos() {
		for (int i = 0; i < cantidad; i++)
		{
			elementos[i]->animar();
		}
	}

	int size() {
		return this->cantidad;
	}
};