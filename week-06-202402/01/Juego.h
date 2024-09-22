#pragma once
#include "Bicicleta.h"
#include "Bus.h"
#include "Carro.h"
#include "Terrestre.h"
#include "Persona.h"
#include "vector"
class Juego
{
public:
	Juego();
	~Juego();
	void jugar();
private:
	vector<Terrestre*> listaTerrestre;
	Persona* personaje;
	bool detectarColision();
};
