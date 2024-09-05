#pragma once
#include "CFecha.hpp"
class CContacto
{
private:
	string nombre, sexo, facultad, email, redSocial;
	CFecha* nacimiento;
	long long telefono;
public:
	CContacto() {
		this->nombre = this->sexo = this->facultad = "--test--";
		this->email = this->redSocial = "--test--";
		this->nacimiento = new CFecha();
		telefono = rand() % (999999999 - 900000000 + 1) + 900000000;
	}
	~CContacto() {

	}

	void mostrarDatos() {
		cout << "Nombre: " << nombre << endl;
		cout << "redSocial: " << redSocial << endl;
		cout << "Telefono: " << telefono << endl;
		cout << "Fecha de nacimiento: ";
		nacimiento->mostrarFecha();
	}

	CFecha* getNacimiento() {
		return this->nacimiento;
	}
};