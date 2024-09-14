#pragma once
#include <vector>
#include "CPlanVacacion.hpp"
class CControladora
{
private:
	vector<CPlanVacacion*> planes;
public:
	CControladora();
	~CControladora();
	void agregarPlan();
	void mostrarPlanesEnIntervalo(long long inicio, long long final);
	void mostrarPlanesMismoHotel(string nombre);
};

CControladora::CControladora()
{
}

CControladora::~CControladora()
{
}

void CControladora::agregarPlan()
{
	string nombre;
	long long fecha;
	cout << "Ingrese nombre: ";
	cin >> nombre;
	cout << "Ingrese fecha: ";
	cin >> fecha;
	planes.push_back(new CPlanVacacion(nombre, fecha));
}

void CControladora::mostrarPlanesEnIntervalo(long long inicio, long long final)
{
	for (int i = 0; i < planes.size(); i++)
	{
		if (planes[i]->estaEnFecha(inicio, final)) {
			planes[i]->mostrar();
		}
	}
}

void CControladora::mostrarPlanesMismoHotel(string nombre)
{
	for (int i = 0; i < planes.size(); i++)
	{
		if (planes[i]->getName() == nombre) {
			planes[i]->mostrar();
		}
	}
}
