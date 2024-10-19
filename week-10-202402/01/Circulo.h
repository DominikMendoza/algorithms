#pragma once
#include "Figura.h"

class Circulo : public Figura
{
private:
	int diametro;
public:
	Circulo();
	~Circulo();
	void dibujar(Graphics^ g) override;
	void mover(Graphics^ g) override;
};
