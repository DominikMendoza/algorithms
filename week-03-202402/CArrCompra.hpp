#pragma once
#include "CCompra.hpp"

class CArrCompra
{
private:
	CCompra** elementos;
	int cantidad;
public:
	CArrCompra() {
		elementos = nullptr;
		cantidad = 0;
	}
	~CArrCompra() {}

	void agregarElemento(CCompra* pntrElemento) {
		CCompra** tpm = new CCompra * [cantidad + 1];
		for (int i = 0; i < cantidad; i++)
		{
			tpm[i] = elementos[i];
		}
		tpm[cantidad] = pntrElemento;

		delete[] elementos;
		elementos = tpm;
		cantidad++;
	}

	void eliminarElementoEnPosicion(int pos) {
		if (pos < 0 || pos >= cantidad) {
			cout << "Out of range\n";
			return;
		}
		CCompra** tmp = new CCompra * [cantidad - 1];

		int j = 0;
		for (int i = 0; i < cantidad; i++)
		{
			if (i == pos) continue;
			tmp[j] = elementos[i];
			j++;
		}

		delete[] elementos;
		elementos = tmp;
		cantidad--;
	}

	CCompra* getElemento(int pos) {
		if (pos < 0 || pos >= cantidad) {
			cout << "Out of range\n";
			return new CCompra();
		}
		return elementos[pos];
	}

	void mostrarElementos() {
		cout << "-->Todos los elementos son los siguientes:\n";
		for (int i = 0; i < cantidad; i++)
		{
			cout << "Elemento n" << i + 1 << endl;
			elementos[i]->mostrarDatos();
			cout << endl;
		}
	}

	int size() {
		return this->cantidad;
	}
};