#include "CListaContacto.hpp"

short showMenu() {
	short opc;
	do {
		cout << "\tMENU\n";
		cout << "1. Agregar contacto\n";
		cout << "2. Modificar datos de un contacto\n";
		cout << "3. Eliminar un contacto\n";
		cout << "4. Reporte de contactos que cumplen anios en mayo\n";
		cout << "5. Reporte de contactos que son hombres\n";
		cout << "6. Reporte de contactos que usan Facebook o Whatsapp\n";
		cout << "7. Mostrar todos los contactos\n";
		cout << "8. Salir\n";
		cout << "Ingrese la opcion...";
		cin >> opc;
	} while (opc < 1 || opc > 8);
	return opc;
}
int main() {
	srand(time(nullptr));
	CListaContacto* lista = new CListaContacto();
	for (int i = 0; i < 10; i++) {
		lista->addContacto(new CContacto());
	}
	while (true) {
		switch (showMenu()) {
		case 1: lista->opAgregarContacto(); break;
		case 2: lista->opModificarContacto(); break;
		case 3: lista->opEliminarContacto(); break;
		case 4: lista->mostrarListaContactosMayo(); break;
		case 5: lista->mostrarListaContactosVarones(); break;
		case 6: lista->mostrarListaContactosFacebookOWhatsapp(); break;
		case 7: lista->mostrarListaContactos(); break;
		case 8: return 0;
		}
		system("pause>0");
		system("cls");
	}
	system("pause>0");
	return 0;
}