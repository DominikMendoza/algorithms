#include "CArrPlato.hpp"

short showMenu() {
	short opc;
	do
	{
		cout << "\tMENU\n";
		cout << "1. Agregar plato\n";
		cout << "2. Modificar datos de un plato\n";
		cout << "3. Eliminar un plato\n";
		cout << "4. Reporte de platos picantes\n";
		cout << "5. Reporte de platos caros\n";
		cout << "6. Mostrar todos los platos\n";
		cout << "7. Salir\n";
		cout << "Ingrese la opcion...";
		cin >> opc;
	} while (opc < 1 || opc > 6);
	return opc;
}

int main() {
	srand(time(nullptr));
	CArrPlato* arr = new CArrPlato();
	while (true) {
		switch (showMenu()) {
		case 1: arr->opAgregarPlato(); break;
		case 2: arr->opModificarPlato(); break;
		case 3: arr->opEliminarPlato(); break;
		case 4: arr->mostrarPlatosPicantes(); break;
		case 5: arr->mostrarPlatosCaros(); break;
		case 6: arr->mostrarPlatos(); break;
		}
		system("pause>0");
		system("cls");
	}
	system("pause>0");
	return 0;
}