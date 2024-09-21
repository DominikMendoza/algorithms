#pragma once
#include "Entidad.h"
#include "Raton.h"
#include "Gato.h"
#include "vector"
#include "chrono"
class Juego
{
public:
	Juego();
	~Juego();
	void play();
private:
	Gato* gato;
	vector<Raton*> listaRatones;
	int cantidad_ratones;
	chrono::steady_clock::time_point tiempoAnterior;
	bool detectarColision();
	void visibleRaton();
};
