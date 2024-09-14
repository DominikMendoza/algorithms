#pragma once
#include "iostream"
#include "string"

using namespace std;

class Hotel
{
protected:
	string nombre;
	string ubicacion;
	int numHabitaciones;
	int numHabitacionesDisponibles;

public:
	Hotel(string nombre, string ubicacion, int numHabitaciones, int numHabitacionesDisponibles);
	void mostrarHotel();
	string getNombreHotel();
};

Hotel::Hotel(string nombre, string ubicacion, int numHabitaciones, int numHabitacionesDisponibles)
{
	this->nombre = nombre;
	this->ubicacion = ubicacion;
	this->numHabitaciones = numHabitaciones;
	this->numHabitacionesDisponibles = numHabitacionesDisponibles;
}

void Hotel::mostrarHotel()
{
	cout << "Nombre del Hotel: " << nombre << endl;
	cout << "Ubicacion: " << ubicacion << endl;
	cout << "Numero de Habitaciones: " << numHabitaciones << endl;
	cout << "Numero de Habitaciones disponibles: " << numHabitacionesDisponibles << endl;
}

string Hotel::getNombreHotel()
{
	return nombre;
}