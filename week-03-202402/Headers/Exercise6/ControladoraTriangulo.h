#pragma once
#include "TEquilatero.h"
#include "TRectangulo.h"

class Controladora
{
private:
	TEquilatero* te;
	TRectangulo* tr;

public:
	Controladora();
	~Controladora();
	void TrianguloEquilateroHorario();
	void TrianguloRectanguloHorario();
};

Controladora::Controladora()
{
	te = nullptr;
	tr = nullptr;
}

Controladora::~Controladora()
{
	delete te;
	delete tr;
}

void Controladora::TrianguloEquilateroHorario()
{
	int lado;
	char caracter;
	do
	{
		cout << "Ingrese el lado: "; cin >> lado;
	} while (lado < 5 || lado > 100);
	cout << "Ingrese el caracter: "; cin >> caracter;
	te = new TEquilatero(caracter, lado);
	system("cls");
	te->RealizarProcedimientoTE();
}

void Controladora::TrianguloRectanguloHorario()
{
	int lado1;
	int lado2;
	char caracter;
	do
	{
		cout << "Ingrese el lado1: "; cin >> lado1;
	} while (lado1 < 5 || lado1 > 100);
	/*do
	{
		cout << "Ingrese el lado2: "; cin >> lado2;
	} while (lado2 < 5 || lado2 > 100);*/
	cout << "Ingrese el caracter: "; cin >> caracter;
	tr = new TRectangulo(caracter, lado1);
	/*tr = new TRectangulo(caracter,lado1,lado2);*/
	system("cls");
	tr->RealizarProcedimientoTR();
}