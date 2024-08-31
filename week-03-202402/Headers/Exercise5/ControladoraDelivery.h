#pragma once
#include "ListaMotorizados.h"

class Controladora
{
private:
	ListaMotorizados* listamotorizados;

public:
	Controladora();
	~Controladora();
	void AgregarMotorizado();
	void EliminarMotorizado();
	void MostrarTodosMotorizados();
	void MotorizadosMapi();
	void MotorizadosGlopo();
	bool existenMotorizados();
};

Controladora::Controladora()
{
	listamotorizados = new ListaMotorizados();
}

Controladora::~Controladora()
{
	delete listamotorizados;
}

void Controladora::AgregarMotorizado()
{
	string nombre, apellido, placa, empresa;
	int kilometraje;
	cout << "Ingrese nombre: "; cin >> nombre;
	cout << "Ingrese apellido: "; cin >> apellido;
	cout << "Ingrese placa: ";
	cin.ignore();
	getline(cin, placa);
	do
	{
		cout << "Ingrese kilometraje: "; cin >> kilometraje;
	} while (kilometraje < 1);
	cout << "Ingrese empresa: "; cin >> empresa;
	Motorizado* motorizado = new Motorizado(nombre, apellido, placa, kilometraje, empresa);
	listamotorizados->agregarMotorizado(motorizado);
}

void Controladora::EliminarMotorizado()
{
	string placa;
	cout << "Ingrese la placa del motorizado a eliminar: "; 
	cin.ignore();
	getline(cin, placa);
	listamotorizados->eliminarMotorizado(placa);
}

void Controladora::MostrarTodosMotorizados()
{
	listamotorizados->mostrarMotorizados();
}

void Controladora::MotorizadosMapi()
{
	listamotorizados->motorizadosMapi();
}

void Controladora::MotorizadosGlopo()
{
	listamotorizados->motorizadosGlopo();
}

bool Controladora::existenMotorizados()
{
	return listamotorizados->getNumMotorizados() > 0;
}