#pragma once
#include "Hotel.hpp"
#include "Boleto.hpp"
class PlanVacacion : public Boleto, public Hotel
{
public:
	PlanVacacion(int fecha, string nombreHotel);
	~PlanVacacion();
	void mostrarPlan();
	int getFechaBoleto();
	string getNombreHotel();
private:

};

PlanVacacion::PlanVacacion(int fecha, string nombreHotel) :
	Boleto(fecha), Hotel(nombreHotel)
{
}

PlanVacacion::~PlanVacacion()
{
}

void PlanVacacion::mostrarPlan()
{
	this->mostrarBoleto();
	this->mostrarHotel();
	cout << endl;
}

int PlanVacacion::getFechaBoleto()
{
	return this->fecha;
}

string PlanVacacion::getNombreHotel()
{
	return this->nombre;
}
