#pragma once
#include "Persona.h"

class Empleado : public Persona
{
protected:
	string posicion;
	double salario;

public:
	Empleado(string nombre, string apellido, int edad, char sexo, string posicion, double salario);
};

Empleado::Empleado(string nombre, string apellido, int edad, char sexo, string posicion, double salario) : Persona(nombre, apellido, edad, sexo)
{
	this->posicion = posicion;
	this->salario = salario;
}