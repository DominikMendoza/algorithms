#pragma once
#include "iostream"
#include "string"

using namespace std;

class Personal
{
private:
	string nombres;
	string apellidos;
	string fechaContratacion;

public:
	Personal(string nombres, string apellidos, string fechaContratacion);
	string getNombres();
	string getApellidos();
	string getfechaContratacion();
	void setNombres(string nombres);
	void setApellidos(string apellidos);
	void setFechaContratacion(string fechaContratacion);
	void mostrarPersonal();
};

Personal::Personal(string nombres, string apellidos, string fechaContratacion)
{
	this->nombres = nombres;
	this->apellidos = apellidos;
	this->fechaContratacion = fechaContratacion;
}

string Personal::getNombres()
{
	return nombres;
}

string Personal::getApellidos()
{
	return apellidos;
}

string Personal::getfechaContratacion()
{
	return fechaContratacion;
}

void Personal::setNombres(string nombres)
{
	this->nombres = nombres;
}

void Personal::setApellidos(string apellidos)
{
	this->apellidos = apellidos;
}

void Personal::setFechaContratacion(string fechaContratacion)
{
	this->fechaContratacion = fechaContratacion;
}

void Personal::mostrarPersonal()
{
	cout << "Nombres: " << nombres << endl;
	cout << "Apellidos: " << apellidos << endl;
	cout << "Fecha Contratacion: " << fechaContratacion << endl;
}