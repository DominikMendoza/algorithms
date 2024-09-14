#include "CArrContacto.hpp"

short showMenu() {
	short opc;
	do
	{
		cout << "\tMENU\n";
		cout << "1. Agregar contacto\n";
		cout << "2. Modificar datos de un contacto\n";
		cout << "3. Eliminar un contacto\n";
		cout << "4. Reporte de contactos que cumplen anios en mayo\n";
		cout << "5. Reporte de contactos caros\n";
		cout << "6. Mostrar todos los contactos\n";
		cout << "7. Salir\n";
		cout << "Ingrese la opcion...";
		cin >> opc;
	} while (opc < 1 || opc > 6);
	return opc;
}

int main() {
	srand(time(nullptr));
	CArrContacto* arr = new CArrContacto();
	for (int i = 0; i < 10; i++)
	{
		arr->agregarContacto(new CContacto());
	}
	while (true) {
		switch (showMenu()) {
		case 1: arr->opAgregarContacto(); break;
		case 2: arr->opModificarContacto(); break;
		case 3: arr->opEliminarContacto(); break;
		case 4: arr->mostrarContactosCumpleanosMayo(); break;
		//case 5: arr->mostrarContactosCaros(); break;
		case 6: arr->mostrarTodosLosContactos(); break;
		}
		system("pause>0");
		system("cls");
	}
	system("pause>0");
	return 0;
}