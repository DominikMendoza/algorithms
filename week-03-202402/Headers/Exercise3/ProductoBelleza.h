#pragma once
#include "iostream"
#include "string"

using namespace std;

class Producto
{
private:
	int codProducto;
	string nombre;
	string tipo;
	string marca;
	int cantidad;
	double precio;

public:
	Producto(int codProducto, string nombre, string tipo, string marca, int cantidad, double precio);
	int getCodProducto();
	string getNombre();
	string getTipo();
	string getMarca();
	int getCantidad();
	double getPrecio();
	void setCodProducto(int codProducto);
	void setNombre(string nombre);
	void setTipo(string tipo);
	void setMarca(string marca);
	void setCantidad(int cantidad);
	void setPrecio(double precio);
	void mostrarProducto();
};

Producto::Producto(int codProducto, string nombre, string tipo, string marca, int cantidad, double precio)
{
	this->codProducto = codProducto;
	this->nombre = nombre;
	this->tipo = tipo;
	this->marca = marca;
	this->cantidad = cantidad;
	this->precio = precio;
}

int Producto::getCodProducto()
{
	return codProducto;
}

string Producto::getNombre()
{
	return nombre;
}

string Producto::getTipo()
{
	return tipo;
}

string Producto::getMarca()
{
	return marca;
}

int Producto::getCantidad()
{
	return cantidad;
}

double Producto::getPrecio()
{
	return precio;
}

void Producto::setCodProducto(int codProducto)
{
	this->codProducto = codProducto;
}

void Producto::setNombre(string nombre)
{
	this->nombre = nombre;
}

void Producto::setTipo(string tipo)
{
	this->tipo = tipo;
}

void Producto::setMarca(string marca)
{
	this->marca = marca;
}

void Producto::setCantidad(int cantidad)
{
	this->cantidad = cantidad;
}

void Producto::setPrecio(double precio)
{
	this->precio = precio;
}

void Producto::mostrarProducto()
{
	cout << "Codigo Producto: " << codProducto << endl;
	cout << "Nombre: " << nombre << endl;
	cout << "Tipo: " << tipo << endl;
	cout << "Marca: " << marca << endl;
	cout << "Cantidad: " << cantidad << endl;
	cout << "Precio (c/u): S/." << precio << endl;
}