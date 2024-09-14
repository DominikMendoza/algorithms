#pragma once
#include "Universitario.h"
#include "Empleado.h"

class Pasante : public Universitario, public Empleado
{
private:
	string nombreProyecto;
	int totalHoras;
	int numeroHorasCompletas;

public:
	Pasante(string nombre, string apellido, int edad, char sexo, string nivelEstudios, string nombreU, string carrera, string posicion, double salario, string nombreProyecto, int totalHoras, int numeroHorasCompletas);
	void mostrarPasante();
};

Pasante::Pasante(string nombre, string apellido, int edad, char sexo, string nivelEstudios, string nombreU, string carrera, string posicion, double salario, string nombreProyecto, int totalHoras, int numeroHorasCompletas) : Universitario(nombre, apellido, edad, sexo, nivelEstudios, nombreU, carrera), Empleado(nombre, apellido, edad, sexo, posicion, salario)
{
	this->nombreProyecto = nombreProyecto;
	this->totalHoras = totalHoras;
	this->numeroHorasCompletas = numeroHorasCompletas;
}

void Pasante::mostrarPasante()
{
	cout << "Nombre: " << Persona::nombre << endl;
	cout << "Apellido: " << Persona::apellido << endl;
	cout << "DNI: " << DNI << endl;
	cout << "Edad: " << Persona::edad << endl;
	cout << "Sexo: " << (Persona::sexo == 'H' ? "Hombre" : "Mujer") << endl;
	cout << "Nivel de Estudios: " << nivelEstudios << endl;
	cout << "Nombre Universidad: " << nombreU << endl;
	cout << "Carrera: " << carrera << endl;
	cout << "Posicion Empleo: " << posicion << endl;
	cout << "Salario: S/." << salario << endl;
	cout << "Nombre Proyecto: " << nombreProyecto << endl;
	cout << "Duracion Pasantia (en horas): " << totalHoras << endl;
	cout << "Numero Horas Completadas: " << numeroHorasCompletas << endl;
}