#pragma once
#include "Tortuga.h"

class Juego
{
private:
	vector<Tortuga*>tortugas;

public:
	Juego();
	~Juego();
	void Dibujar(Graphics^ g, Bitmap^ img);
	void Mover();
	void Iniciar(Graphics^ g, Bitmap^ img);
	void AgregarTortugas();
	void DibujarMeta(Graphics^ g);
	Rectangle mascaraMeta();
	bool ExisteGanador();
};

Juego::Juego()
{
	AgregarTortugas();
}

Juego::~Juego()
{
	for (int i = 0; i < tortugas.size(); i++)
	{
		delete tortugas[i];
	}
	tortugas.clear();
}

void Juego::Dibujar(Graphics^ g, Bitmap^ img)
{
	for (int i = 0; i < tortugas.size(); i++)
	{
		tortugas[i]->DibujarTortuga(g, img);
	}
}

void Juego::Mover()
{
	for (int i = 0; i < tortugas.size(); i++)
	{
		tortugas[i]->MoverTortuga();
	}
}

void Juego::Iniciar(Graphics^ g, Bitmap^ img)
{
	Mover();
	Dibujar(g, img);
	DibujarMeta(g);
}

void Juego::AgregarTortugas()
{
	int cantidad = RandInt(3, 6);
	int y = 30;
	for (int i = 0; i < cantidad; i++)
	{
		tortugas.push_back(new Tortuga(10, y));
		y += 90;
	}
}

void Juego::DibujarMeta(Graphics^ g)
{
	g->FillRectangle(Brushes::Gray, 1300, 10, 20, 680);
}

Rectangle Juego::mascaraMeta()
{
	return Rectangle(1300, 10, 20, 680);
}

bool Juego::ExisteGanador()
{
	for (int i = 0; i < tortugas.size(); i++)
	{
		if (tortugas[i]->mascara().IntersectsWith(mascaraMeta()))
		{
			return true;
		}
	}
	return false;
}