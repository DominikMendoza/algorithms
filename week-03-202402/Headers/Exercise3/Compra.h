#pragma once
#include "iostream"
#include "VectorProductosBelleza.h"
#include "Cliente.h"

using namespace std;

class Compra
{
private:
	long long idCompra;
	string fecha;
	Cliente* cliente;
	VectorProductos* productos;

public:
	Compra(long long idCompra, string fecha, Cliente* cliente);
	~Compra();
	void agregarProducto(Producto* producto, int cantidadComprada);
	long long getIDCompra();
	string getFecha();
	Cliente* getCliente();
	VectorProductos* getProductos();
	void setIDCompra(long long idCompra);
	void setFecha(string fecha);
	void setCliente(Cliente* cliente);
	void setProductos(VectorProductos* productos);
	void mostrarCompra();
};

Compra::Compra(long long idCompra, string fecha, Cliente* cliente)
{
	this->idCompra = idCompra;
	this->fecha = fecha;
	this->cliente = cliente;
	productos = new VectorProductos();
}

Compra::~Compra()
{
	delete productos;
}

void Compra::agregarProducto(Producto* producto, int cantidadComprada)
{
	Producto* productoComprado = new Producto(producto->getCodProducto(), producto->getNombre(), producto->getTipo(), producto->getMarca(), cantidadComprada, producto->getPrecio());
	productos->agregarProducto(productoComprado);
}

long long Compra::getIDCompra()
{
	return idCompra;
}

string Compra::getFecha()
{
	return fecha;
}

Cliente* Compra::getCliente()
{
	return cliente;
}

VectorProductos* Compra::getProductos()
{
	return productos;
}

void Compra::setIDCompra(long long idCompra)
{
	this->idCompra = idCompra;
}

void Compra::setFecha(string fecha)
{
	this->fecha = fecha;
}

void Compra::setCliente(Cliente* cliente)
{
	this->cliente = cliente;
}

void Compra::setProductos(VectorProductos* productos)
{
	this->productos = productos;
}

void Compra::mostrarCompra()
{
	cout << "ID Compra: " << idCompra << endl;
	cout << "Fecha: " << fecha << endl;
	cout << "DATOS CLIENTE:" << endl;
	cout << "==============" << endl;
	cliente->mostrarCliente();
	cout << "PRODUCTOS COMPRADOS:" << endl;
	cout << "=====================" << endl;
	double total = 0;
	if (productos->getNumProductos() == 0)
	{
		cout << "No realizo ninguna compra." << endl;
	}
	else
	{
		for (int i = 0; i < productos->getNumProductos(); i++)
		{
			Producto* prod = productos->getDatosProducto(i);
			prod->mostrarProducto();
			total += prod->getCantidad() * prod->getPrecio();
		}
		cout << "=====================" << endl;
		cout << "Total gastado: S/." << total << endl;
	}
}