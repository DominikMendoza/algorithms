#pragma once
#include "CFecha.hpp"
//«mayor que» > , «menor que» < y la barra(\ y / )
class CContacto {
private:
	string nombre;
	int telefono;
	string sexo;
	string facultad;
	CFecha* fechaDeNacimiento;
	string email;
	string redSocial;

public:
	CContacto() {
		this->nombre = this->sexo = this->facultad = "--test--";
		this->email = this->redSocial = "--test--";
		this->fechaDeNacimiento = new CFecha();
		telefono = rand() % (999999999 - 900000000 + 1) + 900000000;
	}
	CContacto(string nombre, int telefono, string sexo, string facultad, CFecha* fechaDeNacimiento, string email, string redSocial) {
		this->nombre = nombre;
		this->sexo = sexo;
		this->facultad = facultad;
		this->email = email;
		this->redSocial = redSocial;
		this->fechaDeNacimiento = fechaDeNacimiento;
		this->telefono = telefono;
	}
	~CContacto(){		}
	
	//metodos
	void mostrarDatos() {
		cout << "\nNombre: " << nombre;
		cout << "\nTelefono: " << telefono;
		cout << "\nSexo: " << sexo;
		cout << "\nFacultad: " << facultad;
		cout << "\nRed Social: " << redSocial;
		cout << "\nEmail: " << redSocial;
		cout << "\nFecha de nacimiento: ";
		fechaDeNacimiento->mostrarFecha();
	}
	
	//getters
	string getNombre() {
		return this->nombre;
	}
	int getTelefono() {
		return this->telefono;
	}
	string getSexo() {
		return this->sexo;
	}
	string getFacultad() {
		return this->facultad;
	}
	CFecha* getNacimiento() {
		return this->fechaDeNacimiento;
	}
	string getEmail() {
		return this->email;
	}
	string getRedSocial() {
		return this->redSocial;
	}
	//setters
	void setNombre(string nombre) {
		this->nombre = nombre;
	}
	void setTelefono(int telefono) {
		this->telefono = telefono;
	}
	void setSexo(string sexo) {
		this->sexo = sexo;
	}
	void setFacultad(string facultad) {
		this->facultad = facultad;
	}
	void setNacimiento(CFecha* fechaDeNacimiento) {
		this->fechaDeNacimiento = fechaDeNacimiento;
	}
	void setEmail(string email) {
		this->email = email;
	}
	void setRedSocial(string redSocial) {
		this->redSocial = redSocial;
	}
};