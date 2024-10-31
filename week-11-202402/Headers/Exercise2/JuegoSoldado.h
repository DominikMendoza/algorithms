#pragma once
#include "Soldado.h"
#include "Bomba.h"
#include "Fruta.h"

class Juego
{
private:
	Soldado* soldado;
	vector<Bomba*>bombas;
	vector<Fruta*>frutas;
	int tiempo;

public:
	Juego();
	~Juego();
	void Dibujar(Graphics^ g, Bitmap^ imgSoldado, Bitmap^ imgBomba, Bitmap^ imgFrutas);
	void Mover(Graphics^ g);
	void Iniciar(Graphics^ g, Bitmap^ imgSoldado, Bitmap^ imgBomba, Bitmap^ imgFrutas);
	Soldado* getSoldado();
	void AgregarItems();
	void ColisionBombas();
	void ColisionFrutas();
	bool Perdiste();
};

Juego::Juego()
{
	soldado = new Soldado();
	tiempo = 0;
}

Juego::~Juego()
{
	delete soldado;
	for (int i = 0; i < bombas.size(); i++)
	{
		delete bombas[i];
	}
	for (int i = 0; i < frutas.size(); i++)
	{
		delete frutas[i];
	}
	bombas.clear();
	frutas.clear();
}

void Juego::Dibujar(Graphics^ g, Bitmap^ imgSoldado, Bitmap^ imgBomba, Bitmap^ imgFrutas)
{
	soldado->DibujarSoldado(g, imgSoldado);
	for (int i = 0; i < bombas.size(); i++)
	{
		bombas[i]->DibujarBomba(g, imgBomba);
	}
	for (int i = 0; i < frutas.size(); i++)
	{
		frutas[i]->DibujarFruta(g, imgFrutas);
	}
}

void Juego::Mover(Graphics^ g)
{
	soldado->MoverSoldado(g);
	for (int i = 0; i < bombas.size(); i++)
	{
		bombas[i]->MoverBomba();
	}
	for (int i = 0; i < frutas.size(); i++)
	{
		frutas[i]->MoverFruta();
	}
}

void Juego::Iniciar(Graphics^ g, Bitmap^ imgSoldado, Bitmap^ imgBomba, Bitmap^ imgFrutas)
{
	Mover(g);
	Dibujar(g, imgSoldado, imgBomba, imgFrutas);
	AgregarItems();
	ColisionBombas();
	ColisionFrutas();
}

Soldado* Juego::getSoldado()
{
	return soldado;
}

void Juego::AgregarItems()
{
	if (tiempo > 10) 
	{
		if (rand() % 2 == 0)
		{
			bombas.push_back(new Bomba());
		}
		else
		{
			frutas.push_back(new Fruta());
		}
		tiempo = 0;
	}
	tiempo++;
}

void Juego::ColisionBombas()
{
	for (int i = 0; i < bombas.size(); i++)
	{
		if (bombas[i]->mascara().IntersectsWith(soldado->mascara()))
		{
			soldado->BajarVida();
			bombas.erase(bombas.begin() + i);
			return;
		}
	}
}

void Juego::ColisionFrutas()
{
	for (int i = 0; i < frutas.size(); i++)
	{
		if (frutas[i]->mascara().IntersectsWith(soldado->mascara()))
		{
			soldado->SubirVida();
			frutas.erase(frutas.begin() + i);
			return;
		}
	}
}

bool Juego::Perdiste()
{
	return soldado->getVidas() <= 0;
}