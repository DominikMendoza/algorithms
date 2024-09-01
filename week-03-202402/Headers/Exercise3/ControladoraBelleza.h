#pragma once
#include "VectorCompras.h"
#include "VectorClientes.h"
#include "VectorProductosBelleza.h"

class Controladora
{
private:
	VectorCompras* vectorcompras;
	VectorClientes* vectorclientes;
	VectorProductos* vectorproductos;

public:
	Controladora();
	~Controladora();
	void IngresarProducto();
	void IngresarCliente();
	void RealizarCompra();
	void AgregarCantidadAStock();
	void MostrarProductos();
	void MostrarClientes();
	void MostrarCompras();
	bool existeProducto();
	bool existeCliente();
	bool existeCompra();
};

Controladora::Controladora()
{
	vectorcompras = new VectorCompras();
	vectorclientes = new VectorClientes();
	vectorproductos = new VectorProductos();
}

Controladora::~Controladora()
{
	delete vectorcompras;
	delete vectorclientes;
	delete vectorproductos;
}

void Controladora::IngresarProducto()
{
	int codProducto, cantidad;
	string nombre, tipo, marca;
	double precio;
	do
	{
		cout << "Ingrese el codigo del producto: "; cin >> codProducto;
		if (codProducto < 1000 || codProducto > 9999)
		{
			cout << "El codigo de producto debe tener exactamente 4 digitos. Ingrese otro codigo." << endl;
		}
		else if (vectorproductos->existeCodProducto(codProducto))
		{
			cout << "El codigo de producto ya existe. Ingrese otro codigo." << endl;
		}
	} while ((codProducto < 1000 || codProducto > 9999) || vectorproductos->existeCodProducto(codProducto));
	cin.ignore();
	cout << "Ingrese el nombre del producto: ";
	getline(cin, nombre);
	cout << "Ingrese el tipo del producto: ";
	getline(cin, tipo);
	cout << "Ingrese la marca del producto: ";
	getline(cin, marca);
	do
	{
		cout << "Ingrese la cantidad de productos: "; cin >> cantidad;
	} while (cantidad < 1);
	do
	{
		cout << "Ingrese el precio del producto: "; cin >> precio;
	} while (precio < 1);
	Producto* producto = new Producto(codProducto, nombre, tipo, marca, cantidad, precio);
	vectorproductos->agregarProducto(producto);
	cout << endl << "PRODUCTO INGRESADO CORRECTAMENTE!!" << endl;
}

void Controladora::IngresarCliente()
{
	string nombre, DNI;
	do
	{
		cout << "Ingrese el DNI del cliente: "; cin >> DNI;
		if (vectorclientes->existeDNICliente(DNI))
		{
			cout << "El DNI ya existe. Ingrese otro DNI." << endl;
		}
	} while (vectorclientes->existeDNICliente(DNI));
	cout << "Ingrese el nombre del cliente: ";
	cin.ignore();
	getline(cin, nombre);
	Cliente* cliente = new Cliente(DNI, nombre);
	vectorclientes->agregarCliente(cliente);
	cout << endl << "CLIENTE INGRESADO CORRECTAMENTE!!" << endl;
}

