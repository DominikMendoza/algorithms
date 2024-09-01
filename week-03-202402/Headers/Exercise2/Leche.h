#pragma once
#include "iostream"

using namespace std;

class Leche
{
private:
	int tipo;

public:
	Leche();
	int getTipo();
	void mostrarTipo();
};

Leche::Leche()
{
	tipo = rand() % 4 + 1;
}

int Leche::getTipo()
{
	return tipo;
}

void Leche::mostrarTipo()
{
	cout << "Tipo: " << tipo << endl;
}