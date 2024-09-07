#pragma once
#include "Utilidades.h"

class Empenaje
{
private:
    float x;
    float y;
    float dy;
    int ancho;
    string forma;

public:
    Empenaje(float x, float y);
    void BorrarEmpenaje();
    void MoverEmpenaje(float velocidad, float dx);
    void DibujarEmpenaje();
};

Empenaje::Empenaje(float x, float y)
{
    this->x = x;
    this->y = y;
    ancho = 3;
    forma = "_|_";
    dy = 1;
}

void Empenaje::BorrarEmpenaje()
{
    Cursor(x, y); cout << "   ";
}

void Empenaje::MoverEmpenaje(float velocidad, float dx)
{
    y += dy * velocidad;
    x += dx;
}

void Empenaje::DibujarEmpenaje()
{
    Cursor(x, y); cout << forma;
}