#pragma once
#include <iostream>
#include "CBoleto.hpp"
#include "CHotel.hpp"
using namespace std;
class CPlanVacacion : public CBoleto, public CHotel
{
private:
public:
	CPlanVacacion(string name, long long fecha);
	~CPlanVacacion();
	bool estaEnFecha(long long inicio, long long final);
	void mostrar();
};

CPlanVacacion::CPlanVacacion(string name, long long fecha) : CHotel(name), CBoleto(fecha)
{
}

CPlanVacacion::~CPlanVacacion()
{
}

bool CPlanVacacion::estaEnFecha(long long inicio, long long final)
{
	return this->getFecha() >= inicio && this->getFecha() <= final;
}

void CPlanVacacion::mostrar()
{
	cout << "Fecha Boleto: " << getFecha() << endl;
	cout << "Type: " << getType() << endl;
	cout << "Nombre Hotel: " << getName() << endl;
}
