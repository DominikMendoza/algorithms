#pragma once
#include "Fecha.h"

class Boleto
{
protected:
	string idBoleto;
	double precio;
	string destino;
	Fecha* fechaSalida;
	Fecha* fechaRegreso;

public:
	Boleto(string idBoleto, double precio, string destino, Fecha* fechaSalida, Fecha* fechaRegreso);
	~Boleto();
	void mostrarBoleto();
	string getIDBoleto();
};

Boleto::Boleto(string idBoleto, double precio, string destino, Fecha* fechaSalida, Fecha* fechaRegreso)
{
	this->idBoleto = idBoleto;
	this->precio = precio;
	this->destino = destino;
	this->fechaSalida = fechaSalida;
	this->fechaRegreso = fechaRegreso;
}

Boleto::~Boleto()
{
	if (fechaSalida != nullptr)
	{
		delete fechaSalida;
	}
	if (fechaRegreso != nullptr)
	{
		delete fechaRegreso;
	}
}

string Boleto::getIDBoleto()
{
	return idBoleto;
}

void Boleto::mostrarBoleto()
{
	cout << "ID Boleto: " << idBoleto << endl;
	cout << "Precio: S/." << precio << endl;
	cout << "Destino: " << destino << endl;
	cout << "Fecha Salida: " << fechaSalida->mostrarFecha() << endl;
	cout << "Fecha Regreso: " << fechaRegreso->mostrarFecha() << endl;
}