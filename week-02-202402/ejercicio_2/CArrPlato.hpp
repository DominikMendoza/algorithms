#pragma once
#include "CPlato.hpp"

class CArrPlato
{
private:
	CPlato** platos;
	int cantidad;
public:
	CArrPlato() {
		platos = nullptr;
		cantidad = 0;
	}
	~CArrPlato() {}

	void agregarPlato(CPlato* pntrPlato) {
		CPlato** tpm = new CPlato * [cantidad + 1];
		for (int i = 0; i < cantidad; i++)
		{
			tpm[i] = platos[i];
		}
		tpm[cantidad] = pntrPlato;

		delete[] platos;
		platos = tpm;
		cantidad++;
	}

	void eliminarPlatoEnPosicion(int pos) {
		if (pos < 0 || pos >= cantidad) {
			cout << "Out of range\n";
			return;
		}
		CPlato** tmp = new CPlato * [cantidad - 1];

		int j = 0;
		for (int i = 0; i < cantidad; i++)
		{
			if (i == pos) continue;
			tmp[j] = platos[i];
			j++;
		}

		delete[] platos;
		platos = tmp;
		cantidad--;
	}

	CPlato* getPlato(int pos) {
		if (pos < 0 || pos >= cantidad) {
			cout << "Out of range\n";
			return new CPlato();
		}
		return platos[pos];
	}

	void mostrarPlatos() {
		cout << "-->Todos los platos son los siguientes:\n";
		for (int i = 0; i < cantidad; i++)
		{
			cout << "Plato n" << i + 1 << endl;
			platos[i]->mostrarDatos();
			cout << endl;
		}
	}

	void mostrarPlatosPicantes() {
		cout << "-->Los platos picantes son los siguientes:\n";
		for (int i = 0; i < cantidad; i++)
		{
			if (platos[i]->getEsPicante()) {
				cout << "Plato n" << i + 1 << endl;
				platos[i]->mostrarDatos();
				cout << endl;
			}
		}
	}

	void mostrarPlatosCaros() {
		cout << "-->Los platos caros son los siguientes:\n";
		for (int i = 0; i < cantidad; i++)
		{
			if (platos[i]->getPrecioPromedio() > 100) {
				cout << "Plato n" << i + 1 << endl;
				platos[i]->mostrarDatos();
				cout << endl;
			}
		}
	}

	CPlato* crearPlato() {
		string nombrePlato;
		bool esFrio, esPicante;
		float cantidadCalorias, precioPromedio;
		cout << "Nombre del Plato: "; cin >> nombrePlato;
		cout << "Es Frio (1: V, 0: F): "; cin >> esFrio;
		cout << "Es Picante (1: V, 0: F): "; cin >> esPicante;
		cout << "Cantidad de Calorias: "; cin >> cantidadCalorias;
		cout << "Precio Promedio: "; cin >> precioPromedio;
		return new CPlato(nombrePlato, esFrio, esPicante, cantidadCalorias, precioPromedio);
	}

	void opAgregarPlato() {
		short opc;
		string nombrePlato;
		bool esFrio, esPicante;
		float cantidadCalorias, precioPromedio;
		CPlato* platoTmp;
		do
		{
			cout << "1. Agregar plato default\n";
			cout << "2. Ingresar datos manualmente\n";
			cin >> opc;
		} while (opc < 1 || opc > 2);
		switch (opc)
		{
		case 1: agregarPlato(new CPlato()); break;
		case 2: agregarPlato(crearPlato()); break;
		default: break;
		}
	}

	void opModificarPlato() {
		int pos;
		cout << "Ingrese numero de plato a modificar: ";
		cin >> pos;
		platos[pos]->mostrarDatos();
		cout << "\nIngrese nuevos valores: ";
		platos[pos] = crearPlato();
	}

	void opEliminarPlato() {
		int pos;
		cout << "Ingrese posicion del plato a eliminar: ";
		cin >> pos;
		eliminarPlatoEnPosicion(pos);
	}
};