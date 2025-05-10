#pragma once
#include "Raton.hpp"
#include "Gato.hpp"
#include <vector>

class Controladora
{
private:
	Gato* gato;
	vector<Raton*> ratones;

	float distanciaMinima;
public:
	Controladora();
	~Controladora();
	void jugar();
};

Controladora::Controladora()
{
	distanciaMinima = 12;
	gato = new Gato(WIDTH / 2, HEIGHT / 2);
	for (int i = 0; i < 5; i++)
	{
		ratones.push_back(new Raton(rand() % (WIDTH - 7), rand() % HEIGHT));
	}
}

Controladora::~Controladora()
{
}

void Controladora::jugar()
{
	while (true)
	{
		gato->animar();
		for (int i = 0; i < ratones.size(); i++)
		{
			Raton* raton = ratones[i];
			raton->borrar();
			raton->moverControlado(gato->getX(), gato->getY(), distanciaMinima);
			raton->dibujar();
			if (raton->intersectar(gato)) {
				raton->borrar();
				ratones.erase(ratones.begin() + i);
				i--;
				// raton->setVisible(false);
			}
		}

		
		_sleep(120);
	}
}
