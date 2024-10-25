#pragma once
#include "Figura.h"
class Elipse : public Figura
{
private:
	int ejemayor;
	int ejemenor;
public:
	Elipse();
	~Elipse();
	void dibujar(Graphics^ g) override;
	void mover(Graphics^ g) override;
};

