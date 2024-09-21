#pragma once
#include "Terrestre.h"
class Bus : public Terrestre
{
public:
	Bus(float x, float y);
	void borrar() override;
	void mover() override;
	void dibujar() override;
	void cambiarVelocidad(float cantidad) override;
};

