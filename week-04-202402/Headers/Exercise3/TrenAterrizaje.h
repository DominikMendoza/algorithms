#pragma once
#include "Utilidades.h"

class TrenAterrizaje
{
private:
    float x;
    float y;
    float dy;
    char forma;

public:
    TrenAterrizaje(float x, float y);
    void BorrarTren();
    void MoverTren(float velocidad, float dx);
    void DibujarTren();
};

TrenAterrizaje::TrenAterrizaje(float x, float y)
{
    this->x = x;
    this->y = y;
    dy = 1;
    forma = 'o';
}

void TrenAterrizaje::BorrarTren()
{
    Cursor(x, y); cout << " ";
}

void TrenAterrizaje::MoverTren(float velocidad, float dx)
{
    y += dy * velocidad;
    x += dx;
}

void TrenAterrizaje::DibujarTren()
{
    Cursor(x, y); cout << forma;
}