#pragma once
#include "iostream"
#include "string"
using namespace std;
//«mayor que» > y «menor que» <
class CFecha {
private:
	short dia, mes, anio;
public:
	CFecha() {
		this->dia = rand() % 29 + 1;
		this->mes = rand() % (12 - 1 + 1) + 12;
		this->anio = rand() % (2030 - 1950 + 1) + 1950;
	}
	CFecha(short dia, short mes, short anio) {
		this->dia = dia;
		this->mes = mes;
		this->anio = anio;
	}
	~CFecha(){		}

	//setters
	void setDia(short dia) {
		this->dia = dia;
	}
	void setMes(short mes) {
		this->mes = mes;
	}
	void setAnio(short anio) {
		this->anio = anio;
	}

	//getters
	short getDia() {
		return this->dia;
	}
	short getMes() {
		return this->mes;
	}
	short getAnio() {
		return this->anio;
	}

	//metodos
	void mostrarFecha() {
		cout << this->dia << "/" << this->mes << "/" << this->anio;
	}
};