#pragma once
#include "Utilidades.h"

class Fuselaje
{
private:
    float x;
    float y;
    float dy;
    char forma;

public:
    Fuselaje(float x, float y);
    void BorrarFuselaje();
    void MoverFuselaje(float velocidad, float dx);
    void DibujarFuselaje();
};

Fuselaje::Fuselaje(float x, float y)
{
    this->x = x;
    this->y = y;
    dy = 1;
    forma = '0';
}

void Fuselaje::BorrarFuselaje()
{
    Cursor(x, y); cout << " ";
}

void Fuselaje::MoverFuselaje(float velocidad, float dx)
{
    y += dy * velocidad;
    x += dx;
}

void Fuselaje::DibujarFuselaje()
{
    Cursor(x, y); cout << forma;
}