#pragma once
#include "Personaje.hpp"
#include "Disco.hpp"
#include "FileManager.hpp"
#include <sstream>
#include <vector>

class Controller
{
private:
	Personaje* per;
	FileManager* fm;
	vector<Disco*> discos;
public:
	Controller(Bitmap^ bmpPer, Bitmap^ discoRojo, Bitmap^ discoAzul, Bitmap^ Gris);
	void verificarColisiones(Bitmap^ discoGris);
	void moverPersonaje(Graphics^ g, char tecla);
	void moverDiscos(Graphics^ g);
	void dibujarTodo(Graphics^ g, Bitmap^ bmpPer, Bitmap^ discoRojo, Bitmap^ discoAzul, Bitmap^ Gris);
	~Controller();
};

Controller::Controller(Bitmap^ bmpPer, Bitmap^ discoRojo, Bitmap^ discoAzul, Bitmap^ Gris)
{
	fm = new FileManager();
	string resultado = fm->leerDeTxt("configuracion.txt");
	if (resultado.empty()) {
		// manejar cuando no se puede leer;
		fm->guardarEnTxt("configuracion.txt", "X = 150\nY = 200\nN= 10\nT= 20");
	}
	resultado = fm->leerDeTxt("configuracion.txt");
	stringstream ss = stringstream(resultado);
	int x, y, vidas;
	char aux;

	ss >> aux >> aux >> x;
	ss >> aux >> aux >> y;
	ss >> aux >> aux >> vidas;

	per = new Personaje(x, y, bmpPer->Width / 4, bmpPer->Height / 4, vidas);

	for (int i = 0; i < 4; i++)
	{
		x = rand() % 500;
		y = rand() % 300;
		if (i % 2 == 0) {
			discos.push_back(new Disco(x, y, discoRojo->Width / 4, discoRojo->Height / 4, 8, 0));
		}
		else {
			discos.push_back(new Disco(x, y, discoAzul->Width / 4, discoAzul->Height / 4, 0, 8));
		}
	}
}

void Controller::verificarColisiones(Bitmap^ discoGris)
{
	for (int i = 0; i < discos.size(); i++)
	{
		if (discos[i]->estaColisionandoCon(per)) {
			per->disminuirVidas(discos[i]->isLetal());
		};
	}
	int x = rand() % 500;
	int y = rand() % 300;
	for (int i = 0; i < discos.size() - 1; i++)
	{
		for (int j = i + 1; j < discos.size(); j++)
		{
			if (discos[i]->estaColisionandoCon(discos[j])) {
				if (discos[i]->getType() + discos[j]->getType() == 3) {
					discos.push_back(new Disco(x, y, discoGris->Width / 4, discoGris->Height / 4, 8, 8));
					return;
				}
			}
		}
	}
}

void Controller::moverPersonaje(Graphics^ g, char tecla)
{
	per->mover(g, tecla);
}

void Controller::moverDiscos(Graphics^ g)
{
	for (int i = 0; i < discos.size(); i++)
	{
		discos[i]->mover(g, 'x');
	}
}

void Controller::dibujarTodo(Graphics^ g, Bitmap^ bmpPer, Bitmap^ discoRojo, Bitmap^ discoAzul, Bitmap^ Gris)
{
	per->dibujar(g, bmpPer);
	for (int i = 0; i < discos.size(); i++)
	{
		discos[i]->dibujar(g, discoRojo);
	}
}

Controller::~Controller()
{
}