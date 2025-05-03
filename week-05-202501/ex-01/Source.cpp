#include "ArrPlanVacacion.hpp"

void filtrarSegunFechas(ArrPlanVacacion* planes) {
	int limInf, limSup;
	cout << "Ingrese limite inferior: ";
	cin >> limInf;
	cout << "Ingrese limite superior: ";
	cin >> limSup;
	planes->listarSegunFechaDeBoleto(limInf, limSup);
}

void filtrarSegunNombreHotel(ArrPlanVacacion* planes) {
	string nombreHotel;
	cout << "Ingrese nombre de hotel: ";
	cin >> nombreHotel;
	planes->listarSegunNombreDeHotel(nombreHotel);
}
int main()
{
	srand(time(nullptr));
	ArrPlanVacacion* planes = new ArrPlanVacacion();
	string nombre;
	for (int i = 0; i < 4; i++)
	{
		cout << "Ingrese nombre: ";
		cin >> nombre;
		planes->agregarElemento(new PlanVacacion(rand() % 150, nombre));
	}
	cout << "----\n";
	planes->listarUnicamenteBoletos();
	cout << "----\n";
	planes->mostrarElementos();
	cout << "----\n";
	filtrarSegunFechas(planes);
	cout << "----\n";
	filtrarSegunNombreHotel(planes);
	system("pause>0");
	return 0;
}