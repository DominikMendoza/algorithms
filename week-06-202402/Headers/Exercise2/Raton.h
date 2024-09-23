#pragma once
#include "Entidad.h"

class Raton : public Entidad
{
private:
	int color;
	bool visible;

public:
	Raton();
	void MoverRaton(float gatoX, float gatoY);
	void Dibujar() override;
	bool getVisible();
	void setVisible(bool visible);
};

int pos[2] = { 1,-1 };

Raton::Raton() : Entidad(8, 1)
{
	x = RandInt(0, ANCHO_CONSOLA - 9);
	y = RandInt(1, 30);
	dx = pos[rand() % 2];
	dy = pos[rand() % 2];
	velocidad = RandFloat(0.1, 1);
	color = 7;
	visible = false;
}

void Raton::MoverRaton(float gatoX, float gatoY)
{
	float distanciaX = x - gatoX;
	float distanciaY = y - gatoY;
	float distancia = sqrt(distanciaX * distanciaX + distanciaY * distanciaY);
	if (distancia < 10)
	{
		if (distanciaX < 0)
		{
			dx = -fabs(dx);
		}
		else
		{
			dx = fabs(dx);
		}

		if (distanciaY < 0)
		{
			dy = -fabs(dy);
		}
		else
		{
			dy = fabs(dy);
		}
	}

	if (x < 1 || x > ANCHO_CONSOLA - ancho)
	{
		dx *= -1;
	}
	if (y < 1 || y > ALTO_CONSOLA - 10 - alto)
	{
		dy *= -1;
	}
	x += dx * velocidad;
	y += dy * velocidad;
}

void Raton::Dibujar()
{
	if (visible)
	{
		Console::SetCursorPosition(x, y);
		cout << "--(_c'>";
	}
}

bool Raton::getVisible()
{
	return visible;
}

void Raton::setVisible(bool visible)
{
	this->visible = visible;
}