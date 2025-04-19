#pragma once
#include "Producto.hpp"

class ArrProducto
{
private:
	Producto** elementos;
	int cantidad;
public:
	ArrProducto();
	~ArrProducto();
	void agregarElemento(Producto* pntrElemento);
	void eliminarElementoEnPosicion(int pos);
	Producto* getElemento(int pos);
	void mostrarTodos();
	void mostrarCategoriaAProvNatura();
	void eliminarProvHerbalife();
	void eliminarVencidos();
	void modificarUltimoElemento();
};

ArrProducto::ArrProducto() {
	elementos = nullptr;
	cantidad = 0;
}

ArrProducto::~ArrProducto() {}

void ArrProducto::agregarElemento(Producto* pntrElemento) {
	Producto** tmp = new Producto * [cantidad + 1];
	for (int i = 0; i < cantidad; i++)
	{
		tmp[i] = elementos[i];
	}
	tmp[cantidad] = pntrElemento;

	delete[] elementos;
	elementos = tmp;
	cantidad++;
}

void ArrProducto::eliminarElementoEnPosicion(int pos) {
	// 0 -> cantidad - 1
	if (pos < 0 || pos >= cantidad) {
		cout << "Out of range\n";
		return;
	}

	Producto** tmp = new Producto * [cantidad - 1];

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
	//cantidad = cantidad - 1;
	cantidad--;
}

Producto* ArrProducto::getElemento(int pos) {
	if (pos < 0 || pos >= cantidad) {
		cout << "Out of range\n";
		return new Producto();
	}
	return elementos[pos];
}

void ArrProducto::mostrarTodos()
{
	for (int i = 0; i < cantidad; i++)
	{
		cout << "Producto " << i + 1 << ":\n";
		elementos[i]->mostrar();
	}
}

void ArrProducto::mostrarCategoriaAProvNatura()
{
	for (int i = 0; i < cantidad; i++)
	{
		Producto* prod = elementos[i];

		if (prod->getProveedor() == nullptr) {
			continue;
		}

		if (prod->getCategoria() == 'A' &&
			prod->getProveedor()->getRazonSocial() == "Natura") {
			prod->mostrar();
		}
	}
}

void ArrProducto::eliminarProvHerbalife()
{
	for (int i = 0; i < cantidad; i++)
	{
		Producto* prod = elementos[i];

		if (prod->getProveedor() == nullptr) {
			continue;
		}

		if (prod->getProveedor()->getRazonSocial() == "Herbalife") {
			eliminarElementoEnPosicion(i);
			i--;
		}
	}
}

void ArrProducto::eliminarVencidos()
{
	for (int i = 0; i < cantidad; i++)
	{
		Producto* prod = elementos[i];
		if (prod->getAnio() < 2020) {
			eliminarElementoEnPosicion(i);
			i--;
		}
	}
}

void ArrProducto::modificarUltimoElemento()
{
	elementos[cantidad - 1]->modificarProducto();
}
