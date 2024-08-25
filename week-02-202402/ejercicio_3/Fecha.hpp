#pragma once
#include <iostream>
using namespace std;

class Fecha
{
private:
	int dia, mes, anio;
public:
	Fecha();
	Fecha(int, int, int);
	
	//MOSTRAR
	void MOSTRAR();
	// Declaraciones de los setters
	void setDia(int d);
	void setMes(int m);
	void setAnio(int a);

	// Declaraciones de los getters
	int getDia();
	int getMes();
	int getAnio();
};

Fecha::Fecha()
{
	dia = rand() % 29+1;
	mes = rand() % (2)+5 ;
	anio = rand() % (2030 - 2000 + 1) + 2000;
}

Fecha::Fecha(int D, int M , int A)
{
	dia = D;
	mes = M;
	anio = A;
}
//MOSTRAR
void Fecha::MOSTRAR() {

	cout << dia << '/' << mes << '/' << anio;
}

// Definiciones de los setters
void Fecha::setDia(int d) {
	dia = d;
}

void Fecha::setMes(int m) {
	mes = m;
}

void Fecha::setAnio(int a) {
	anio = a;
}

// Definiciones de los getters
int Fecha::getDia() {
	return dia;
}

int Fecha::getMes() {
	return mes;
}

int Fecha::getAnio() {
	return anio;
}