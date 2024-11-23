#pragma once
#include "Bala.hpp"
#include "Avion.hpp"
#include "Enemigo.hpp"
#include <vector>
using namespace std;
class Controller
{
private:
	vector<Bala*> balas;
	vector<Enemigo*> enemigos;
	Avion* avion;
	int puntos;
public:
	Controller(Graphics^ g, int widthAvion, int heightAvion, int widthEnemigo, int heightEnemigo);
	~Controller();
	void moverTodos(Graphics^ g);
	void dibujarTodos(Graphics^ g, Bitmap^ bmpBala, Bitmap^ bmpEnemigo, Bitmap^ bmpAvion);
	void moverAvion(Graphics^ g, char tecla);
	void evaluarColisiones();
	void agregarBala(int widthBala, int heightbala);
	void agregarEnemigo(int widthEnemigo, int heightEnemigo);
	int getVidasAvion();
	int getPuntos();

};

Controller::Controller(Graphics^ g, int widthAvion, int heightAvion, int widthEnemigo, int heightEnemigo)
{
	srand(time(nullptr));
	this->puntos = 0;
	avion = new Avion(0, 0, widthAvion, heightAvion);
	int widthMax = g->VisibleClipBounds.Width;
	int heightMax = g->VisibleClipBounds.Height;
	for (int i = 0; i < (rand() % 5 + 3); i++)
	{
		enemigos.push_back(new Enemigo(i * 150, i * 100,
			widthEnemigo, heightEnemigo));
	}
}

Controller::~Controller()
{
}

void Controller::moverTodos(Graphics^ g)
{
	for (int i = 0; i < balas.size(); i++)
	{
		balas[i]->mover(g);
	}
	for (int i = 0; i < enemigos.size(); i++)
	{
		enemigos[i]->mover(g);
	}
}

void Controller::dibujarTodos(Graphics^ g, Bitmap^ bmpBala, Bitmap^ bmpEnemigo, Bitmap^ bmpAvion)
{
	for (int i = 0; i < balas.size(); i++)
	{
		balas[i]->dibujar(g, bmpBala);
	}
	for (int i = 0; i < enemigos.size(); i++)
	{
		enemigos[i]->dibujar(g, bmpEnemigo);
	}
	avion->dibujar(g, bmpAvion);
}

void Controller::moverAvion(Graphics^ g, char tecla)
{
	avion->movimientoControlado(g, tecla);
}

void Controller::evaluarColisiones()
{
	for (int i = 0; i < enemigos.size(); i++)
	{
		if (avion->intersect(enemigos[i]->getRectangle())) {
			enemigos.erase(enemigos.begin() + i);
			this->puntos += 7;
			avion->disminuirVida();
			return;
		}
	}
	for (int i = 0; i < balas.size(); i++)
	{
		for (int j = 0; j < enemigos.size(); j++)
		{
			if (balas[i]->intersect(enemigos[j]->getRectangle())) {
				balas.erase(balas.begin() + i);
				enemigos.erase(enemigos.begin() + j);
				this->puntos += 7;
				return;
			}
		}
	}
}

void Controller::agregarBala(int widthBala, int heightbala)
{
	balas.push_back(new Bala(avion->getRectangle()->X, avion->getRectangle()->Y, widthBala, heightbala));
}

void Controller::agregarEnemigo(int widthEnemigo, int heightEnemigo)
{
	enemigos.push_back(new Enemigo(500, 320, widthEnemigo, heightEnemigo));
}

int Controller::getVidasAvion()
{
	return this->avion->getVidas();
}

int Controller::getPuntos()
{
	return this->puntos;
}
