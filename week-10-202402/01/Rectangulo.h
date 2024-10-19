#pragma once
#include "Figura.h"
class Rectangulo : public Figura
{
private:
	int lado1;
	int lado2;
public:
	Rectangulo();
	~Rectangulo();
	void dibujar(Graphics^ g) override;
	void mover(Graphics^ g) override;
};
