#pragma once
#include "iostream"
#include "string"

using namespace std;

class Animal
{
private:
	string tipo;
	string nombre;
	int edad;
	bool diagnosticado;

public:
	Animal(string tipo, string nombre, int edad);
	string getTipo();
	string getNombre();
	bool esDiagnosticado();
	int getEdad();
	void setDiagnosticado(bool diagnosticado);
	void setTipo(string tipo);
	void setNombre(string nombre);
	void setEdad(int edad);
	void mostrarAnimal();
};

Animal::Animal(string tipo, string nombre, int edad)
{
	this->tipo = tipo;
	this->nombre = nombre;
	this->edad = edad;
	diagnosticado = false;
}

string Animal::getTipo()
{
	return tipo;
}

string Animal::getNombre()
{
	return nombre;
}

int Animal::getEdad()
{
	return edad;
}

void Animal::setTipo(string tipo)
{
	this->tipo = tipo;
}

void Animal::setNombre(string nombre)
{
	this->nombre = nombre;
}

void Animal::setEdad(int edad)
{
	this->edad = edad;
}

bool Animal::esDiagnosticado()
{
	return diagnosticado;
}

void Animal::setDiagnosticado(bool diagnosticado)
{
	this->diagnosticado = diagnosticado;
}

void Animal::mostrarAnimal()
{
	cout << "Tipo: " << tipo << endl;
	cout << "Nombre: " << nombre << endl;
	cout << "Edad: " << edad << endl;
}