#pragma once

#include <iostream>
#include <string>
#include "Fecha.h"
using namespace std;

class Contacto
{
private:
	string Nombre, Facultad,  Mail, RedSocial;
	char Sexo;
	Fecha* FecNac;
	long long Celar;

public:
	Contacto();
	Contacto(string,long long, char , string, Fecha*, string, string);
	
	void MostrarDatos();

	// Declaraciones de los setters
	void setNombre(string& nombre);
	void setCelar(long long& celar);
	void setSexo(char& sexo);
	void setFacultad(string& facultad);
	void setFecNac(Fecha* fecNac);
	void setMail(string& mail);
	void setRedSocial(string& redSocial);

	// Declaraciones de los getters
	string getNombre() ;
	long long getCelar() ;
	char getSexo() ;
	string getFacultad() ;
	Fecha* getFecNac() ;
	string getMail() ;
	string getRedSocial() ;

};

Contacto::Contacto()
{
	this->Nombre = "///";
	this->Celar = rand() % (999999999 - 900000000 + 1) + 900000000;;
	this->Sexo = '/';
	this->Facultad = "///";
	this->FecNac = new Fecha();
	this->Mail = "///";
	this->RedSocial = "///";
}

Contacto::Contacto(string N, long long C, char S , string FAC, Fecha* FNAC, string M, string RSS)
{
	this->Nombre = N;
	this->Celar = C;
	this->Sexo = S;
	this->Facultad = FAC;
	this->FecNac = FNAC;
	this->Mail = M;
	this->RedSocial = RSS;
}

//MOSTRAR DATOS

void Contacto::MostrarDatos() {

	cout << "Nombre: " << this->Nombre<< endl;
	cout << "redSocial: " << this->RedSocial<< endl;
	cout << "Telefono: " << this->Celar<< endl;
	cout << "Genero: " << this->Sexo << endl;
	cout << "Fecha de nacimiento: ";
	FecNac->MOSTRAR();
}

// Implementación de los setters fuera de la clase
void Contacto::setNombre(string& nombre) { Nombre = nombre; }
void Contacto::setCelar(long long& celar) { Celar = celar; }
void Contacto::setSexo(char& sexo) { Sexo = sexo; }
void Contacto::setFacultad(string& facultad) { Facultad = facultad; }
void Contacto::setFecNac(Fecha* fecNac) { FecNac = fecNac; }
void Contacto::setMail(string& mail) { Mail = mail; }
void Contacto::setRedSocial(string& redSocial) { RedSocial = redSocial; }

// Implementación de los getters fuera de la clase
string Contacto::getNombre() { return Nombre; }
long long Contacto::getCelar()  { return Celar; }
char Contacto::getSexo() { return Sexo; }
string Contacto::getFacultad() { return Facultad; }
Fecha* Contacto::getFecNac() { return FecNac; }
string Contacto::getMail() { return Mail; }
string Contacto::getRedSocial() { return RedSocial; }
