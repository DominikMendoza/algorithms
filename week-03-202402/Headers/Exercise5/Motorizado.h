#pragma once
#include "iostream"
#include "string"

using namespace std;

class Motorizado
{
private:
	string nombre;
	string apellido;
	string placa;
	int kilometraje;
	string empresa;

public:
	Motorizado(string nombre, string apellido, string placa, int kilometraje, string empresa);
	double Precio();
	string getNombre();
	string getApellido();
	int getKilometraje();
	string getEmpresa();
	string getPlaca();
	void setNombre(string nombre);
	void setApellido(string apellido);
	void setKilometraje(int kilometraje);
	void setEmpresa(string empresa);
	void setPlaca(string placa);
	void mostrarMotorizado();
};

Motorizado::Motorizado(string nombre, string apellido, string placa, int kilometraje, string empresa)
{
	this->nombre = nombre;
	this->apellido = apellido;
	this->placa = placa;
	this->kilometraje = kilometraje;
	this->empresa = empresa;
}

double Motorizado::Precio()
{
	return 1.5 * kilometraje;
}

string Motorizado::getNombre()
{
	return nombre;
}

string Motorizado::getApellido()
{
	return apellido;
}

int Motorizado::getKilometraje()
{
	return kilometraje;
}

string Motorizado::getEmpresa()
{
	return empresa;
}

string Motorizado::getPlaca()
{
	return placa;
}

void Motorizado::setNombre(string nombre)
{
	this->nombre = nombre;
}

void Motorizado::setApellido(string apellido)
{
	this->apellido = apellido;
}

void Motorizado::setKilometraje(int kilometraje)
{
	this->kilometraje = kilometraje;
}

void Motorizado::setEmpresa(string empresa)
{
	this->empresa = empresa;
}

void Motorizado::setPlaca(string placa)
{
	this->placa = placa;
}

void Motorizado::mostrarMotorizado()
{
	cout << "Nombre: " << nombre << endl;
	cout << "Apellido: " << apellido << endl;
	cout << "Placa: " << placa << endl;
	cout << "Kilometraje: " << kilometraje << endl;
	cout << "Precio: S/" << Precio() << endl;
	cout << "Empresa: " << empresa << endl;
}