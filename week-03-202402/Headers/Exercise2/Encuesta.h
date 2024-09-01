#pragma once
#include "DNI.h"
#include "Leche.h"

class Encuesta
{
private: 
	DNI* dni;
	Leche* leche;

public:
	Encuesta();
	string getDNI();
	void mostrarEncuesta();
};

Encuesta::Encuesta()
{
	dni = new DNI();
	leche = new Leche();
}

string Encuesta::getDNI()
{
	return dni->getNumero();
}

void Encuesta::mostrarEncuesta()
{
	cout << dni->getNumero() << " - " << leche->getTipo() << endl;
}