#pragma once
#include "CContacto.hpp"
//«mayor que» > , «menor que» < y la barra(\ y / )
class CListaContacto {
private:
	CContacto** contactos;
	int cantidad;

public:
	CListaContacto() {
		contactos = nullptr;
		cantidad = 0;
	}
	~CListaContacto() {		}

	//metodos
	void addContacto(CContacto* pntrContacto) {
		CContacto** tempo = new CContacto * [cantidad + 1];
		for (int i = 0; i < cantidad; i++) {
			tempo[i] = contactos[i];
		}
		tempo[cantidad] = pntrContacto;

		delete[] contactos;
		contactos = tempo;
		cantidad++;
	}
	void deleteContactoInPos(short pos) {
		if (pos < 0 || pos > cantidad) {
			cout << "Out Of Range\n";
		}
		CContacto** tempo = new CContacto * [cantidad - 1];
		for (int i = 0, j = 0; i < cantidad; i++) {
			if (i == pos) continue;
			tempo[j] = contactos[i];
			j++;
		}

		delete[] contactos;
		contactos = tempo;
		cantidad--;
	}
	CContacto* getContacto(int pos) {
		if (pos < 0 || pos > cantidad) {
			cout << "Out Of Range\n";
			return new CContacto();
		}
		return contactos[pos];
	}
	void mostrarListaContactos() {
		cout << "\t\tTodos los contactos\n";
		for (int i = 0; i < cantidad; i++) {
			cout << "Contacto" << i + 1 << "\n";
			contactos[i]->mostrarDatos();
			cout << "\n";
		}
	}
	void mostrarListaContactosMayo() {
		cout << "\t\tTodos los contactos\n";
		for (int i = 0; i < cantidad; i++) {
			if (contactos[i]->getNacimiento()->getMes() == 5) {
				cout << "Contacto " << i + 1 << "\n";
				contactos[i]->mostrarDatos();
				cout << "\n";
			}
		}
	}
	void mostrarListaContactosVarones() {
		cout << "\t\tTodos los contactos\n";
		for (int i = 0; i < cantidad; i++) {
			string isMale = contactos[i]->getSexo();
			if (isMale == "Hombre" || isMale == "Masculino" || isMale == "Varon" || isMale == "M") {
				cout << "Contacto " << i + 1 << "\n";
				contactos[i]->mostrarDatos();
				cout << "\n";
			}
		}
	}
	void mostrarListaContactosFacebookOWhatsapp() {
		cout << "\t\tTodos los contactos\n";
		for (int i = 0; i < cantidad; i++) {
			if (contactos[i]->getRedSocial() == "Facebook" || contactos[i]->getRedSocial() == "Whatsapp") {
				cout << "Contacto " << i + 1 << "\n";
				contactos[i]->mostrarDatos();
				cout << "\n";
			}
		}
	}
	CContacto* crearContacto() {
		string nombre;
		int telefono;
		string sexo;
		string facultad;
		CFecha* fechaDeNacimiento = new CFecha();
		string email;
		string redSocial;
		short f_aux;

		cout << "Nombre: "; cin >> nombre;
		cout << "Telefono: "; cin >> telefono;
		cout << "Sexo: "; cin >> sexo;
		cout << "Facultad: "; cin >> facultad;
		cout << "Red Social: "; cin >> redSocial;
		cout << "Email: "; cin >> email;
		cout << "Fecha de nacimiento:\n";
		cout << "-Dia: "; cin >> f_aux;
		fechaDeNacimiento->setDia(f_aux);
		cout << "-Mes: "; cin >> f_aux;
		fechaDeNacimiento->setMes(f_aux);
		cout << "-Anio: "; cin >> f_aux;
		fechaDeNacimiento->setAnio(f_aux);
		return new CContacto(nombre, telefono, sexo, facultad, fechaDeNacimiento, email, redSocial);
	}
	void opAgregarContacto() {
		short opc;
		do {
			cout << "1. Agregar contacto default\n";
			cout << "2. Ingresar datos manualmente\n";
			cin >> opc;
		} while (opc < 1 || opc > 2);

		switch (opc) {
		case 1: addContacto(new CContacto()); break;
		case 2: addContacto(crearContacto()); break;
		default: break;
		}
	}
	void opModificarContacto() {
		int pos;
		cout << "Ingrese el numero de contacto a modificar";
		cin >> pos;
		contactos[pos]->mostrarDatos();
		cout << "\nIngrese los nuevos valores\n";
		contactos[pos] = crearContacto();
	}
	void opEliminarContacto() {
		int pos;
		cout << "Ingrese el numero de contacto a eliminar";
		cin >> pos;
		deleteContactoInPos(pos);
	}
};