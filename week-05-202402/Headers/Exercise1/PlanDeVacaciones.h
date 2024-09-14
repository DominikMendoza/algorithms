#pragma once
#include "Hotel.h"
#include "Boleto.h"

class PlanDeVacaciones : public Boleto, public Hotel
{
private:

public:
	PlanDeVacaciones(string idBoleto, double precio, string destino, Fecha* fechaSalida, Fecha* fechaRegreso, string nombre, string ubicacion, int numHabitaciones, int numHabitacionesDisponibles);
	void mostrarPlan();
	static bool esMenorIgual(Fecha* f1, Fecha* f2);
	bool estaDentroDeRangoFechas(Fecha* inicio, Fecha* fin);
};

PlanDeVacaciones::PlanDeVacaciones(string idBoleto, double precio, string destino, Fecha* fechaSalida, Fecha* fechaRegreso, string nombre, string ubicacion, int numHabitaciones, int numHabitacionesDisponibles) : Boleto(idBoleto, precio, destino, fechaSalida, fechaRegreso), Hotel(nombre, ubicacion, numHabitaciones, numHabitacionesDisponibles) {}

void PlanDeVacaciones::mostrarPlan()
{
	mostrarBoleto();
	cout << "DATOS HOTEL HOSPEDAJE: " << endl;
	cout << "=====================" << endl;
	mostrarHotel();
}

bool PlanDeVacaciones::esMenorIgual(Fecha* f1, Fecha* f2)
{
	if (f1->getYear() < f2->getYear()) return true;
	if (f1->getYear() > f2->getYear()) return false;
	if (f1->getMonth() < f2->getMonth()) return true;
	if (f1->getMonth() > f2->getMonth()) return false;
	return f1->getDay() <= f2->getDay();
}

bool PlanDeVacaciones::estaDentroDeRangoFechas(Fecha* inicio, Fecha* fin)
{
	return esMenorIgual(inicio, fechaSalida) && esMenorIgual(fechaRegreso, fin);
}