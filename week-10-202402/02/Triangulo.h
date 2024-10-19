#pragma once
#include "Figura.h"
class Triangulo : public Figura
{
public:
	Triangulo(int x, int y);
	~Triangulo();
	void dibujar(Graphics^ g) override;
	void mover(Graphics^ g) override;

	int getLado() { return lado; }
private:
	int lado;
};
