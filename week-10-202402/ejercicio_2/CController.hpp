#pragma once
#include <iostream>
#include <vector>
#include "CTriangulo.hpp"
#include "CRectangulo.hpp"
#include "CElipse.hpp"

using namespace std;

class CController
{
private:
	vector<CFigura*> figuras;
	int coordXMeta;
	int partidasJugadas;
	vector<int> puntajes;
public:
	CController(Graphics^ g);
	~CController();
	void dibujarTodos(Graphics^ g);
	void dibujarMeta(Graphics^ g);
	void moverTodos(Graphics^ g);
	void restaurarPosiciones();
	string getNombrePrimerLugar();
	string getNombreSegundoLugar();
	string getNombreTercerLugar();
	string getResumenDeCarrera();
	bool acaboJuego();
};

CController::CController(Graphics^ g)
{
	srand(time(nullptr));
	int numeroFiguras = 3;
	int seccion = g->VisibleClipBounds.Height / numeroFiguras;
	this->coordXMeta = g->VisibleClipBounds.Width - 50;
	this->partidasJugadas = 0;
	figuras.push_back(new CTriangulo(10, 30, rand() % 15 + 5));
	figuras.push_back(new CRectangulo(10, seccion + 30, rand() % 15 + 5));
	figuras.push_back(new CElipse(10, 2 * seccion + 30, rand() % 15 + 5));
	for (int i = 0; i < numeroFiguras; i++)
	{
		puntajes.push_back(0);
	}
}

CController::~CController()
{
}

void CController::dibujarTodos(Graphics^ g)
{
	for (int i = 0; i < figuras.size(); i++)
	{
		figuras[i]->dibujar(g);
	}
}

void CController::dibujarMeta(Graphics^ g)
{
	Pen^ pencil = gcnew Pen(Color::Gold, 3);
	g->DrawLine(pencil, Point(this->coordXMeta, 10), Point(this->coordXMeta, g->VisibleClipBounds.Height - 10));
}

void CController::moverTodos(Graphics^ g)
{
	for (int i = 0; i < figuras.size(); i++)
	{
		figuras[i]->mover(g);
		if (figuras[i]->getXAncho() >= coordXMeta) {
			puntajes[i]++;
			partidasJugadas++;
			restaurarPosiciones();
		}
	}
}

void CController::restaurarPosiciones()
{
	for (int i = 0; i < figuras.size(); i++)
	{
		figuras[i]->resetar();
	}
}

string CController::getNombrePrimerLugar()
{
	
	for (int i = 0; i < 3; i++)
	{
		if (puntajes[i] >= puntajes[0] && puntajes[i] >= puntajes[1] && puntajes[i] >= puntajes[2]) {
			return figuras[i]->getNombre();
		}
	}
}

string CController::getNombreSegundoLugar()
{
	return "segundo lugar";
}

string CController::getNombreTercerLugar()
{
	return "tercer lugar";
}

string CController::getResumenDeCarrera()
{
	string resumen = "";
	for (int i = 0; i < 3; i++)
	{
		resumen += figuras[i]->getNombre() + ": " + to_string(puntajes[i]) + "\n";
	}
	return resumen;
}

bool CController::acaboJuego()
{
	return this->partidasJugadas >= 2;
}
