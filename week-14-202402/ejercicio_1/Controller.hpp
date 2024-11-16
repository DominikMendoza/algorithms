#pragma once
#include <vector>
#include "Disco.hpp"
#include "Personaje.hpp"
#include "FileManager.hpp"
class Controller
{
private:
	vector<Disco*> discos;
	Personaje* per;
	FileManager* file;
	int time;
public:
	Controller(Bitmap^ bmpDiscos);
	~Controller();
	void moverTodo(Graphics^ g);
	void dibujar(Graphics^ g, Bitmap^ bmpDiscos);
	void validarColisiones();
	Personaje* getPersonaje();
	void disminuirTime();
	int getTime();
};

Controller::Controller(Bitmap^ bmpDiscos)
{
	file = new FileManager();
	/* Construir personaje en base a txt */
	string resultado = file->readFile("configuracion.txt");
	char aux;
	int x, y, hp, t;

	stringstream ss(resultado);
	ss >> aux >> aux >> x;
	ss >> aux >> aux >> y;
	ss >> aux >> aux >> hp;
	ss >> aux >> aux >> this->time;

	per = new Personaje(x, y, 80, 80, hp);
	/*discos.push_back(new Disco(0, rand() % 300, rand() % 50 + 20, rand() % 50 + 20));
	discos.push_back(new Disco(300, rand() % 300, rand() % 50 + 20, rand() % 50 + 20));
	discos.push_back(new Disco(150, rand() % 300, rand() % 50 + 20, rand() % 50 + 20));*/
	
	for (int i = 0; i < 60; i++)
	{
		discos.push_back(new Disco(rand() % 300, rand() % 300, bmpDiscos->Width / 4, bmpDiscos->Height / 3));
	}
	
}

Controller::~Controller()
{
}

void Controller::moverTodo(Graphics^ g)
{
	for (int i = 0; i < discos.size(); i++)
	{
		discos[i]->mover(g);
	}
	//per->mover(g);
}

void Controller::dibujar(Graphics^ g, Bitmap^ bmpDiscos)
{
	for (int i = 0; i < discos.size(); i++)
	{
		discos[i]->dibujar(g, bmpDiscos);
	}
	per->dibujar(g);
}

void Controller::validarColisiones()
{
	for (int i = 0; i < discos.size(); i++)
	{
		if (discos[i]->getType() == 3) continue;
		for (int j = 0; j < discos.size(); j++)
		{
			if (i == j || discos[j]->getType() == 3) continue;
			if (discos[i]->intersect(discos[j]->getRectangle())) {
				discos[j]->transformar();
				discos.erase(discos.begin() + i);
				break;
			}
		}
	}

	for (int i = 0; i < discos.size(); i++)
	{
		if (per->intersect(discos[i]->getRectangle())) {
			discos.erase(discos.begin() + i);
			per->disminuirVida();
			per->resetearCoordenadas();
			i--;
		}
	}
}

Personaje* Controller::getPersonaje()
{
	return this->per;
}

void Controller::disminuirTime()
{
	this->time--;
}

int Controller::getTime()
{
	return this->time;
}
