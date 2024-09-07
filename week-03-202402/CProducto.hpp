#pragma once
#include <iostream>
using namespace std;
class CProducto
{
private:
	long long codProducto, cantidad;
	float precio;
public:
	CProducto() {
		this->codProducto = rand() % (999999 - 10000 + 1) + 100000;
		this->cantidad = rand() % 20;
		this->precio = 100.0;
	}
	CProducto(float cantidad) {
		this->codProducto = rand() % (999999 - 10000 + 1) + 100000;
		this->cantidad = cantidad;
		this->precio = 100.0;
	}
	~CProducto() {}

	void mostrarDatos() {
		cout << "codProducot: " << this->codProducto << endl;
		cout << "Cantidad: " << this->cantidad << endl;
		cout << "Precio: " << this->precio << endl;
	}
	long long getCodProducto() {
		return this->codProducto;
	}
	long long getCantidad() {
		return this->cantidad;
	}
	void setCantidad(long long cantidad) {
		this->cantidad = cantidad;
	}
	CProducto* getDuplicado(int cantidad) {
		CProducto* nuevoProducto = new CProducto();
		nuevoProducto->codProducto = this->codProducto;
		nuevoProducto->precio = this->precio;
		nuevoProducto->cantidad = cantidad;
		return nuevoProducto;
	}
};