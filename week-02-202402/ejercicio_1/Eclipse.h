#pragma once
#include "iostream"
#include "string"

using namespace std;

class Eclipse
{
private:
	string tipo;
	string fecha;
	int hora;
	char sismos;
	char lluvias;
	string visibilidad;

public:
	Eclipse(string tipo, string fecha, int hora, char sismos, char lluvias, string visibilidad);
	string getTipo();
	string getFecha();
	int getHora();
	char getSismos();
	char getLluvias();
	string getVisibilidad();
	void setTipo(string tipo);
	void setFecha(string fecha);
	void setHora(int hora);
	void setSismos(char sismos);
	void setLluvias(char lluvias);
	void setVisibilidad(string visibilidad);
	void MostrarEclipse();
};

Eclipse::Eclipse(string tipo, string fecha, int hora, char sismos, char lluvias, string visibilidad)
{
	this->tipo = tipo;
	this->fecha = fecha;
	this->hora = hora;
	this->sismos = sismos;
	this->lluvias = lluvias;
	this->visibilidad = visibilidad;
}

string Eclipse::getTipo()
{
	return tipo;
}

string Eclipse::getFecha()
{
	return fecha;
}

int Eclipse::getHora()
{
	return hora;
}

char Eclipse::getSismos()
{
	return sismos;
}

char Eclipse::getLluvias()
{
	return lluvias;
}

string Eclipse::getVisibilidad()
{
	return visibilidad;
}

void Eclipse::setTipo(string tipo)
{
	this->tipo = tipo;
}

void Eclipse::setFecha(string fecha)
{
	this->fecha = fecha;
}

void Eclipse::setHora(int hora)
{
	this->hora = hora;
}

void Eclipse::setSismos(char sismos)
{
	this->sismos = sismos;
}

void Eclipse::setLluvias(char lluvias)
{
	this->lluvias = lluvias;
}

void Eclipse::setVisibilidad(string visibilidad)
{
	this->visibilidad = visibilidad;
}

void Eclipse::MostrarEclipse()
{
	cout << "Tipo de Eclipse: " << tipo << endl;
	cout << "Fecha: " << fecha << endl;
	cout << "Hora: " << hora << endl;
	cout << "Sismos: " << (sismos == 'S' ? "Si" : "No") << endl;
	cout << "Lluvias: " << (lluvias == 'S' ? "Si" : "No") << endl;
	cout << "Visibilidad: " << visibilidad << endl;
}