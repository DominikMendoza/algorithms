#pragma once
#include "Triangulo.h"
#include "Circulo.h"

using namespace System;
using namespace System::Collections::Generic;

ref class Controladora
{
private:
	Random^ r;
	List<Circulo^>^ circulos;  
	List<Triangulo^>^ triangulos; 

public:
	Controladora();
	void AgregarCirculo(int ancho, int alto);
	void AgregarTriangulo(int ancho);
	void MoverFiguras();
	void DibujarFiguras(Graphics^ g);
	void DetectarColisiones();
};

Controladora::Controladora()
{
	r = gcnew Random();
	circulos = gcnew List<Circulo^>();
	triangulos = gcnew List<Triangulo^>();
}

void Controladora::AgregarCirculo(int ancho, int alto)
{
	if (r->Next(1000) % 50 == 0) //Cambiar a  % 10 para que se pueda ver mejor las colisiones en el juego.
	{
		int x = 0;
		int y = r->Next(alto);
		double diametro = r->Next(20, 50);
		Circulo^ nuevoCirculo = gcnew Circulo(x, y, diametro, Color::Blue);
		circulos->Add(nuevoCirculo);
	}
}

void Controladora::AgregarTriangulo(int ancho)
{
	int x = r->Next(ancho);
	int y = 0;
	int lado = r->Next(30, 60);
	Triangulo^ nuevoTriangulo = gcnew Triangulo(x, y, lado, Color::Green);
	triangulos->Add(nuevoTriangulo);
}

void Controladora::MoverFiguras()
{
	for (int i = 0; i < circulos->Count; i++)
	{
		if (circulos[i]->isVisible())
		{
			circulos[i]->MoverCirculo();
		}
	}

	for (int i = 0; i < triangulos->Count; i++)
	{
		if (triangulos[i]->isVisible())
		{
			triangulos[i]->MoverTriangulo();
		}
	}

	DetectarColisiones();
}

void Controladora::DibujarFiguras(Graphics^ g)
{
	for (int i = 0; i < circulos->Count; i++)
	{
		if (circulos[i]->isVisible())
		{
			circulos[i]->DibujarCirculo(g);
		}
	}

	for (int i = 0; i < triangulos->Count; i++)
	{
		if (triangulos[i]->isVisible())
		{
			triangulos[i]->DibujarTriangulo(g);
		}
	}
}

void Controladora::DetectarColisiones()
{
	for (int i = 0; i < triangulos->Count; i++)
	{
		if (!triangulos[i]->isVisible())
			continue;

		for (int j = 0; j < circulos->Count; j++)
		{
			if (!circulos[j]->isVisible())
				continue;

			// Usar las m�scaras para detectar colisiones
			if (triangulos[i]->mascara().IntersectsWith(circulos[j]->mascara()))
			{
				triangulos[i]->setVisible(false);
				circulos[j]->setVisible(false);
				break;
			}
		}
	}
}