#pragma once
#include "Animal.h"
#include "Personal.h"

class Diagnostico
{
private:
	string fecha;
	string descripcion;
	Animal* animal;
	Personal* personal;

public:
	Diagnostico(string fecha, string descripcion, Animal* animal, Personal* personal);
	string getFecha();
	string getDescripcion();
	Animal* getAnimal();
	Personal* getPersonal();
	void setFecha(string fecha);
	void setDescripcion(string descripcion);
	void setAnimal(Animal* animal);
	void setPersonal(Personal* personal);
	void mostrarDiagnostico();
};

Diagnostico::Diagnostico(string fecha, string descripcion, Animal* animal, Personal* personal)
{
	this->fecha = fecha;
	this->descripcion = descripcion;
	this->animal = animal;
	this->personal = personal;
}

string Diagnostico::getFecha()
{
	return fecha;
}

string Diagnostico::getDescripcion()
{
	return descripcion;
}

Animal* Diagnostico::getAnimal()
{
	return animal;
}

Personal* Diagnostico::getPersonal()
{
	return personal;
}

void Diagnostico::setFecha(string fecha)
{
	this->fecha = fecha;
}

void Diagnostico::setDescripcion(string descripcion)
{
	this->descripcion = descripcion;
}

void Diagnostico::setAnimal(Animal* animal)
{
	this->animal = animal;
}

void Diagnostico::setPersonal(Personal* personal)
{
	this->personal = personal;
}

void Diagnostico::mostrarDiagnostico()
{
	animal->mostrarAnimal();
	cout << "Fecha Diagnostico: " << fecha << endl;
	cout << "Descripcion: " << descripcion << endl;
	cout << "DATOS PERSONAL" << endl;
	cout << "==============" << endl;
	personal->mostrarPersonal();
}