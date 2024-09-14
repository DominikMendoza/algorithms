#pragma once
#include "Avion.h"

class AvionTipo7 : public Avion
{
private:
	int color;
	int niveles;
	int espacios;
	float xmin;
	float ymin;
	float xmax;
	float ymax;

public:
	AvionTipo7();
	void Dibujar() override;
	void Mover() override;
};

AvionTipo7::AvionTipo7() : Avion(3, 14, 3)
{
	niveles = 8;
	dx = 1;
	color = 14;
	espacios = 10;
	xmin = 0;
	ymin = 0;
	xmax = ANCHO_CONSOLA - ancho;
	ymax = ALTO_CONSOLA - alto;
}

void AvionTipo7::Dibujar()
{
	Console::ForegroundColor = ConsoleColor(color);
	Console::SetCursorPosition(x, y);
	cout << "        |";
	Console::SetCursorPosition(x, y + 1);
	cout << "    ---=O=---";
	Console::SetCursorPosition(x, y + 2);
	cout << "       / \\";
	Console::ResetColor();
}

void AvionTipo7::Mover()
{
    x += dx * velocidad;
    y += dy * velocidad;
    if (x >= xmax && dx == 1)
	{  
        dx = 0;
        dy = 1;  
    }
    else if (y >= ymax && dy == 1) 
	{  
        dx = -1;
        dy = 0;  
    }
    else if (x <= xmin && dx == -1)
	{ 
        dx = 0;
        dy = -1;  
    }
    else if (y <= ymin && dy == -1)
	{ 
        dx = 1;
        dy = 0;  
        xmin += espacios;
        ymin += espacios;
        xmax -= espacios;
        ymax -= espacios;
        niveles--;  
        if (niveles <= 0) 
		{
            movimiento = false;
        }
    }
}