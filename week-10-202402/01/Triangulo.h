#pragma once
#include "Figura.h"
class Triangulo : public Figura
{
public:
	Triangulo();
	~Triangulo();
	void dibujar(Graphics^ g) override;
	void mover(Graphics^ g) override;
private:
	int lado;
};
