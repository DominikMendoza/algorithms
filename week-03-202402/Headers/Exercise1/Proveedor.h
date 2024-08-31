#pragma once
#include "iostream"
#include "string"

using namespace std;

class Proveedor
{
private:
	long long ruc;
	string nombre;
	string categoria;
	string direccion;
	long long telefono;

public:
	Proveedor(long long ruc, string nombre, string categoria, string direccion, long long telefono);
	long long getRuc();
	string getNombre();
	string getCategoria();
	string getDireccion();
	long long getTelefono();
	void mostrarProveedor();
};

Proveedor::Proveedor(long long ruc, string nombre, string categoria, string direccion, long long telefono)
{
	this->ruc = ruc;
	this->nombre = nombre;
	this->categoria = categoria;
	this->direccion = direccion;
	this->telefono = telefono;
}

long long Proveedor::getRuc()
{
	return ruc;
}

string Proveedor::getNombre()
{
	return nombre;
}

string Proveedor::getCategoria()
{
	return categoria;
}

string Proveedor::getDireccion()
{
	return direccion;
}

long long Proveedor::getTelefono()
{
	return telefono;
}

void Proveedor::mostrarProveedor()
{
	cout << "Ruc: " << ruc << endl;
	cout << "Nombre: " << nombre << endl;
	cout << "Categoria: " << categoria << endl;
	cout << "Direccion: " << direccion << endl;
	cout << "Telefono: " << telefono << endl;
}