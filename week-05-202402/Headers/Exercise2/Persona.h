#pragma once
#include "iostream"

using namespace std;
using namespace System;

class Persona
{
protected:
	string nombre;
	string apellido;
	int edad;
	char sexo;

public:
	Persona(string nombre, string apellido, int edad, char sexo);
	string getNombre();
	string getApellido();
};

Persona::Persona(string nombre, string apellido, int edad, char sexo)
{
	this->nombre = nombre;
	this->apellido = apellido;
	this->edad = edad;
	this->sexo = sexo;
}

string Persona::getNombre()
{
	return nombre;
}

string Persona::getApellido()
{
	return apellido;
}