#pragma once
#include "CProducto.hpp"

class CArrProducto
{
private:
	CProducto** elementos;
	int cantidad;
public:
	CArrProducto() {
		elementos = nullptr;
		cantidad = 0;
	}
	~CArrProducto() {}

	void agregarElemento(CProducto* pntrElemento) {
		CProducto** tpm = new CProducto * [cantidad + 1];
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
		CProducto** tmp = new CProducto * [cantidad - 1];

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

	CProducto* getElemento(int pos) {
		if (pos < 0 || pos >= cantidad) {
			cout << "Out of range\n";
			return new CProducto();
		}
		return elementos[pos];
	}

	CProducto* getElementoByCode(long long codigo) {
		for (int i = 0; i < cantidad; i++)
		{
			if (elementos[i]->getCodProducto() == codigo) {
				return elementos[i];
			}
		}
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