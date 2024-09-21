#pragma once
#include "Entidad.h"
class Raton : public Entidad
{
public:
	Raton();
	void borrar() override;
	void mover() override;
	void mover(int gatoX, int gatoY);
	void dibujar() override;
	bool getVisible() { return visible; }
	void setVisible(bool visible) { this->visible = visible; }
private:
	float dx, dy, velocidad;
	bool visible;
};
