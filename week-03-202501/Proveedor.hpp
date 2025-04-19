#pragma once
#include <iostream>
#include <string>
using namespace std;
class Proveedor
{
private:
	long long ruc;
	string razonSocial;
	char categoria;
	string direccion;
	int telefono;
public:
	Proveedor();
	Proveedor(string razonSocial);
	~Proveedor();
	void mostrar();
	string getRazonSocial();
	long long getRuc();
	void setRazonSocial(string razonSocial);
};

Proveedor::Proveedor()
{
	ruc = rand() % (9999999999 - 1000000000 + 1) + 1000000000;
	razonSocial = "Prov-default";
	categoria = 'X';
	direccion = "Groove s";
	telefono = 999999999;
}

Proveedor::Proveedor(string razonSocial)
{
	ruc = rand() % (9999999999 - 1000000000 + 1) + 1000000000;
	this->razonSocial = razonSocial;
	categoria = 'X';
	direccion = "Groove s";
	telefono = 999999999;
}

Proveedor::~Proveedor()
{
}

void Proveedor::mostrar()
{
	cout << "Ruc: " << ruc << endl;
	cout << "Razon social: " << razonSocial << endl;
	cout << "Categoria: " << categoria << endl;
	cout << "Direccion: " << direccion << endl;
	cout << "Telefono: " << telefono << endl << endl;
}

string Proveedor::getRazonSocial()
{
	return this->razonSocial;
}

long long Proveedor::getRuc()
{
	return this->ruc;
}

void Proveedor::setRazonSocial(string razonSocial)
{
	this->razonSocial = razonSocial;
}
