#include "CSuperMercado.hpp"
int main()
{
	srand(time(nullptr));
	CSuperMercado* sm = new CSuperMercado();
	sm->surtirMercado();
	sm->mostrarStock();
	short opc;
	do
	{
		cout << "1. Nueva Compra\n";
		cout << "2. Salir...\n";
		cin >> opc;
		if (opc == 2) break;
		sm->realizarCompra();
	} while (opc != 2);
	sm->realizarCompra();
	sm->mostrarStock();
	sm->mostrarResumenDeCompras();
	system("pause>0");
	return 0;
}