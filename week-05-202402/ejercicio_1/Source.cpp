#include "CControladora.hpp"
int main()
{
	CControladora* c = new CControladora();
	c->agregarPlan();
	c->agregarPlan();
	c->agregarPlan();
	/*
	long long inicio, finall;
	cout << "Ingrese intervalo: (inicio): ";
	cin >> inicio;
	cout << "Ingrese intervalo: (finall): ";
	cin >> finall;
	c->mostrarPlanesEnIntervalo(inicio, finall);

	*/
	string nombre;
	cout << "Ingrese nombre de Hotel: ";
	cin.ignore();
	getline(cin, nombre);
	c->mostrarPlanesMismoHotel(nombre);
	cout << "\n-----";
	system("pause>0");
	return 0;
}