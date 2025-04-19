#include "ArrProducto.hpp"
#include "ArrProveedor.hpp"

int menu() {
	int opc;
	do {
		cout << "\tMENU\n";
		cout << "1) Insertar producto:\n";
		cout << "2) Insertar proveedor:\n";
		cout << "3) Modificar producto:\n";
		cout << "4) Eliminar productos vencidos:\n";
		cout << "5) Reportes:\n";
		cout << "6) Salir\n";
		cout << "Ingrese opcion: "; cin >> opc;
	} while (opc < 1 || opc > 6);
	return opc;
}
int main()
{
	srand(time(nullptr));
	Proveedor* prov = new Proveedor();
	ArrProducto* products = new ArrProducto();
	ArrProveedor* proveedores = new ArrProveedor();
	//products->agregarElemento(new Producto(prov));
	//products->agregarElemento(new Producto(prov));
	//products->agregarElemento(new Producto(prov));
	bool termino;
	string razonSocial;
	do
	{
		system("cls");
		termino = false;
		switch (menu())
		{
		case 1: 
			products->agregarElemento(new Producto()); 
			products->modificarUltimoElemento();
			break;
		case 2:
			cout << "Ingrese razon social: ";
			cin >> razonSocial;
			proveedores->agregarElemento(new Proveedor(razonSocial));
			break;
		case 3:
			int pos;
			cout << "Ingrese posicion a de producto a modificar: ";
			cin >> pos;
			products->getElemento(pos)->modificarProducto();
			break;
		case 4:
			products->eliminarVencidos();
			break;
		case 5:
			products->mostrarTodos();
			break;
		case 6:
			termino = true;
			break;
		}
		system("pause");
	} while (!termino);
	system("pause>0");
	return 0;
}