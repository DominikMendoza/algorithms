#pragma once
#include "CContacto.hpp"

class CArrContacto
{
private:
	CContacto** contactos;
	int cantidad;
public:
	CArrContacto() {
		contactos = nullptr;
		cantidad = 0;
	}
	~CArrContacto() {}

	void agregarContacto(CContacto* pntrPlato) {
		CContacto** tpm = new CContacto * [cantidad + 1];
		for (int i = 0; i < cantidad; i++)
		{
			tpm[i] = contactos[i];
		}
		tpm[cantidad] = pntrPlato;

		delete[] contactos;
		contactos = tpm;
		cantidad++;
	}

	void eliminarContactoEnPosicio(int pos) {
		if (pos < 0 || pos >= cantidad) {
			cout << "Out of range\n";
			return;
		}
		CContacto** tmp = new CContacto * [cantidad - 1];

		int j = 0;
		for (int i = 0; i < cantidad; i++)
		{
			if (i == pos) continue;
			tmp[j] = contactos[i];
			j++;
		}

		delete[] contactos;
		contactos = tmp;
		cantidad--;
	}

	CContacto* getContacto(int pos) {
		if (pos < 0 || pos >= cantidad) {
			cout << "Out of range\n";
			return new CContacto();
		}
		return contactos[pos];
	}

	void mostrarTodosLosContactos() {
		cout << "-->Todos los contactos son los siguientes:\n";
		for (int i = 0; i < cantidad; i++)
		{
			cout << "Contacto n" << i + 1 << endl;
			contactos[i]->mostrarDatos();
			cout << endl;
		}
	}

	void mostrarContactosCumpleanosMayo() {
		cout << "-->Los contactos que cumplen anios en mayo son:\n";
		for (int i = 0; i < cantidad; i++)
		{
			// Mayo es el mes 5
			if (contactos[i]->getNacimiento()->getMes() == 5) {
				cout << "Contacto n" << i + 1 << endl;
				contactos[i]->mostrarDatos();
				cout << endl;
			}
		}
	}

	CContacto* crearContacto() {
		string nombrePlato;
		bool esFrio, esPicante;
		float cantidadCalorias, precioPromedio;
		cout << "Nombre del Plato: "; cin >> nombrePlato;
		cout << "Es Frio (1: V, 0: F): "; cin >> esFrio;
		cout << "Es Picante (1: V, 0: F): "; cin >> esPicante;
		cout << "Cantidad de Calorias: "; cin >> cantidadCalorias;
		cout << "Precio Promedio: "; cin >> precioPromedio;
		return new CContacto();
	}

	void opAgregarContacto() {
		short opc;
		do
		{
			cout << "1. Agregar plato default\n";
			cout << "2. Ingresar datos manualmente\n";
			cin >> opc;
		} while (opc < 1 || opc > 2);
		switch (opc)
		{
		case 1: agregarContacto(new CContacto()); break;
		case 2: agregarContacto(crearContacto()); break;
		default: break;
		}
	}

	void opModificarContacto() {
		int pos;
		cout << "Ingrese numero de plato a modificar: ";
		cin >> pos;
		contactos[pos]->mostrarDatos();
		cout << "\nIngrese nuevos valores: ";
		contactos[pos] = crearContacto();
	}

	void opEliminarContacto() {
		int pos;
		cout << "Ingrese posicion del plato a eliminar: ";
		cin >> pos;
		eliminarContactoEnPosicio(pos);
	}

	 //Reporte WhatsApp y Facebook
  void ArrContactos::ReporteContc_W_F() {
	 cout << "Contactos que usan Facebook y WhatsApp: ";
	 for (int i = 0; i < this->cant; i++) {
		 string RedS = Arr[i]->getRedSocial();

		 bool usaFacebook = RedS.find("Facebook") != string::npos;
		 bool usaWhatsApp = RedS.find("WhatsApp") != string::npos;

		 if (usaFacebook && usaWhatsApp) {
			 cout << "Contacto N#" << i + 1 << '\n';
			 Arr[i]->MostrarDatos();
			 cout << "\n\n";
		 }
	 }
  }
};