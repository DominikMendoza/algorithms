#pragma once
#include "VectorProveedores.h"
#include "VectorProductos.h"

class Controladora
{
private:
	VectorProductos* vectorproductos;
	VectorProveedores* vectorproveedores;

public:
	Controladora();
	~Controladora();
	void InsertarProducto();
	void InsertarProveedor();
	bool existenProveedores();
	bool existeProveedorRUC(long long ruc);
	void ModificarProducto();
	bool existenProductos();
	void EliminarProductosProveedorHerbalife();
	void EliminarProductosVencidos();
	void MostrarProductosCategoriaANatura();
	void MostrarTodosProductos();
	void Reportes();
};

Controladora::Controladora()
{
	vectorproductos = new VectorProductos();
	vectorproveedores = new VectorProveedores();
}

Controladora::~Controladora()
{
	delete vectorproductos;
	delete vectorproveedores;
}

void Controladora::InsertarProducto()
{
	int idproducto, cantidad, a�o;
	string nombre, tipo;
	char categoriaproduc;
	double precio; 
	long long ruc;
	do
	{
		cout << "Ingrese ID del producto: "; cin >> idproducto;
	} while (idproducto < 1000 || idproducto > 9999);
	cin.ignore();
	cout << "Ingrese el nombre del producto: ";
	getline(cin, nombre);
	cout << "Ingrese el tipo del producto (polvo o liquido): "; cin >> tipo;
	do
	{
		cout << "Ingrese la cantidad de productos: "; cin >> cantidad;
	} while (cantidad < 1);
	do
	{
		cout << "Ingrese la categoria del producto (A,B o C): "; cin >> categoriaproduc;
		categoriaproduc = toupper(categoriaproduc);
	} while (categoriaproduc != 'A' && categoriaproduc != 'B' && categoriaproduc != 'C');
	do
	{
		cout << "Ingrese el anual del producto: "; cin >> a�o;
	} while (a�o < 1950 || a�o > 2100);
	do
	{
		cout << "Ingrese el precio del producto: "; cin >> precio;
	} while (precio < 1);
	do
	{
		cout << "Ingrese el ruc del proveedor: "; cin >> ruc;
		if (!existeProveedorRUC(ruc))
		{
			cout << "No hay un proveedor con el ruc ingresado. Por favor, ingrese otro ruc." << endl;
		}
	} while (!existeProveedorRUC(ruc));
	Proveedor* proveedor = nullptr;
	for (int i = 0; i < vectorproveedores->getNumProveedores(); i++)
	{
		if (vectorproveedores->obtenerDatosProveedor(i)->getRuc() == ruc)
		{
			proveedor = vectorproveedores->obtenerDatosProveedor(i);
			break;
		}
	}
	if (proveedor == nullptr)
	{
		cout << "Proveedor con RUC " << ruc << " no encontrado." << endl;
		return;
	}
	Producto* producto = new Producto(idproducto, nombre, tipo, cantidad, categoriaproduc, a�o, precio, proveedor);
	vectorproductos->agregarProducto(producto);
}

void Controladora::InsertarProveedor()
{
	long long ruc, telefono;
	string nombre, categoriaprove, direccion;
	do
	{
		cout << "Ingrese el ruc del proveedor: "; cin >> ruc;
	} while (ruc < 10000000000 || ruc > 99999999999);
	cin.ignore();
	cout << "Ingrese el nombre del proveedor: ";
	getline(cin, nombre);
	cout << "Ingrese la categoria del proveedor: ";
	getline(cin, categoriaprove);
	cout << "Ingrese la direccion del proveedor: ";
	getline(cin, direccion);
	do
	{
		cout << "Ingrese el telefono del proveedor: "; cin >> telefono;
	} while (telefono < 900000000 || telefono > 999999999);
	Proveedor* proveedor = new Proveedor(ruc, nombre, categoriaprove, direccion, telefono);
	vectorproveedores->agregarProveedor(proveedor);
}

bool Controladora::existenProveedores()
{
	return vectorproveedores->getNumProveedores() > 0;
}

bool Controladora::existeProveedorRUC(long long ruc)
{
	for (int i = 0; i < vectorproveedores->getNumProveedores(); i++)
	{
		if (vectorproveedores->obtenerDatosProveedor(i)->getRuc() == ruc)
		{
			return true;
		}
	}
	return false;
}

bool Controladora::existenProductos()
{
	return vectorproductos->getNumProductos() > 0;
}

