#pragma once
#include <iostream>
using namespace std;
class CCliente
{
private:
	long long DNI;
	string nombre;
public:
	CCliente();
	~CCliente();
	void mostrarDatos();
};

CCliente::CCliente()
{
	this->DNI = rand() % (99999999 - 1000000 + 1) + 10000000;
	this->nombre = "test";
}

CCliente::~CCliente()
{
}

void CCliente::mostrarDatos() {
	cout << "DNI: " << this->DNI << " - ";
	cout << "Nombre: " << this->nombre << endl;
}