#pragma once
#include "iostream"
#include "string"
#include "sstream"

using namespace std;

class DNI
{
private:
	string dni;
	string generaDNI();

public:
	DNI();
	string getNumero();
	void mostrarDNI();
};

DNI::DNI()
{
	dni = generaDNI();
}

string DNI::generaDNI()
{
	stringstream ss;
	for (int i = 0; i < 4; i++)
	{
		ss << rand() % 10;
	}
	return ss.str();
}

string DNI::getNumero()
{
	return dni;
}

void DNI::mostrarDNI()
{
	cout << "DNI: " << dni << endl;
}