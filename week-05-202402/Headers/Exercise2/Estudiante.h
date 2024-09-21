#pragma once
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
	string s;
	s = to_string(rand() % (99999999 - 10000000 + 1) + 10000000);
	return s;
}