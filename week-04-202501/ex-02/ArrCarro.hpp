#pragma once
#include "Carro.hpp"

class ArrCarro
{
private:
	Carro** elementos;
	int cantidad;
public:
	ArrCarro() {
		elementos = nullptr;
		cantidad = 0;
	}
	~ArrCarro() {}

	void agregarElemento(Carro* pntrElemento) {
		Carro** tpm = new Carro * [cantidad + 1];
		for (int i = 0; i < cantidad; i++)
		{
			tpm[i] = elementos[i];
		}
		tpm[cantidad] = pntrElemento;

		delete[] elementos;
		elementos = tpm;
		cantidad++;
	}

	void pintarElementos() {
		for (int i = 0; i < cantidad; i++)
		{
			elementos[i]->dibujar();
		}
	}

	void animarElementos() {
		for (int i = 0; i < cantidad; i++)
		{
			elementos[i]->borrar();
			elementos[i]->mover();
			elementos[i]->dibujar();
		}
	}

	int getPosicionGanadora() {
		for (int i = 0; i < cantidad; i++)
		{
			if (elementos[i]->getDx() == 0) { // ya gano 
				return i;
			}
		}
		return -1;
	}

	int size() {
		return this->cantidad;
	}
};