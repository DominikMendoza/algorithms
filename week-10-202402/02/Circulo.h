#pragma once
#include "Figura.h"

class Circulo : public Figura
{
private:
	int diametro;
public:
	Circulo(int x, int y);
	~Circulo();
	void dibujar(Graphics^ g) override;
	void mover(Graphics^ g) override;

	int getDiametro() { return diametro; }
};
