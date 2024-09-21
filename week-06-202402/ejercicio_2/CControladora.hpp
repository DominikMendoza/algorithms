#pragma once
#include "CGato.hpp"
#include "CRaton.hpp"
#include <vector>
#include <chrono>
#include <thread>

class CControladora
{
private:
	CGato* cat;
	vector<CRaton*> ratones;
	bool juegoTerminado;
	int nratonesInicial;
	int contador;
public:
	CControladora();
	~CControladora();
	void jugar();
	void contadorRatones();
	bool terminoJuego();
	void generarPausa(long long time);
};

CControladora::CControladora()
{
	srand(time(nullptr));
	Console::SetWindowSize(WIDTH, HEIGHT);
	Console::CursorVisible = false;

	juegoTerminado = false;
	contador = 0;
	cat = new CGato(WIDTH / 2, HEIGHT / 2);
	nratonesInicial = rand() % 9 + 7;
	for (int i = 0; i < nratonesInicial; i++)
	{
		ratones.push_back(new CRaton(rand() % WIDTH, rand() % HEIGHT));
	}
}

CControladora::~CControladora()
{
	delete cat;
	for (int i = 0; i < ratones.size(); i++)
	{
		delete ratones[i];
	}
	ratones.clear();
}

void CControladora::jugar()
{
	// cada 50 milisegundos
	contadorRatones();
	// Verificar colisiones
	for (int i = 0; i < ratones.size(); i++)
	{
		if (cat->intersectar(ratones[i])) {
			ratones[i]->borrar();
			ratones.erase(ratones.begin() + i);
			i--;
		}
	}

	if (ratones.size() <= nratonesInicial / 2) {
		this->juegoTerminado = true;
	}

	for (int i = 0; i < ratones.size(); i++)
	{
		ratones[i]->animar(cat);
	}
	cat->animar(nullptr);

	// cada 50 milisegundos
	// El contador tiene que llegar a 40 para que haya pasado 2 segundos
	contador++;
	if (contador >= 40) {
		contador = 0;
		if (ratones.size() < nratonesInicial) {
			ratones.push_back(new CRaton(rand() % WIDTH, rand() % HEIGHT));
		}
	}

}

void CControladora::contadorRatones()
{
	Console::SetCursorPosition(WIDTH - 4, 0);
	cout << "    ";
	Console::SetCursorPosition(WIDTH - 12, 0);
	cout << "RATONES: " << ratones.size();
}

bool CControladora::terminoJuego()
{
	return this->juegoTerminado;
}

void CControladora::generarPausa(long long time)
{
	this_thread::sleep_for(chrono::milliseconds(time));
}
