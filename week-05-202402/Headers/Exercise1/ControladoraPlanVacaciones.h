#pragma once
#include "VectorPlanDeVacaciones.h"

class Controladora
{
private:
	VectorPlanDeVacaciones* vectorplanesdevacaciones;

public:
	Controladora();
	~Controladora();
	void RegistroPlanDeVacaciones();
	void MostrarPlanVacacionesEnIntervaloFecha();
	void MostrarPlanVacacionesMismoHotel();
	void MostrarBoletosCadaPlanVacaciones();
	void MostrarTodosPlanesVacaciones();
	bool existenPlanesDeVacaciones();
};

Controladora::Controladora()
{
	vectorplanesdevacaciones = new VectorPlanDeVacaciones();
}

Controladora::~Controladora()
{
	delete vectorplanesdevacaciones;
}

void Controladora::RegistroPlanDeVacaciones()
{
	string idBoleto, destino, nombre, ubicacion;
	int diaSalida, mesSalida, añoSalida, diaRegreso, mesRegreso, añoRegreso;
	int numHabitaciones, numHabitacionesDisponibles;
	double precio;
	bool idExiste = false;
	do
	{
		cout << "Ingrese ID del Boleto: "; cin >> idBoleto;
		idExiste = false;
		for (int i = 0; i < vectorplanesdevacaciones->getNumPlanesDeVacaciones(); i++)
		{
			if (vectorplanesdevacaciones->obtenerDatosPlanDeVacaciones(i)->getIDBoleto() == idBoleto)
			{
				idExiste = true;
				cout << "EL ID YA EXISTE. POR FAVOR, INGRESE OTRO ID." << endl;
				break;
			}
		}
	} while (idExiste);
	do
	{
		cout << "Ingrese el precio del Boleto: "; cin >> precio;
	} while (precio < 1 || precio > 1000);
	cout << "Ingrese destino: ";
	cin.ignore();
	getline(cin, destino);
	do
	{
		cout << "Ingrese dia de salida: "; cin >> diaSalida;
	} while (diaSalida < 1 || diaSalida > 31);
	do
	{
		cout << "Ingrese mes de salida: "; cin >> mesSalida;
	} while (mesSalida < 1 || mesSalida > 12);
	do
	{
		cout << "Ingrese anual de salida: "; cin >> añoSalida;
	} while (añoSalida < 1970 || añoSalida > 2050);
	Fecha* fechaSalida = new Fecha(diaSalida, mesSalida, añoSalida);
	Fecha* fechaRegreso = nullptr;
	do
	{
		do
		{
			cout << "Ingrese dia de regreso: "; cin >> diaRegreso;
		} while (diaRegreso < 1 || diaRegreso > 31);
		do
		{
			cout << "Ingrese mes de regreso: "; cin >> mesRegreso;
		} while (mesRegreso < 1 || mesRegreso > 12);
		do
		{
			cout << "Ingrese anual de regreso: "; cin >> añoRegreso;
		} while (añoRegreso < 1970 || añoRegreso > 2050);
		fechaRegreso = new Fecha(diaRegreso, mesRegreso, añoRegreso);
		// Verificar que la fecha de regreso no sea anterior a la de salida
		if (!PlanDeVacaciones::esMenorIgual(fechaSalida, fechaRegreso))
		{
			cout << "ERROR: LA FECHA DE REGRESO NO PUEDE SER ANTERIOR A LA FECHA DE SALIDA!!" << endl;
			delete fechaRegreso; // Borrar la fecha incorrecta
			fechaRegreso = nullptr; // Resetear puntero para repetir el ciclo
		}
	} while (fechaRegreso == nullptr);
	cout << "Ingrese nombre del hotel: ";
	cin.ignore();
	getline(cin, nombre);
	cout << "Ingrese ubicacion del hotel: ";
	getline(cin, ubicacion);
	do
	{
		cout << "Ingrese numero de habitaciones en el hotel: "; cin >> numHabitaciones;
	} while (numHabitaciones < 1);
	do
	{
		cout << "Ingrese numero de habitaciones disponibles en el hotel: "; cin >> numHabitacionesDisponibles;
	} while (numHabitacionesDisponibles < 1 || numHabitacionesDisponibles > numHabitaciones);
	PlanDeVacaciones* plandevacaciones = new PlanDeVacaciones(idBoleto, precio, destino, fechaSalida, fechaRegreso, nombre, ubicacion, numHabitaciones, numHabitacionesDisponibles);
	vectorplanesdevacaciones->agregarPlanDeVacaciones(plandevacaciones);
}

