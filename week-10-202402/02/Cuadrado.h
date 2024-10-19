#pragma once
#include "Figura.h"
class Cuadrado : public Figura
{
private:
	int lado;
public:
	Cuadrado(int x, int y);
	~Cuadrado();
	void dibujar(Graphics^ g) override;
	void mover(Graphics^ g) override;

	int getLado() { return lado; }
};