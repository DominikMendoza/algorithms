#pragma once
#include "CCliente.hpp"

class CArrCliente
{
private:
	CCliente** elementos;
	int cantidad;
public:
	CArrCliente() {
		elementos = nullptr;
		cantidad = 0;
	}
	~CArrCliente() {}

	void agregarElemento(CCliente* pntrElemento) {
		CCliente** tpm = new CCliente * [cantidad + 1];
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
		CCliente** tmp = new CCliente * [cantidad - 1];

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

	CCliente* getElemento(int pos) {
		if (pos < 0 || pos >= cantidad) {
			cout << "Out of range\n";
			return new CCliente();
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
};