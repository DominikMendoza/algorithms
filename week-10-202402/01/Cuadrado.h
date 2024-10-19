#pragma once
#include "Figura.h"
class Cuadrado : public Figura
{
private:
	int lado;
public:
	Cuadrado();
	~Cuadrado();
	void dibujar(Graphics^ g) override;
	void mover(Graphics^ g) override;
};