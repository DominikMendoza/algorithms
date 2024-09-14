#pragma once
#include <iostream>
using namespace std;
class CFecha
{
private:
	int dia, mes, anio;
public:
	CFecha() {
		this->dia = rand() % 29 + 1;
		this->mes = rand() % (2) + 5;
		this->anio = rand() % (2030 - 2000 + 1) + 2000;
	}
	CFecha(int dia, int mes, int anio) {
		this->dia = dia;
		this->mes = mes;
		this->anio = anio;
	}
	~CFecha() {}

	void mostrarFecha() {
		cout << dia << "/" << mes << "/" << anio << endl;
	}
	void setDia(int dia) {
		this->dia = dia;
	}
	void setMes(int mes) {
		this->mes = mes;
	}
	void setAnio(int anio) {
		this->anio = anio;
	}
	int getDia() {
		return this->dia;
	}
	int getMes() {
		return this->mes;
	}
	int getAnio() {
		return this->anio;
	}
};