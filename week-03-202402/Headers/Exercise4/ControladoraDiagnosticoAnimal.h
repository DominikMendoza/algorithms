#pragma once
#include "VectorAnimales.h"
#include "VectorPersonal.h"
#include "VectorDiagnosticos.h"

class Controladora
{
private:
	VectorPersonal* vectorpersonal;
	VectorAnimales* vectoranimales;
	VectorDiagnosticos* vectordiagnosticos;

public:
	Controladora();
	~Controladora();
	void InsertarPersonal();
	void InsertarAnimal();
	void RealizarDiagnostico();
	bool existePersonal();
	bool existeAnimal();
	bool existeDiagnostico();
	bool existeNombreAnimal(string nombre);
	void ReporteDiagnosticos();
	void ReporteAnimales();
	void SeleccionAnimal();
	void SeleccionPersonal();
};

Controladora::Controladora()
{
	vectorpersonal = new VectorPersonal();
	vectoranimales = new VectorAnimales();
	vectordiagnosticos = new VectorDiagnosticos();
}

Controladora::~Controladora()
{
	delete vectoranimales;
	delete vectorpersonal;
	delete vectordiagnosticos;
}

void Controladora::InsertarPersonal()
{
	string nombres, apellidos, fechaContratacion;
	cin.ignore();
	cout << "Ingrese nombres: ";
	getline(cin, nombres);
	cout << "Ingrese apellidos: ";
	getline(cin, apellidos);
	cout << "Ingrese fecha de contratacion: ";
	getline(cin, fechaContratacion);
	Personal* persona = new Personal(nombres, apellidos, fechaContratacion);
	vectorpersonal->agregarPersonal(persona);
}

void Controladora::InsertarAnimal()
{
	string nombre, tipo;
	int edad;
	cin.ignore();
	cout << "Ingrese nombre del animal: ";
	getline(cin, nombre);
	cout << "Ingrese tipo de animal: ";
	getline(cin, tipo);
	do
	{
		cout << "Ingrese edad del animal: "; cin >> edad;
	} while (edad < 0 || edad > 70);
	Animal* animal = new Animal(tipo, nombre, edad);
	vectoranimales->agregarAnimales(animal);
}

void Controladora::RealizarDiagnostico()
{
	string fecha, descripcion;
	int indiceanimal, indicepersonal;
	do
	{
		SeleccionAnimal();
		cout << "Ingrese indice de animal a diagnosticar: "; cin >> indiceanimal;
	} while (indiceanimal < 0 || indiceanimal >= vectoranimales->getNumAnimales() || vectoranimales->getDatosAnimales(indiceanimal)->esDiagnosticado());
	do
	{
		SeleccionPersonal();
		cout << "Ingrese indice del personal que realizara el diagnostico: "; cin >> indicepersonal;
	} while (indicepersonal < 0 || indicepersonal >= vectorpersonal->getNumPersonal());
	cin.ignore();
	cout << "Ingrese fecha del diagnostico: ";
	getline(cin, fecha);
	cout << "Ingrese descripcion del diagnostico: ";
	getline(cin, descripcion);
	Animal* animal = vectoranimales->getDatosAnimales(indiceanimal);
	Personal* personal = vectorpersonal->getDatosPersonal(indicepersonal);
	Diagnostico* diagnostico = new Diagnostico(fecha, descripcion, animal, personal);
	vectordiagnosticos->agregarDiagnosticos(diagnostico);
	animal->setDiagnosticado(true);
	cout << endl << "DIAGNOSTICO REALIZADO CON EXITO!!" << endl;
}

bool Controladora::existePersonal()
{
	return vectorpersonal->getNumPersonal() > 0;
}

bool Controladora::existeAnimal()
{
	return vectoranimales->getNumAnimales() > 0;
}

bool Controladora::existeDiagnostico()
{
	return vectordiagnosticos->getNumDiagnosticos() > 0;
}

bool Controladora::existeNombreAnimal(string nombre)
{
	for (int i = 0; i < vectoranimales->getNumAnimales(); i++)
	{
		if (vectoranimales->getDatosAnimales(i)->getNombre() == nombre)
		{
			return true;
		}
	}
	return false;
}

void Controladora::ReporteDiagnosticos()
{
	cout << "\t\t\tREPORTE DE DIAGNOSTICOS\n\n";
	for (int i = 0; i < vectordiagnosticos->getNumDiagnosticos(); i++)
	{
		cout << "Diagnostico " << i + 1 << ": " << endl;
		vectordiagnosticos->getDatosDiagnosticos(i)->mostrarDiagnostico();
		cout << endl;
	}
}

void Controladora::ReporteAnimales()
{
	cout << "\t\t\tREPORTE DE ANIMALES\n\n";
	for (int i = 0; i < vectoranimales->getNumAnimales(); i++)
	{
		vectoranimales->getDatosAnimales(i)->mostrarAnimal();
		cout << (vectoranimales->getDatosAnimales(i)->esDiagnosticado() ? " [Diagnosticado]" : " [No Diagnosticado]") << endl;
		cout << endl;
	}
}

void Controladora::SeleccionAnimal()
{
	cout << "Seleccione el animal a diagnosticar: " << endl;
	for (int i = 0; i < vectoranimales->getNumAnimales(); i++)
	{
		cout << i << ". " << vectoranimales->getDatosAnimales(i)->getNombre() << endl;
	}
}

void Controladora::SeleccionPersonal()
{
	cout << "Seleccion el personal que realizara el diagnostico: " << endl;
	for (int i = 0; i < vectorpersonal->getNumPersonal(); i++)
	{
		cout << i << ". " << vectorpersonal->getDatosPersonal(i)->getNombres() << " " << vectorpersonal->getDatosPersonal(i)->getApellidos() << endl;
	}
}