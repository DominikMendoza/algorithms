#pragma once
#include <iostream>
using namespace std;
class Hotel
{
protected:
	string nombre;
public:
	Hotel();
	Hotel(string nombre);
	~Hotel();
	void mostrarHotel();
};

Hotel::Hotel()
{
	nombre = "-";
}

Hotel::Hotel(string nombre)
{
	this->nombre = nombre;
}

Hotel::~Hotel()
{
}

void Hotel::mostrarHotel()
{
	cout << "Informacion del hotel" << endl;
	cout << "Nombre: " << nombre << endl;
}
