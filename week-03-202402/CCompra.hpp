#pragma once
#include "CCliente.hpp"
#include "CArrProducto.hpp"
class CCompra
{
private:
	long long idCompra;
	CCliente* cliente;
	CArrProducto* productos;
public:
	CCompra();
	~CCompra();
	void agregarProducto(CProducto* prod);
	void mostrarDatos();
};

CCompra::CCompra()
{
	this->idCompra = rand() % (999999 - 10000 + 1) + 100000;
	this->cliente = new CCliente();
	this->productos = new CArrProducto();
}

CCompra::~CCompra()
{
}

void CCompra::agregarProducto(CProducto* prod)
{
	productos->agregarElemento(prod);
}

void CCompra::mostrarDatos()
{
	cout << "DATOS DE LA COMPRA:\n";
	cout << "ID de la compra: " << this->idCompra << endl;
	cout << "Datos del cliente: ";
	this->cliente->mostrarDatos();
	cout << "Productos de la compra: ";
	this->productos->mostrarElementos();
	cout << "\n-----------------\n";

}
