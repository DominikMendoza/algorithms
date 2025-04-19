#pragma once
#include "Proveedor.hpp"
class Producto
{
private:
	int idProducto;
	string nombre;
	string tipo;
	int cantidad;
	char categoria;
	int anio;
	float precio;
	Proveedor* prov;
public:
	Producto();
	Producto(Proveedor* prov);
	~Producto();
	void modificarProducto();
	void mostrar();
	void setProveedor(Proveedor* prov);
	char getCategoria();
	int getAnio();
	Proveedor* getProveedor();
};

Producto::Producto()
{
	idProducto = rand() % (999 - 100 + 1) + 100;
	nombre = "Product-default";
	tipo = "polvo";
	cantidad = rand() % (20 - 10 + 1) + 10;
	categoria = rand() % (3) + 'A';
	anio = rand() % (2025 - 2003 + 1) + 2003;
	precio = (rand() % (9999 - 1000 + 1) + 1000) / 10.0;
	prov = nullptr;
}

Producto::Producto(Proveedor* prov)
{
	idProducto = rand() % (999 - 100 + 1) + 100;
	nombre = "Product-default";
	tipo = "polvo";
	cantidad = rand() % (20 - 10 + 1) + 10;
	categoria = rand() % (3) + 'A';
	anio = rand() % (2025 - 2003 + 1) + 2003;
	precio = (rand() % (9999 - 1000 + 1) + 1000) / 10.0;
	this->prov = prov;
}

Producto::~Producto()
{
}

void Producto::modificarProducto()
{
	cout << "Ingrese nuevo nombre: ";
	cin >> nombre;
	cout << "Ingrese nueva cantidad: ";
	cin >> cantidad;
	cout << "Ingrese nueva categoria (A/B/C): ";
	cin >> categoria;
	cout << "Ingrese nuevo precio: ";
	cin >> precio;
}

void Producto::mostrar()
{
	cout << "ID Producto: " << idProducto << endl;
	cout << "Nombre: " << nombre << endl;
	cout << "Tipo: " << tipo << endl;
	cout << "Cantidad: " << cantidad << endl;
	cout << "Categoria: " << categoria << endl;
	cout << "Anio: " << anio << endl;
	cout << "Precio: S/" << precio << endl;

	if (prov == nullptr) {
		cout << "Proveedor: No asignado" << endl;
	}
	else {
		cout << "Proveedor:" << prov->getRuc() << endl;
	}
	cout << endl;
}

void Producto::setProveedor(Proveedor* prov)
{
	this->prov = prov;
}

char Producto::getCategoria()
{
	return this->categoria;
}

int Producto::getAnio()
{
	return this->anio;
}

inline Proveedor* Producto::getProveedor()
{
	return this->prov;
}
