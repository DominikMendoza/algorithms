#pragma once
#include <vector>
#include "COAlfa.hpp"
#include "COBeta.hpp"
#include "COGamma.hpp"

class CControladora
{
private:
	vector<COvni*> ovnis;
	int cntAlfa, cntBeta, cntNumeroMaximo;
public:
	CControladora();
	~CControladora();
	void agregarOvniAlfa();
	void agregarOvniBeta();
	void agregarOvniGamma();
	void animarOvnis();
	bool llegoInvasion();
	void imprimirMensajeFinal();
	void imprimirNumeroNaves();
};

CControladora::CControladora()
{
	Console::SetWindowSize(WIDTH, HEIGHT);
	Console::CursorVisible = false;
	srand(time(nullptr));
	this->cntAlfa = 0;
	this->cntBeta = 0;
	this->cntNumeroMaximo = 0;
}

CControladora::~CControladora()
{
	ovnis.clear();
}

void CControladora::agregarOvniAlfa()
{
	cntNumeroMaximo++;
	ovnis.push_back(new COAlfa(rand() % (WIDTH - 20), 0));
	cntAlfa++;
	if (cntAlfa == 2) {
		agregarOvniBeta();
		cntAlfa = 0;
	}
}

void CControladora::agregarOvniBeta()
{
	cntNumeroMaximo++;
	ovnis.push_back(new COBeta(rand() % (WIDTH - 20), 0));
	cntBeta++;
	if (cntBeta == 2) {
		agregarOvniGamma();
		cntBeta = 0;
	}
}

void CControladora::agregarOvniGamma()
{
	cntNumeroMaximo++;
	ovnis.push_back(new COGamma(rand() % (WIDTH - 20), 0));
}

void CControladora::animarOvnis()
{
	for (int i = 0; i < ovnis.size(); i++)
	{
		if (!ovnis[i]->isVisible()) {
			ovnis[i]->borrar();
			ovnis.erase(ovnis.begin() + i);
			i--;
			continue;
		}
		ovnis[i]->animar();
	}
}

bool CControladora::llegoInvasion()
{
	//return ovnis.size() >= 20;
	return cntNumeroMaximo >= 20;
}

void CControladora::imprimirMensajeFinal()
{
	Console::Clear();
	Console::SetCursorPosition(WIDTH / 2, HEIGHT / 2);
	Console::ForegroundColor = ConsoleColor::Red;
	cout << "NOS HAN INVADIDO, YA VOLAMOS!";
}

void CControladora::imprimirNumeroNaves()
{
	Console::SetCursorPosition(WIDTH - 3, 0);
	cout << "    ";
	Console::SetCursorPosition(WIDTH - 3, 0);
	Console::ForegroundColor = ConsoleColor::Blue;
	//cout << ovnis.size();
	cout << cntNumeroMaximo;
}
