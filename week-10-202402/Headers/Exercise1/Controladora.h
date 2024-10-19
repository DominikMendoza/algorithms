#pragma once
#include "Circulo.h"
#include "Elipse.h"
#include "Rectangulo.h"
#include "Triangulo.h"
#include "Cuadrado.h"

ref class Controladora
{
private:
	List<Circulo^>^ circulos;
	List<Elipse^>^ elipses;
	List<Rectangulo^>^ rectangulos;
	List<Triangulo^>^ triangulos;
	List<Cuadrado^>^ cuadrados;

public:
	Controladora();
	void AgregarCirculo(int ancho, int alto);
	void AgregarElipse(int ancho, int alto);
	void AgregarRectangulo(int ancho, int alto);
	void AgregarTriangulo(int ancho, int alto);
	void AgregarCuadrado(int ancho, int alto);
	void MoverFiguras(Graphics^ g);
	void DibujarFiguras(Graphics^ g);
};

Controladora::Controladora()
{
	circulos = gcnew List<Circulo^>();
	elipses = gcnew List<Elipse^>();
	rectangulos = gcnew List<Rectangulo^>();
	triangulos = gcnew List<Triangulo^>();
	cuadrados = gcnew List<Cuadrado^>();
}

void Controladora::AgregarCirculo(int ancho, int alto)
{
	Color color = Color::FromArgb(RandInt(0, 255), RandInt(0, 255), RandInt(0, 255));
	int radio = RandInt(20, 40);
	int dx = RandInt(-5, 5);
	int dy = RandInt(-5, 5);
	Circulo^ circulo = gcnew Circulo(RandInt(0, ancho - radio), RandInt(0, alto - radio), dx, dy, color, radio);
	circulos->Add(circulo);
}

void Controladora::AgregarElipse(int ancho, int alto)
{
	Color color = Color::FromArgb(RandInt(0, 255), RandInt(0, 255), RandInt(0, 255));
	int ejemayor = RandInt(40, 70);
	int ejemenor = RandInt(20, 40);
	int dx = RandInt(-5, 5);
	int dy = RandInt(-5, 5);
	Elipse^ elipse = gcnew Elipse(RandInt(0, ancho - ejemayor), RandInt(0, alto - ejemenor), dx, dy, color, ejemayor, ejemenor);
	elipses->Add(elipse);
}

void Controladora::AgregarRectangulo(int ancho, int alto)
{
	Color color = Color::FromArgb(RandInt(0, 255), RandInt(0, 255), RandInt(0, 255));
	int largo = RandInt(30, 55);
	int anchoRec = RandInt(20, 40);
	int dx = RandInt(-5, 5);
	int dy = RandInt(-5, 5);
	Rectangulo^ rectangulo = gcnew Rectangulo(RandInt(0, ancho - largo), RandInt(0, alto - anchoRec), dx, dy, color, largo, anchoRec);
	rectangulos->Add(rectangulo);
}

void Controladora::AgregarTriangulo(int ancho, int alto)
{
	Color color = Color::FromArgb(RandInt(0, 255), RandInt(0, 255), RandInt(0, 255));
	int lado = RandInt(25, 45);
	int dx = RandInt(-5, 5);
	int dy = RandInt(-5, 5);
	Triangulo^ triangulo = gcnew Triangulo(RandInt(0, ancho - lado), RandInt(0, alto - lado), dx, dy, color, lado);
	triangulos->Add(triangulo);
}

void Controladora::AgregarCuadrado(int ancho, int alto)
{
	Color color = Color::FromArgb(RandInt(0, 255), RandInt(0, 255), RandInt(0, 255));
	int lado = RandInt(25, 45);
	int dx = RandInt(-5, 5);
	int dy = RandInt(-5, 5);
	Cuadrado^ cuadrado = gcnew Cuadrado(RandInt(0, ancho - lado), RandInt(0, alto - lado), dx, dy, color, lado);
	cuadrados->Add(cuadrado);
}

void Controladora::MoverFiguras(Graphics^ g)
{
	for (int i = 0; i < circulos->Count; i++)
	{
		circulos[i]->Mover(g);
	}
	for (int i = 0; i < elipses->Count; i++)
	{
		elipses[i]->Mover(g);
	}
	for (int i = 0; i < rectangulos->Count; i++)
	{
		rectangulos[i]->Mover(g);
	}
	for (int i = 0; i < triangulos->Count; i++)
	{
		triangulos[i]->Mover(g);
	}
	for (int i = 0; i < cuadrados->Count; i++)
	{
		cuadrados[i]->Mover(g);
	}
}

void Controladora::DibujarFiguras(Graphics^ g)
{
	for (int i = 0; i < circulos->Count; i++)
	{
		circulos[i]->Dibujar(g);
	}
	for (int i = 0; i < elipses->Count; i++)
	{
		elipses[i]->Dibujar(g);
	}
	for (int i = 0; i < rectangulos->Count; i++)
	{
		rectangulos[i]->Dibujar(g);
	}
	for (int i = 0; i < triangulos->Count; i++)
	{
		triangulos[i]->Dibujar(g);
	}
	for (int i = 0; i < cuadrados->Count; i++)
	{
		cuadrados[i]->Dibujar(g);
	}
}