void Controladora::ModificarProducto()
{
	bool found = false;
	string nombre, tipo;
	double precio;
	char categoriaproduc;
	int idproducto, cantidad, a�o;
	cin.ignore();
	do {
		found = false;
		cout << "Ingrese el nombre del producto a modificar: ";
		getline(cin, nombre);

		for (int i = 0; i < vectorproductos->getNumProductos(); i++)
		{
			Producto* producto = vectorproductos->obtenerDatosProducto(i);
			if (producto->getNombre() == nombre)
			{
				do
				{
					cout << "Ingrese nuevo ID del producto: "; cin >> idproducto;
				} while (idproducto < 1000 || idproducto > 9999);
				cin.ignore();
				cout << "Ingrese nuevo nombre del producto: ";
				getline(cin, nombre);
				cout << "Ingrese nuevo tipo del producto (polvo o liquido): "; cin >> tipo;
				do
				{
					cout << "Ingrese nueva cantidad de productos: "; cin >> cantidad;
				} while (cantidad < 1);
				do
				{
					cout << "Ingrese nueva categoria del producto (A,B o C): "; cin >> categoriaproduc;
					categoriaproduc = toupper(categoriaproduc);
				} while (categoriaproduc != 'A' && categoriaproduc != 'B' && categoriaproduc != 'C');
				do
				{
					cout << "Ingrese nuevo anual del producto: "; cin >> a�o;
				} while (a�o < 1950 || a�o > 2100);
				do
				{
					cout << "Ingrese nuevo precio del producto: "; cin >> precio;
				} while (precio < 1);
				producto->setIDProducto(idproducto);
				producto->setNombre(nombre);
				producto->setTipo(tipo);
				producto->setCantidad(cantidad);
				producto->setCategoria(categoriaproduc);
				producto->setA�o(a�o);
				producto->setPrecio(precio);
				found = true;
				cout << endl << "SE MODIFICO CON EXITO EL PRODUCTO!!" << endl;
				return;
			}
		}
		if (!found)
		{
			cout << "NO SE ENCONTRO UN PRODUCTO CON ESTE NOMBRE. POR FAVOR, INGRESE OTRO NOMBRE." << endl;
		}

	} while (!found);
}

void Controladora::EliminarProductosProveedorHerbalife()
{
	bool found = false;
	for (int i = vectorproductos->getNumProductos() - 1; i >= 0; i--)
	{
		if (vectorproductos->obtenerDatosProducto(i)->getProveedor()->getNombre() == "Herbalife")
		{
			vectorproductos->eliminarProducto(i);
			found = true;
		}
	}
	if (found)
	{
		cout << "SE ELIMINARON CON EXITO LOS PRODUCTOS CON PROVEEDOR HERBALIFE!" << endl;
	}
	else
	{
		cout << "NO HAY PRODUCTOS CON PROVEEDOR HERBALIFE!" << endl;
	}
}

void Controladora::EliminarProductosVencidos()
{
	bool found = false;
	for (int i = vectorproductos->getNumProductos() - 1; i >= 0; i--)
	{
		if (vectorproductos->obtenerDatosProducto(i)->getA�o() < 2020)
		{
			vectorproductos->eliminarProducto(i);
			found = true;
		}
	}
	if (found)
	{
		cout << "SE ELIMINARON CON EXITO LOS PRODUCTOS VENCIDOS!" << endl;
	}
	else
	{
		cout << "NO HAY PRODUCTOS VENCIDOS!" << endl;
	}
}

void Controladora::MostrarProductosCategoriaANatura()
{
	bool found = false;
	for (int i = 0; i < vectorproductos->getNumProductos(); i++)
	{
		Producto* producto = vectorproductos->obtenerDatosProducto(i);
        if (producto->getCategoria() == 'A' && producto->getProveedor()->getNombre() == "Natura")
        {
			if (!found)
			{
				cout << "\t\tPRODUCTOS DE CATEGORIA A CUYO PROVEEDOR ES NATURA\n\n";
				found = true;
			}
			producto->mostrarProducto();
        }
	}
	if (!found)
	{
		cout << "NO HAY PRODUCTOS DE CATEGORIA A CUYO PROVEEDOR ES NATURA!" << endl;
	}
}

void Controladora::MostrarTodosProductos()
{
	for (int i = 0; i < vectorproductos->getNumProductos(); i++)
	{
		Producto* producto = vectorproductos->obtenerDatosProducto(i);
		producto->mostrarProducto();
	}
}

void Controladora::Reportes()
{
	cout << "\t\tREPORTE DE TODOS LOS PRODUCTOS EN STOCK CON SUS RESPECTIVOS PROVEEDORES\n\n";
	MostrarTodosProductos();
}