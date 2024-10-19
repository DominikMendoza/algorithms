#pragma once
#include "Figura.h"
#include "Triangulo.h"
#include "Circulo.h"
#include "Elipse.h"
#include "Rectangulo.h"
#include "Cuadrado.h"
#include "vector"

using namespace std;

class Controladora
{
public:
	Controladora(Graphics^ g);
	~Controladora();
	void dibujarTodos(Graphics^ g);
	void moverTodos(Graphics^ g);
	void agregarTriangulo();
	void agregarCirculo();
	void agregarElipse();
	void agregarCuadrado();
	void agregarRectangulo();
private:
	vector<Figura*> listaFiguras;
	int ancho;
	int alto;
};

