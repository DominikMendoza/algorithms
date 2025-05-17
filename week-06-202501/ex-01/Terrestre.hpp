#pragma once
#include "Persona.hpp"
class Terrestre : public Movil
{
protected:
	bool velocidadConstante;
public:
	Terrestre(int x, int y);
	~Terrestre();
	virtual void chocarPersona(Persona* per) = 0;
	void mover() override;
};

Terrestre::Terrestre(int x, int y) : Movil(x, y)
{
	this->velocidadConstante = true;
	this->dx = 2;
}

Terrestre::~Terrestre()
{
}

void Terrestre::mover()
{
	if (!velocidadConstante) {
		int incremento = rand() % 3 + 1;
		if (dx > 0) {
			dx = incremento * 1;
		}
		else {
			dx = incremento * -1;
		}
	}

	if (x + dx < 0 || x + dx + ancho >= WIDTH) {
		dx *= -1;
	}
	x += dx;
	y += dy;
}
