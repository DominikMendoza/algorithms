#pragma once
#include "Terrestre.h"
class Carro : public Terrestre
{
public:
	Carro(float x, float y);
	void borrar() override;
	void mover() override;
	void dibujar() override;
	void cambiarVelocidad(float cantidad) override;
};
