#pragma once
#include "Utilidades.h"

class Ala
{
private:
    float x;
    float y;
    float dy;
    int ancho;
    char forma;

public:
    Ala(float x, float y);
    void BorrarAla();
    void MoverAla(float velocidad, float dx);
    void DibujarAla();
};

Ala::Ala(float x, float y)
{
    this->x = x;
    this->y = y;
    ancho = 3;
    forma = '-';
    dy = 1;
}

void Ala::BorrarAla()
{
    for (int i = 0; i < ancho; i++)
    {
        Cursor(x + i, y); cout << " ";
    }
}

void Ala::MoverAla(float velocidad, float dx)
{
    y += dy * velocidad;
    x += dx;
}

void Ala::DibujarAla()
{
    for (int i = 0; i < ancho; i++)
    {
        Cursor(x + i, y); cout << forma;
    }
}