void Controladora::MostrarPlanVacacionesEnIntervaloFecha()
{
	int diaInicio, mesInicio, añoInicio, diaFin, mesFin, añoFin;
	do
	{
		cout << "Ingrese dia de inicio del intervalo: "; cin >> diaInicio;
	} while (diaInicio < 1 || diaInicio > 31);
	do
	{
		cout << "Ingrese mes de inicio del intervalo: "; cin >> mesInicio;
	} while (mesInicio < 1 || mesInicio > 12);
	do
	{
		cout << "Ingrese anual de inicio del intervalo: "; cin >> añoInicio;
	} while (añoInicio < 1970 || añoInicio > 2050);
	Fecha* inicio = new Fecha(diaInicio, mesInicio, añoInicio);
	Fecha* fin = nullptr;
	do
	{
		do
		{
			cout << "Ingrese dia de fin del intervalo: "; cin >> diaFin;
		} while (diaFin < 1 || diaFin > 31);
		do
		{
			cout << "Ingrese mes de fin del intervalo: "; cin >> mesFin;
		} while (mesFin < 1 || mesFin > 12);
		do
		{
			cout << "Ingrese anual de fin del intervalo: "; cin >> añoFin;
		} while (añoFin < 1970 || añoFin > 2050);
		fin = new Fecha(diaFin, mesFin, añoFin);
		// Verificar que la fecha de fin no sea anterior a la de inicio
		if (!PlanDeVacaciones::esMenorIgual(inicio, fin))
		{
			cout << "ERROR: LA FECHA DE FIN NO PUEDE SER ANTERIOR A LA FECHA DE INICIO!!" << endl;
			delete fin; // Borrar la fecha incorrecta
			fin = nullptr; // Resetear puntero para repetir el ciclo
		}
	} while (fin == nullptr);
	bool encontrado = false;
	for (int i = 0; i < vectorplanesdevacaciones->getNumPlanesDeVacaciones(); i++)
	{
		if (vectorplanesdevacaciones->obtenerDatosPlanDeVacaciones(i)->estaDentroDeRangoFechas(inicio, fin))
		{
			if (!encontrado)
			{
				system("cls");
				cout << "\t\t\tPLANES DE VACACIONES EN INTERVALO FECHA\n\n";
				encontrado = true;
			}
			vectorplanesdevacaciones->obtenerDatosPlanDeVacaciones(i)->mostrarPlan();
			cout << endl;
		}
	}
	if (!encontrado)
	{
		cout << endl << "NO SE ENCONTRARON PLANES DE VACACIONES EN EL RANGO DE FECHAS ESPECIFICADOS!!" << endl;
	}
	delete inicio;
	delete fin;
}

void Controladora::MostrarPlanVacacionesMismoHotel()
{
	string nombreHotel;
	int contador = 0;
	bool encontrado = false;
	cout << "Ingrese el nombre del hotel: ";
	cin.ignore();
	getline(cin, nombreHotel);
	for (int i = 0; i < vectorplanesdevacaciones->getNumPlanesDeVacaciones(); i++)
	{
		if (vectorplanesdevacaciones->obtenerDatosPlanDeVacaciones(i)->getNombreHotel() == nombreHotel)
		{
			contador++;
		}
	}
	if (contador < 2)
	{
		cout << endl << "NO HAY COMO MINIMO DOS HOTELES CON EL MISMO NOMBRE!!" << endl;
		return;
	}
	for (int i = 0; i < vectorplanesdevacaciones->getNumPlanesDeVacaciones(); i++)
	{
		if (vectorplanesdevacaciones->obtenerDatosPlanDeVacaciones(i)->getNombreHotel() == nombreHotel)
		{
			if (!encontrado)
			{
				system("cls");
				cout << "\t\t\tPLANES DE VACACIONES DEL MISMO HOTEL\n\n";
				encontrado = true;
			}
			vectorplanesdevacaciones->obtenerDatosPlanDeVacaciones(i)->mostrarPlan();
			cout << endl;
		}
	}
}

void Controladora::MostrarBoletosCadaPlanVacaciones()
{
	cout << "\t\t\tBOLETOS QUE TIENE CADA PLAN DE VACACIONES\n\n";
	for (int i = 0; i < vectorplanesdevacaciones->getNumPlanesDeVacaciones(); i++)
	{
		vectorplanesdevacaciones->obtenerDatosPlanDeVacaciones(i)->mostrarBoleto();
		cout << endl;
	}
}

void Controladora::MostrarTodosPlanesVacaciones()
{
	cout << "\t\t\tTODOS LOS PLANES DE VACACIONES\n\n";
	for (int i = 0; i < vectorplanesdevacaciones->getNumPlanesDeVacaciones(); i++)
	{
		vectorplanesdevacaciones->obtenerDatosPlanDeVacaciones(i)->mostrarPlan();
		cout << endl;
	}
}

bool Controladora::existenPlanesDeVacaciones()
{
	return vectorplanesdevacaciones->getNumPlanesDeVacaciones() > 0;
}