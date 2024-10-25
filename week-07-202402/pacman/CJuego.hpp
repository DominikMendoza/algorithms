#pragma once
#include <vector>
#include "CFantasma.hpp"
#include "CPacman.hpp"
#include "CPastilla.hpp"

class CJuego
{
private:
	CPacman* pac;
	vector<CFantasma*> fantasmas;
	vector<CPastilla*> pastillas;
	bool juegoTermino;
public:
	CJuego();
	~CJuego();
	void iniciarJuego();
	bool juegoTerminado();
	bool pacmanGano();
};

CJuego::CJuego()
{
	Console::SetWindowSize(WIDTH, HEIGHT);
	Console::CursorVisible = false;
	srand(time(nullptr));
	juegoTermino = false;
	pac = new CPacman(WIDTH / 2 - 2, HEIGHT - 8);
	for (int i = 0; i < 4; i++)
	{
		fantasmas.push_back(new CFantasma(rand() % (WIDTH - 9), rand() % (HEIGHT - 8)));
	}
	for (int i = 0; i < 4; i++)
	{
		pastillas.push_back(new CPastilla(rand() % (WIDTH - 4), rand() % (HEIGHT - 4)));
	}
}

CJuego::~CJuego()
{
	delete pac;
	for (int i = 0; i < fantasmas.size(); i++)
	{
		delete fantasmas[i];
	}
	fantasmas.clear();
	for (int i = 0; i < pastillas.size(); i++)
	{
		delete pastillas[i];
	}
	pastillas.clear();
}

void CJuego::iniciarJuego()
{


	pac->animar();
	for (int i = 0; i < fantasmas.size(); i++)
	{
		fantasmas[i]->borrar();
		if (fantasmas[i]->instersectar(pac)) {
			this->juegoTermino = true;
		}
		fantasmas[i]->mover();
		fantasmas[i]->dibujar();
	}
	for (int i = 0; i < pastillas.size(); i++)
	{
		pastillas[i]->borrar();
		if (pastillas[i]->instersectar(pac)) {
			pastillas.erase(pastillas.begin() + i);
			i--;
			continue;
		}
		pastillas[i]->mover();
		pastillas[i]->dibujar();
	}
	if (pastillas.size() == 0) {
		this->juegoTermino = true;
	}
}

bool CJuego::juegoTerminado()
{
	return this->juegoTermino;
}

bool CJuego::pacmanGano()
{
	return (pastillas.size() == 0);
}
