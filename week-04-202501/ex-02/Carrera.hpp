#pragma once
#include <conio.h>
#include "ArrCarro.hpp"
class Carrera
{
private:
	ArrCarro* carros;
	bool inicioCarrera;
	bool terminoCarrera;
	int numeroCarroGanador;
public:
	Carrera();
	~Carrera();
	void play();
	void mostrarResultados();
	void iniciarCarrera();
	bool getTerminoCarrera();
};

Carrera::Carrera()
{
	inicioCarrera = false;
	terminoCarrera = false;
	numeroCarroGanador = -1;
	carros = new ArrCarro();
	for (int i = 0; i < 3; i++)
	{
		carros->agregarElemento(new Carro(0, i * 8 + 3));
	}
	carros->pintarElementos();
}

Carrera::~Carrera()
{
}

void Carrera::play()
{
	while (inicioCarrera && !terminoCarrera) {
		carros->animarElementos();
		if (carros->getPosicionGanadora() != -1) {
			numeroCarroGanador = carros->getPosicionGanadora();
			terminoCarrera = true;
		}
		_sleep(150);
	}
}

void Carrera::mostrarResultados()
{
	Console::SetCursorPosition(WIDTH / 2 - 15, HEIGHT / 2);
	cout << "El ganador fue: " << numeroCarroGanador + 1;
}

void Carrera::iniciarCarrera()
{
	while (true) {
		if (kbhit()) {
			char tecla = _getch();
			tecla = toupper(tecla);
			if (tecla == 'G') {
				this->inicioCarrera = true;
				break;
			}
		}
	}
}
