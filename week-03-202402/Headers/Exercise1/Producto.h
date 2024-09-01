#pragma once
#include "Proveedor.h"

using namespace std;

class Producto
{
private:
	int idproducto;
	string nombre;
	string tipo;
	int cantidad;
	char categoria;
	int a�o;
	double precio;
	Proveedor* proveedor;

public:
	Producto(int idproducto, string nombre, string tipo, int cantidad, char categoria, int a�o, double precio, Proveedor* proveedor);
	int getIDProducto();
	string getNombre();
	string getTipo();
	int getCantidad();
	char getCategoria();
	int getA�o();
	double getPrecio();
	Proveedor* getProveedor();
	void setIDProducto(int idproducto);
	void setNombre(string nombre);
	void setTipo(string tipo);
	void setCantidad(int cantidad);
	void setCategoria(char categoria);
	void setA�o(int a�o);
	void setPrecio(double precio);
	void setProveedor(Proveedor* proveedor);
	void mostrarProducto();
};

Producto::Producto(int idproducto, string nombre, string tipo, int cantidad, char categoria, int a�o, double precio, Proveedor* proveedor)
{
	this->idproducto = idproducto;
	this->nombre = nombre;
	this->tipo = tipo;
	this->cantidad = cantidad;
	this->categoria = categoria;
	this->a�o = a�o;
	this->precio = precio;
	this->proveedor = proveedor;
}

int Producto::getIDProducto()
{
	return idproducto;
}

string Producto::getNombre()
{
	return nombre;
}

string Producto::getTipo()
{
	return tipo;
}

int Producto::getCantidad()
{
	return cantidad;
}

char Producto::getCategoria()
{
	return categoria;
}

int Producto::getA�o()
{
	return a�o;
}

double Producto::getPrecio()
{
	return precio;
}

Proveedor* Producto::getProveedor()
{
	return proveedor;
}

void Producto::setIDProducto(int idproducto)
{
	this->idproducto = idproducto;
}

void Producto::setNombre(string nombre)
{
	this->nombre = nombre;
}

void Producto::setTipo(string tipo)
{
	this->tipo = tipo;
}

void Producto::setCantidad(int cantidad)
{
	this->cantidad = cantidad;
}

void Producto::setCategoria(char categoria)
{
	this->categoria = categoria;
}

void Producto::setA�o(int a�o)
{
	this->a�o = a�o;
}

void Producto::setPrecio(double precio)
{
	this->precio = precio;
}

void Producto::setProveedor(Proveedor* proveedor)
{
	this->proveedor = proveedor;
}

void Producto::mostrarProducto()
{
	cout << "IdProducto: " << idproducto << endl;
	cout << "Nombre: " << nombre << endl;
	cout << "Tipo (polvo o liquido): " << tipo << endl;
	cout << "Cantidad: " << cantidad << endl;
	cout << "Categoria: " << categoria << endl;
	cout << "Year: " << a�o << endl;
	cout << "Precio: S/." << precio << endl;
	cout << "DATOS PROVEEDOR:" << endl;
	cout << "================" << endl;
	proveedor->mostrarProveedor();
	cout << endl;
}