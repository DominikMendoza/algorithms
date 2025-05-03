#pragma once
#include <iostream>
using namespace std;
class Boleto
{
protected:
	int fecha;
public:
	Boleto(int fecha);
	~Boleto();
	void mostrarBoleto();
};

Boleto::Boleto(int fecha)
{
	this->fecha = fecha;
}

Boleto::~Boleto()
{
}

void Boleto::mostrarBoleto()
{
	cout << "Informacion del boleto" << endl;
	cout << "Fecha: " << fecha << endl;
}
