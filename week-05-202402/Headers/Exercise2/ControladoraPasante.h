#pragma once
#include "Pasante.h"

class Controladora
{
private:
	vector<Pasante*> pasantes;

public:
	Controladora();
	~Controladora();
	void AgregarPasante();
	void VerificarUniversidadMayoriaPasantesEmpresa();
	void VisualizarPromedioNotasEstudiantesSelecPasantes();
	void MostrarPasantes();
};

Controladora::Controladora() {}

Controladora::~Controladora()
{
	for (int i = 0; i < pasantes.size(); i++)
	{
		delete pasantes[i];
	}
	pasantes.clear();
}

void Controladora::AgregarPasante()
{
	string nombre, apellido, nivelEstudios, nombreU, carrera, posicion, nombreProyecto, materia;
	int edad, totalHoras, numeroHorasCompletas, numMaterias;  
	char sexo;
	double salario, nota; 
	do
	{
		cout << "Ingrese Nombre: "; cin >> nombre;
	} while (nombre.empty());
	do
	{
		cout << "Ingrese Apellido: "; cin >> apellido;
	} while (apellido.empty());
	do
	{
		cout << "Ingrese Edad: "; cin >> edad;
	} while (edad < 18);
	do
	{
		cout << "Ingrese Sexo: "; cin >> sexo;
		sexo = toupper(sexo);
	} while (sexo != 'H' && sexo != 'M');
	do
	{
		cout << "Ingrese Nivel de Estudios: ";
		cin.ignore();
		getline(cin, nivelEstudios);
	} while (nivelEstudios.empty());
	do
	{
		cout << "Ingrese Nombre Universidad: ";
		getline(cin, nombreU);
	} while (nombreU.empty());
	do
	{
		cout << "Ingrese Carrera: "; 
		getline(cin, carrera);
	} while (carrera.empty());
	do
	{
		cout << "Ingrese Posicion Empleo: "; 
		getline(cin, posicion);
	} while (posicion.empty());
	do
	{
		cout << "Ingrese Salario Mensual: "; cin >> salario;
	} while (salario < 1);
	do
	{
		cout << "Ingrese Nombre Proyecto: ";
		cin.ignore();
		getline(cin, nombreProyecto);
	} while (nombreProyecto.empty());
	do
	{
		cout << "Ingrese Duracion Pasantia (en horas): "; cin >> totalHoras;
	} while (totalHoras < 1);
	do
	{
		cout << "Ingrese Numero Horas Completadas: "; cin >> numeroHorasCompletas;
	} while (numeroHorasCompletas < 1 || numeroHorasCompletas > totalHoras);
	Pasante* pasante = new Pasante(nombre, apellido, edad, sexo, nivelEstudios, nombreU, carrera, posicion, salario, nombreProyecto, totalHoras, numeroHorasCompletas);
	do
	{
		cout << "Ingresar Cantidad de Materias: "; cin >> numMaterias;
	} while (numMaterias < 1);
	for (int i = 0; i < numMaterias; i++)
	{
		do
		{
			cout << "Ingresar Nombre Materia: "; 
			cin.ignore();
			getline(cin, materia);
		} while (materia.empty());
		do
		{
			cout << "Ingrese Nota: "; cin >> nota;
		} while (nota < 0 || nota > 20);
		pasante->agregarMateria(materia, nota);
	}
	pasantes.push_back(pasante);
}

void Controladora::VerificarUniversidadMayoriaPasantesEmpresa()
{
	if (pasantes.empty())
	{
		cout << "NO HAY PASANTES REGISTRADOS. POR FAVOR REGISTRE UN PASANTE" << endl;
		return;
	}
	vector<string> universidades;
	vector<int> conteos;
	for (int i = 0; i < pasantes.size(); i++)
	{
		string universidad = pasantes[i]->getUniversidad();
		int posUniversidad = -1;
		for (int i = 0; i < universidades.size(); i++)
		{
			if (universidad == universidades[i])
			{
				posUniversidad = i;
				break;
			}
		}
		if (posUniversidad == -1)
		{
			universidades.push_back(universidad);
			conteos.push_back(1);
		}
		else
		{
			conteos[posUniversidad]++;
		}
	}
	int maxIndex = 0;
	for (int i = 1; i < conteos.size(); i++)
	{
		if (conteos[i] > conteos[maxIndex])
		{
			maxIndex = i;
		}
	}
	cout << "Universidad con mayor cantidad de pasantes: " << universidades[maxIndex] << " con " << conteos[maxIndex] << "\n";
}

void Controladora::VisualizarPromedioNotasEstudiantesSelecPasantes()
{
	if (pasantes.empty())
	{
		cout << "NO HAY PASANTES REGISTRADOS. POR FAVOR REGISTRE UN PASANTE" << endl;
		return;
	}
	cout << "\t\tPROMEDIO NOTAS ESTUDIANTES PARA SER SELECCIONADOS\n\n";
	for (int i = 0; i < pasantes.size(); i++)
	{
		cout << "Estudiante " << i + 1 << ": " << endl;
		cout << "Nombre: " << pasantes[i]->Persona::getNombre() << endl;
		cout << "Apellido: " << pasantes[i]->Persona::getApellido() << endl;
		cout << "Promedio de Notas: " << pasantes[i]->getPromedioNotas() << endl;
		cout << endl;
	}
}

//void Controladora::VisualizarPromedioNotasEstudiantesSelecPasantes() //Para ingresar el promedio minimo y mostrar solo esos estudiantes que se convierten en pasantes
//{
//	if (pasantes.empty())
//	{
//		cout << "NO HAY PASANTES REGISTRADOS. POR FAVOR REGISTRE UN PASANTE" << endl;
//		return;
//	}
//	bool pasantesSeleccionados = false;
//	double promedioMinimo;
//	do
//	{
//		cout << "Ingrese el promedio minimo para seleccionar los pasantes: "; cin >> promedioMinimo;
//	} while (promedioMinimo < 0);
//	for (int i = 0; i < pasantes.size(); i++)
//	{
//		double promedio = pasantes[i]->getPromedioNotas();
//		if (promedio >= promedioMinimo)
//		{
//			if (!pasantesSeleccionados)
//			{
//				system("cls");
//				cout << "\t\tPROMEDIO NOTAS ESTUDIANTES SELECCIONADOS\n\n";
//				pasantesSeleccionados = true;
//			}
//			cout << "Pasante " << i + 1 << ": " << endl;
//			cout << "Nombre: " << pasantes[i]->Persona::getNombre() << endl;
//			cout << "Apellido: " << pasantes[i]->Persona::getApellido() << endl;
//			cout << "Promedio de Notas: " << promedio << endl;
//			cout << endl;
//		}
//	}
//	if (!pasantesSeleccionados)
//	{
//		cout << endl << "NO HAY PASANTES QUE CUMPLAN CON EL PROMEDIO MINIMO!!" << endl;
//	}
//}

void Controladora::MostrarPasantes()
{
	if (pasantes.empty())
	{
		cout << "NO HAY PASANTES REGISTRADOS. POR FAVOR REGISTRE UN PASANTE" << endl;
		return;
	}
	cout << "\t\t\t\tTODOS LOS PASANTES\n\n";
	for (int i = 0; i < pasantes.size(); i++)
	{
		pasantes[i]->mostrarPasante();
		cout << endl;
	}
}