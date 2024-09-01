#pragma once
#include "Cliente.h"

class VectorClientes
{
private:
	int numClientes;
	Cliente** clientes;

public:
	VectorClientes();
	~VectorClientes();
	void agregarCliente(Cliente* cliente);
	int getNumClientes();
	bool existeDNICliente(string DNI);
	Cliente* getDatosCliente(int indice);
};

VectorClientes::VectorClientes()
{
	numClientes = 0;
	clientes = nullptr;
}

VectorClientes::~VectorClientes()
{
	if (clientes != nullptr)
	{
		for (int i = 0; i < numClientes; i++)
		{
			delete clientes[i];
		}
		delete[] clientes;
	}
}

void VectorClientes::agregarCliente(Cliente* cliente)
{
	Cliente** temp = new Cliente * [numClientes + 1];
	for (int i = 0; i < numClientes; i++)
	{
		temp[i] = clientes[i];
	}
	temp[numClientes] = cliente;
	numClientes++;
	delete[] clientes;
	clientes = temp;
}

int VectorClientes::getNumClientes()
{
	return numClientes;
}

Cliente* VectorClientes::getDatosCliente(int indice)
{
	if (indice < 0 || indice >= numClientes)
	{
		cout << "Indice fuera de rango!!" << endl;
		return nullptr;
	}
	return clientes[indice];
}

bool VectorClientes::existeDNICliente(string DNI)
{
	for (int i = 0; i < numClientes; i++)
	{
		if (clientes[i]->getDNI() == DNI)
		{
			return true;
		}
	}
	return false;
}