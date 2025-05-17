#pragma once
#include "Terrestre.hpp"
class Moto : public Terrestre
{
public:
	Moto(int x, int y);
	~Moto();
	void dibujar() override;
	void chocarPersona(Persona* per) override;

private:

};

Moto::Moto(int x, int y) : Terrestre(x, y)
{
	this->velocidadConstante = true;
	this->ancho = 6;
	this->alto = 2;
	this->dx = 2;
}

Moto::~Moto()
{
}

void Moto::dibujar()
{
	if (dx > 0) {
		Console::SetCursorPosition(x, y);
		cout << ".._\\";
		Console::SetCursorPosition(x, y + 1);
		cout << "(o)(o)";
	}
	else {
		Console::SetCursorPosition(x, y);
		cout << "/_..";
		Console::SetCursorPosition(x, y + 1);
		cout << "(o)(o)";
	}
}

void Moto::chocarPersona(Persona* per)
{
	per->setVidas(per->getVidas() - 1);
}
