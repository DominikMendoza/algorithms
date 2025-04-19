#pragma once
#include "Proveedor.hpp"

class ArrProveedor
{
private:
	Proveedor** elementos;
	int cantidad;
public:
	ArrProveedor();
	~ArrProveedor();
	void agregarElemento(Proveedor* pntrElemento);
	void eliminarElementoEnPosicion(int pos);
	Proveedor* getElemento(int pos);
};

ArrProveedor::ArrProveedor() {
	elementos = nullptr;
	cantidad = 0;
}

ArrProveedor::~ArrProveedor() {}

void ArrProveedor::agregarElemento(Proveedor* pntrElemento) {
	Proveedor** tmp = new Proveedor * [cantidad + 1];
	for (int i = 0; i < cantidad; i++)
	{
		tmp[i] = elementos[i];
	}
	tmp[cantidad] = pntrElemento;

	delete[] elementos;
	elementos = tmp;
	cantidad++;
}

void ArrProveedor::eliminarElementoEnPosicion(int pos) {
	if (pos < 0 || pos >= cantidad) {
		cout << "Out of range\n";
		return;
	}

	Proveedor** tmp = new Proveedor * [cantidad - 1];

	int j = 0;
	for (int i = 0; i < cantidad; i++)
	{
		if (i != pos) {
			tmp[j] = elementos[i];
			j++;
		}
	}

	delete[] elementos;
	elementos = tmp;
	cantidad--;
}

Proveedor* ArrProveedor::getElemento(int pos) {
	if (pos < 0 || pos >= cantidad) {
		cout << "Out of range\n";
		return new Proveedor();
	}
	return elementos[pos];
}