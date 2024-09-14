#pragma once
#include "CArrCompra.hpp"
#include "CArrCliente.hpp"
class CSuperMercado
{
private:
	CArrCompra* compras;
	CArrProducto* stock;
	CArrCliente* clientes;
public:
	CSuperMercado();
	~CSuperMercado();

	void surtirMercado();
	void mostrarStock();
	void realizarCompra();
	bool comprobarStockDeProducto(long long codProducto, long long cantidad);
	void comprarProducto(CCompra* compra, long long codProducto, long long cantidad);
	void mostrarResumenDeCompras();
	void cualquierCosa();
};

CSuperMercado::CSuperMercado()
{
	this->compras = new CArrCompra();
	this->stock = new CArrProducto();
	this->clientes = new CArrCliente();
}

CSuperMercado::~CSuperMercado()
{
}

void CSuperMercado::mostrarStock()
{
	cout << "STOCK DEL SUPERMERCADO\n";
	stock->mostrarElementos();
	cout << "\n--------------------\n";
}

void CSuperMercado::realizarCompra()
{
	long long codProd, cantidad;
	short opc;
	CCompra* nuevaCompra = new CCompra();
	do
	{
		cout << "1. Seguir comprando\n";
		cout << "2. Salir...\n";
		cin >> opc;
		if (opc == 2) break;
		cout << "Ingrese producto a comprar: "; cin >> codProd;
		cout << "Ingrese cantidad del producto: "; cin >> cantidad;
		comprarProducto(nuevaCompra, codProd, cantidad);
		system("cls");
		mostrarStock();

	} while (opc != 2);
	nuevaCompra->mostrarDatos();
	compras->agregarElemento(nuevaCompra);
}

void CSuperMercado::surtirMercado()
{
	for (int i = 0; i < 4; i++)
	{
		stock->agregarElemento(new CProducto());
	}
}

bool CSuperMercado::comprobarStockDeProducto(long long codProducto, long long cantidad)
{
	CProducto* prod = stock->getElementoByCode(codProducto);
	return prod->getCantidad() >= cantidad;
}

void CSuperMercado::comprarProducto(CCompra* compra, long long codProducto, long long cantidad)
{
	if (!comprobarStockDeProducto(codProducto, cantidad)) {
		cout << "No hay stock suficiente....\n";
		return;
	}
	// Encontramos el producto
	CProducto* producto = stock->getElementoByCode(codProducto);
	// Creamos una copia y se la compramos
	CProducto* productoComprado = producto->getDuplicado(cantidad);
	compra->agregarProducto(productoComprado);

	// reducir el stock
	producto->setCantidad(producto->getCantidad() - cantidad);
}

void CSuperMercado::mostrarResumenDeCompras()
{
	cout << "\tRESUMEN DE COMPRASSSSSSSS\n";
	compras->mostrarElementos();
}

void CSuperMercado::cualquierCosa()
{

}
