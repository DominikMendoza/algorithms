#pragma once
#include "sstream"
#include "Persona.h"

class Estudiante : public Persona
{
protected:
	string DNI;
	string nivelEstudios;

public:
	Estudiante(string nombre, string apellido, int edad, char sexo, string nivelEstudios);
	string generarDNI();
};

Estudiante::Estudiante(string nombre, string apellido, int edad, char sexo, string nivelEstudios) : Persona(nombre, apellido, edad, sexo)
{
	this->nivelEstudios = nivelEstudios;
	DNI = generarDNI();
}

string Estudiante::generarDNI()
{
	stringstream ss;
	for (int i = 0; i < 8; i++)
	{
		ss << rand() % 10;
	}
	return ss.str();
}