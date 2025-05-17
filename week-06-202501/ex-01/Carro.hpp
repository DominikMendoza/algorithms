#pragma once
#include "Terrestre.hpp"
class Carro : public Terrestre
{
public:
	Carro(int x, int y);
	~Carro();
	void dibujar() override;
	void chocarPersona(Persona* per) override;
private:

};

Carro::Carro(int x, int y) : Terrestre(x, y)
{
	this->velocidadConstante = false;
	this->ancho = 8;
	this->alto = 3;
}

Carro::~Carro()
{
}

void Carro::dibujar()
{
	Console::SetCursorPosition(x, y);
	cout << "____|~\\";
	Console::SetCursorPosition(x, y + 1);
	cout << "[| _ | -";
	Console::SetCursorPosition(x, y + 2);
	cout << "(_)(_)";
}

void Carro::chocarPersona(Persona* per)
{
	per->setVidas(0);
}
