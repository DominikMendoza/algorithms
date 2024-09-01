#pragma once
#include "VectorEclipses.h"

class Controladora
{
private:
	VectorEclipses* vectoreclipses;

public:
	Controladora();
	~Controladora();
	void RegistroDatos();
	void ModificarDatos();
	void EliminarDatos();
	void ReporteTodosEclipses();
	void ReporteEclipsesEuropa();
	void ReporteEclipsesSismos();
	void ReporteEclipsesNoche();
	bool existenEclipses();
};

Controladora::Controladora()
{
	vectoreclipses = new VectorEclipses();
}

Controladora::~Controladora()
{
	delete vectoreclipses;
}

void Controladora::RegistroDatos()
{
	string tipo, fecha, visibilidad;
	int hora;
	char sismos, lluvias;
	cout << "Ingrese Tipo Eclipse: ";
	cin.ignore();
	getline(cin, tipo);
	cout << "Ingrese Fecha: ";
	getline(cin, fecha);
	do
	{
		cout << "Ingrese Hora: "; cin >> hora;
	} while (hora < 100 || hora > 2400);
	do
	{
		cout << "Hubo Sismos?: "; cin >> sismos;
		sismos = toupper(sismos);
	} while (sismos != 'S' && sismos != 'N');
	do
	{
		cout << "Hubo Lluvias?: "; cin >> lluvias;
		lluvias = toupper(lluvias);
	} while (lluvias != 'S' && lluvias != 'N');
	cout << "Continente Mayor Visibilidad: ";
	cin.ignore();
	getline(cin, visibilidad);
	Eclipse* eclipse = new Eclipse(tipo, fecha, hora, sismos, lluvias, visibilidad);
	vectoreclipses->RegistrarEclipse(eclipse);
}

void Controladora::ModificarDatos()
{
	string tipo, fecha, visibilidad;
	int indice, hora, opcion;
	char sismos, lluvias;
	cout << "Ingrese el indice del eclipse a modificar: "; cin >> indice;
	if (indice < 0 || indice >= vectoreclipses->getNumEclipses())
	{
		cout << endl << "Indice fuera de rango!" << endl;
		return;
	}
	Eclipse* eclipse = vectoreclipses->obtenerDatosEclipse(indice);

	do
	{
		cout << "Seleccione el atributo a modificar:" << endl;
		cout << "1. Tipo de Eclipse" << endl;
		cout << "2. Fecha" << endl;
		cout << "3. Hora" << endl;
		cout << "4. Sismos" << endl;
		cout << "5. Lluvias" << endl;
		cout << "6. Visibilidad" << endl;
		cout << "0. Terminar modificaciones" << endl;
		cout << "Ingresar Opcion: "; cin >> opcion;
		system("cls");

		switch (opcion)
		{
		case 1:
			system("cls");
			cout << "Ingrese el nuevo tipo de eclipse: ";
			cin.ignore();
			getline(cin, tipo);
			eclipse->setTipo(tipo);
			system("pause>0");
			break;
		case 2:
			system("cls");
			cout << "Ingrese la nueva fecha: ";
			cin.ignore();
			getline(cin, fecha);
			eclipse->setFecha(fecha);
			system("pause>0");
			break;
		case 3:
			system("cls");
			do
			{
				cout << "Ingrese la nueva hora: "; cin >> hora;
			} while (hora < 100 || hora > 2400);
			eclipse->setHora(hora);
			system("pause>0");
			break;
		case 4:
			system("cls");
			do
			{
				cout << "Hubo Sismos?: "; cin >> sismos;
				sismos = toupper(sismos);
			} while (sismos != 'S' && sismos != 'N');
			eclipse->setSismos(sismos);
			system("pause>0");
			break;
		case 5:
			system("cls");
			do
			{
				cout << "Hubo Lluvias?: "; cin >> lluvias;
				lluvias = toupper(lluvias);
			} while (lluvias != 'S' && lluvias != 'N');
			eclipse->setLluvias(lluvias);
			system("pause>0");
			break;
		case 6:
			system("cls");
			cout << "Ingrese el nuevo continente de mayor visibilidad: ";
			cin.ignore();
			getline(cin, visibilidad);
			eclipse->setVisibilidad(visibilidad);
			system("pause>0");
			break;
		case 0:
			break;
		}
		system("cls");
	} while (opcion != 0);
	cout << "SE MODIFICO CON EXITO LOS DATOS DEL ECLIPSE!!" << endl;
}

void Controladora::EliminarDatos()
{
	int indice;
	cout << "Ingrese el indice del eclipse a eliminar: "; cin >> indice;
	if (indice < 0 || indice >= vectoreclipses->getNumEclipses())
	{
		cout << endl << "Indice fuera de rango!" << endl;
		return;
	}
	vectoreclipses->EliminarEclipse(indice);
	cout << "\nSE ELIMINO CON EXITO LOS DATOS DEL ECLIPSE!!" << endl;
}

void Controladora::ReporteTodosEclipses()
{
	cout << "\t\tREPORTE DE TODOS LOS ECLIPSES\n\n";
	for (int i = 0; i < vectoreclipses->getNumEclipses(); i++)
	{
		vectoreclipses->obtenerDatosEclipse(i)->MostrarEclipse();
		cout << endl;
	}
}

void Controladora::ReporteEclipsesEuropa()
{
	bool found = false;
	for (int i = 0; i < vectoreclipses->getNumEclipses(); i++)
	{
		if (vectoreclipses->obtenerDatosEclipse(i)->getVisibilidad() == "Europa")
		{
			if (!found)
			{
				cout << "\t\tECLIPSES VISIBLES EN EUROPA\n\n";
				found = true;
			}
			vectoreclipses->obtenerDatosEclipse(i)->MostrarEclipse();
			cout << endl;
		}
	}
	if (!found)
	{
		cout << "NO HAY ECLIPSES QUE SON VISIBLES EN EUROPA" << endl;
	}
}

void Controladora::ReporteEclipsesSismos()
{
	bool found = false;
	for (int i = 0; i < vectoreclipses->getNumEclipses(); i++)
	{
		if (vectoreclipses->obtenerDatosEclipse(i)->getSismos() == 'S')
		{
			if (!found)
			{
				cout << "\t\tECLIPSES QUE OCASIONARON SISMOS\n\n";
				found = true;
			}
			vectoreclipses->obtenerDatosEclipse(i)->MostrarEclipse();
			cout << endl;
		}
	}
	if (!found)
	{
		cout << "NO HAY ECLIPSES QUE OCASIONARON SISMOS" << endl;
	}
}

void Controladora::ReporteEclipsesNoche()
{
	bool found = false;
	for (int i = 0; i < vectoreclipses->getNumEclipses(); i++)
	{
		int hora = vectoreclipses->obtenerDatosEclipse(i)->getHora();
		if ((hora >= 1800 || hora < 600) && vectoreclipses->obtenerDatosEclipse(i)->getTipo() == "Lunar")
		{
			if (!found)
			{
				cout << "\t\tECLIPSES QUE SE PRODUJERON EN LA NOCHE\n\n";
				found = true;
			}
			vectoreclipses->obtenerDatosEclipse(i)->MostrarEclipse();
			cout << endl;
		}
	}
	if (!found)
	{
		cout << "NO HAY ECLIPSES QUE SE PRODUJERON EN LA NOCHE" << endl;
	}
}

bool Controladora::existenEclipses()
{
	return vectoreclipses->getNumEclipses() > 0;
}