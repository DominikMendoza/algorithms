#pragma once
#include "Hulk.h"

class Juego
{
private:
	Hulk* hulk;

public:
	Juego();
	~Juego();
	void Dibujar(Graphics^ g, Bitmap^ imgHulk);
	void Mover(Graphics^ g);
	void Iniciar(Graphics^ g, Bitmap^ imgHulk);
	Hulk* getHulk();
};

Juego::Juego()
{
	hulk = new Hulk();
}

Juego::~Juego()
{
	delete hulk;
}

void Juego::Dibujar(Graphics^ g, Bitmap^ imgHulk)
{
	hulk->DibujarHulk(g, imgHulk);
}

void Juego::Mover(Graphics^ g)
{
	hulk->MoverHulk(g);
}

void Juego::Iniciar(Graphics^ g, Bitmap^ imgHulk)
{
	Mover(g);
	Dibujar(g, imgHulk);
}

Hulk* Juego::getHulk()
{
	return hulk;
}