#include "Controladora.h"

Controladora::Controladora(Graphics^ g)
{
	srand(time(nullptr));
	this->ancho = g->VisibleClipBounds.Width;
	this->alto = g->VisibleClipBounds.Height;
}

Controladora::~Controladora()
{

}

void Controladora::dibujarTodos(Graphics^ g)
{
	for (int i = 0; i < listaFiguras.size(); i++)
	{
		listaFiguras[i]->dibujar(g);
	}
}

void Controladora::moverTodos(Graphics^ g)
{
	for (int i = 0; i < listaFiguras.size(); i++)
	{
		listaFiguras[i]->mover(g);
	}
}

void Controladora::agregarTriangulo()
{
	listaFiguras.push_back(new Triangulo());
}

void Controladora::agregarCirculo() {
	listaFiguras.push_back(new Circulo());
}

void Controladora::agregarElipse() {
	listaFiguras.push_back(new Elipse());
}

void Controladora::agregarCuadrado() {
	listaFiguras.push_back(new Cuadrado());
}

void Controladora::agregarRectangulo() {
	listaFiguras.push_back(new Rectangulo());
}