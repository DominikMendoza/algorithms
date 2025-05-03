#pragma once
#include "Ovni.hpp"

class ArrOvni
{
private:
	Ovni** elementos;
	int cantidad;
public:
	ArrOvni() {
		elementos = nullptr;
		cantidad = 0;
	}
	~ArrOvni() {}

	void agregarElemento(Ovni* pntrElemento) {
		Ovni** tpm = new Ovni * [cantidad + 1];
		for (int i = 0; i < cantidad; i++)
		{
			tpm[i] = elementos[i];
		}
		tpm[cantidad] = pntrElemento;

		delete[] elementos;
		elementos = tpm;
		cantidad++;
	}

	Ovni* getElemento(int pos) {
		return this->elementos[pos];
	}

	int size() {
		return this->cantidad;
	}
};