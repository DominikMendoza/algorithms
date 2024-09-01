#pragma once
#include "iostream"
#include "string"

using namespace std;

class Cliente
{
private:
	string DNI;
	string nombre;

public:
	Cliente(string DNI, string nombre);
	string getDNI();
	string getNombre();
	void setDNI(string DNI);
	void setNombre(string nombre);
	void mostrarCliente();
};

Cliente::Cliente(string DNI, string nombre)
{
	this->DNI = DNI;
	this->nombre = nombre;
}

string Cliente::getDNI()
{
	return DNI;
}

string Cliente::getNombre()
{
	return nombre;
}

void Cliente::setDNI(string DNI)
{
	this->DNI = DNI;
}

void Cliente::setNombre(string nombre)
{
	this->nombre = nombre;
}

void Cliente::mostrarCliente()
{
	cout << "DNI: " << DNI << endl;
	cout << "Nombre: " << nombre << endl;
}