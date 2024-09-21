#pragma once
#include "Entidad.h"
#include "conio.h"
class Gato : public Entidad
{
public:
	Gato(float x, float y);
	void borrar() override;
	void mover() override;
	void dibujar() override;
};
