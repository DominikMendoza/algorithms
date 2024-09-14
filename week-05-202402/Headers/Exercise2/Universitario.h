#pragma once
#include "vector"
#include "Estudiante.h"

class Universitario : public Estudiante
{
protected:
	string nombreU;
	string carrera;
	vector<string> materias;
	vector<double> notas;
	
public:
	Universitario(string nombre, string apellido, int edad, char sexo, string nivelEstudios, string nombreU, string carrera);
	void agregarMateria(string materia, double nota);
	double getPromedioNotas();
	string getUniversidad();
};

Universitario::Universitario(string nombre, string apellido, int edad, char sexo, string nivelEstudios, string nombreU, string carrera) : Estudiante(nombre, apellido, edad, sexo, nivelEstudios)
{
	this->nombreU = nombreU;
	this->carrera = carrera;
}

void Universitario::agregarMateria(string materia, double nota)
{
	materias.push_back(materia);
	notas.push_back(nota);
}

double Universitario::getPromedioNotas()
{
	if (notas.empty())
	{
		return 0.0;
	}
	double suma = 0;
	for (int i = 0; i < notas.size(); i++)
	{
		suma += notas[i];
	}
	return suma / notas.size();
}

string Universitario::getUniversidad()
{
	return nombreU;
}