void Controladora::RealizarCompra()
{
	long long idCompra;
	string fecha, DNI;
	do
	{
		cout << "Ingrese el ID de la compra: "; cin >> idCompra;
		if (idCompra < 1000000000 || idCompra > 9999999999)
		{
			cout << "El ID de compra debe tener exactamente 10 digitos. Ingrese otro ID." << endl;
		}
		else if (vectorcompras->existeIDCompra(idCompra))
		{
			cout << "El ID de compra ya existe. Ingrese otro ID." << endl;
		}
	} while ((idCompra < 1000000000 || idCompra > 9999999999) || vectorcompras->existeIDCompra(idCompra));
	cin.ignore();
	cout << "Ingrese la fecha de la compra: ";
	getline(cin, fecha);
	Cliente* cliente = nullptr;
	do
	{
		cout << "Ingrese el DNI del cliente: "; cin >> DNI;
		for (int i = 0; i < vectorclientes->getNumClientes(); i++)
		{
			if (vectorclientes->getDatosCliente(i)->getDNI() == DNI)
			{
				cliente = vectorclientes->getDatosCliente(i);
				break;
			}
		}
		if (cliente == nullptr)
		{
			cout << "Cliente no encontrado!" << endl;
		}
	} while (cliente == nullptr);
	Compra* compra = new Compra(idCompra, fecha, cliente);
	int codProducto;
	int cantidad;
	do 
	{
		cout << "Ingrese el codigo del producto que desea comprar: "; cin >> codProducto;
	} while (codProducto < 1000 || codProducto > 9999);
	while (codProducto != 0)
	{
		Producto* producto = nullptr;
		for (int i = 0; i < vectorproductos->getNumProductos(); i++)
		{
			if (vectorproductos->getDatosProducto(i)->getCodProducto() == codProducto)
			{
				producto = vectorproductos->getDatosProducto(i);
				break;
			}
		}
		if (producto == nullptr)
		{
			cout << "Producto no encontrado!" << endl;
		}
		else
		{
			do
			{
				cout << "Ingrese la cantidad que desea comprar: "; cin >> cantidad;
			} while (cantidad < 1);
			if (producto->getCantidad() >= cantidad)
			{
				// Crear una copia del producto con la cantidad comprada y agregarla a la compra
				Producto* productoComprado = new Producto(producto->getCodProducto(), producto->getNombre(), producto->getTipo(), producto->getMarca(), cantidad, producto->getPrecio());
				compra->agregarProducto(productoComprado, cantidad);
				vectorproductos->reducirCantidadProducto(codProducto, cantidad);
				cout << "Producto agregado a la compra y stock actualizado" << endl;
			}
			else
			{
				cout << "Cantidad insuficiente en stock para el producto " << producto->getNombre() << endl;
			}
		}

		do
		{
			cout << endl << "Ingrese el codigo de otro producto (0 para finalizar): "; cin >> codProducto;
		} while ((codProducto < 1000 || codProducto > 9999) && codProducto != 0);
	}
	vectorcompras->agregarCompra(compra);
	cout << endl << "COMPRA FINALIZADA!!" << endl;
}

void Controladora::AgregarCantidadAStock()
{
	int codProducto;
	Producto* producto = nullptr;
	do
	{
		cout << "Ingrese el codigo del producto al que desea reestablecer el stock: "; cin >> codProducto;
		if (codProducto < 1000 || codProducto > 9999)
		{
			cout << "El codigo del producto debe ser de 4 digitos. Intente de nuevo." << endl;
			continue;
		}
		for (int i = 0; i < vectorproductos->getNumProductos(); i++)
		{
			if (vectorproductos->getDatosProducto(i)->getCodProducto() == codProducto)
			{
				producto = vectorproductos->getDatosProducto(i);
				break;
			}
		}
		if (producto == nullptr)
		{
			cout << "Codigo de producto no encontrado. Ingrese otro codigo." << endl;
		}
	} while (producto == nullptr); 
	int cantidadAgregar;
	do
	{
		cout << "Ingrese la cantidad a agregar al stock del producto " << producto->getNombre() << ": "; cin >> cantidadAgregar;
		if (cantidadAgregar <= 0)
		{
			cout << "La cantidad a agregar debe ser mayor a 0!" << endl;
		}
	} while (cantidadAgregar <= 0);
	producto->setCantidad(producto->getCantidad() + cantidadAgregar);
	cout << endl << "STOCK ACTUALIZADO CORRECTAMENTE!!" << endl;
}

void Controladora::MostrarProductos()
{
	cout << "\t\t\tLISTA DE PRODUCTOS\n\n";
	for (int i = 0; i < vectorproductos->getNumProductos(); i++)
	{
		vectorproductos->getDatosProducto(i)->mostrarProducto();
		cout << endl;
	}
}

void Controladora::MostrarClientes()
{
	cout << "\t\t\tLISTA DE CLIENTES\n\n";
	for (int i = 0; i < vectorclientes->getNumClientes(); i++)
	{
		vectorclientes->getDatosCliente(i)->mostrarCliente();
		cout << endl;
	}
}

void Controladora::MostrarCompras()
{
	cout << "\t\t\tLISTA DE COMPRAS\n\n";
	for (int i = 0; i < vectorcompras->getNumCompras(); i++)
	{
		vectorcompras->getDatosCompra(i)->mostrarCompra();
		cout << endl;
	}
}

bool Controladora::existeProducto()
{
	return vectorproductos->getNumProductos() > 0;
}

bool Controladora::existeCliente()
{
	return vectorclientes->getNumClientes() > 0;
}

bool Controladora::existeCompra()
{
	return vectorcompras->getNumCompras() > 0;
}