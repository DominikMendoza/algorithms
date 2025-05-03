#pragma once
#include "ArrOvni.hpp"
#include "OAlfa.hpp"
#include "OBeta.hpp"
#include "OGamma.hpp"

class Invasion
{
private:
	ArrOvni* naves;
	int ovnisAlfa;
	int ovnisBeta;
public:
	Invasion();
	~Invasion();
	void animarNaves();
	void agregarNaveAlfa();
	void agregarNaveBeta();
	void agregarNaveGamma();
	void imprimirCantidadDeNaves();
	bool terminoInvasion();
};

Invasion::Invasion()
{
	this->naves = new ArrOvni();
	ovnisAlfa = 0;
	ovnisBeta = 0;
}

Invasion::~Invasion()
{
}

void Invasion::animarNaves()
{
	for (int i = 0; i < naves->size(); i++)
	{
		naves->getElemento(i)->animar();
	}
}

void Invasion::agregarNaveAlfa()
{
	naves->agregarElemento(new OAlfa(rand() % (26)));
	ovnisAlfa++;
	if (ovnisAlfa >= 2) {
		agregarNaveBeta();
		ovnisAlfa = 0;
	}
}

void Invasion::agregarNaveBeta()
{
	naves->agregarElemento(new OBeta(rand() % (52 - 26 + 1) + 26));
	ovnisBeta++;
	if (ovnisBeta >= 2) {
		agregarNaveGamma();
		ovnisBeta = 0;
	}
}

void Invasion::agregarNaveGamma()
{
	naves->agregarElemento(new OGamma(rand() % (75 - 52 + 1) + 52));
}

void Invasion::imprimirCantidadDeNaves()
{
	Console::SetCursorPosition(WIDTH - 3, 0);
	cout << "   ";
	Console::SetCursorPosition(WIDTH - 3, 0);
	cout << naves->size();
}

bool Invasion::terminoInvasion()
{
	return (naves->size() >= 20);
}
