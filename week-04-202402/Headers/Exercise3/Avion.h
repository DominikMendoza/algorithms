#pragma once
#include "Ala.h"
#include "Empenaje.h"
#include "Fuselaje.h"
#include "TrenAterrizaje.h"

class Avion
{
private:
    float x;
    float y;
    float dy;
    float dx;
    float velocidad;
    int color;
    int alto;
    int ancho;
    TrenAterrizaje** trenes;
    Ala** alas;
    Fuselaje* fuselaje;
    Empenaje* empenaje;
    int numTrenes;
    int numAlas;
    int pasoActual;
    int numPasos;
    bool haLlegadoFinal;

public:
    Avion(float x, float y, int color);
    ~Avion();
    void Borrar();
    void Mover();
    void Dibujar();
    bool LlegoFinal();
    bool EstaEstacionado();
};

Avion::Avion(float x, float y, int color)
{
    this->x = x;
    this->y = y;
    this->color = color;
    numPasos = 5;
    ancho = 9;
    alto = 2;
    velocidad = RandFloat(0.1, 1);
    numTrenes = 2;
    numAlas = 2;
    empenaje = new Empenaje(x + 3, y);
    alas = new Ala * [numAlas];
    alas[0] = new Ala(x, y + 1);
    alas[1] = new Ala(x + 6, y + 1);
    trenes = new TrenAterrizaje * [numTrenes];
    trenes[0] = new TrenAterrizaje(x + 3, y + 1);
    trenes[1] = new TrenAterrizaje(x + 5, y + 1);
    fuselaje = new Fuselaje(x + 4, y + 1);
    pasoActual = 0;
    dy = 1;
    dx = 1;
    haLlegadoFinal = false;
}

Avion::~Avion()
{
    delete fuselaje;
    delete empenaje;
    for (int i = 0; i < numAlas; i++)
    {
        delete alas[i];
    }
    delete[] alas;
    for (int i = 0; i < numTrenes; i++)
    {
        delete trenes[i];
    }
    delete[] trenes;
}

void Avion::Borrar()
{
    empenaje->BorrarEmpenaje();
    fuselaje->BorrarFuselaje();
    for (int i = 0; i < numAlas; i++)
    {
        alas[i]->BorrarAla();
    }
    for (int i = 0; i < numTrenes; i++)
    {
        trenes[i]->BorrarTren();
    }
}

void Avion::Mover()
{
    y += dy * velocidad;
    x += dx;
    // Verificar si se sale del ancho de la consola
    if (x < 0) {
        x = 0;
        dx *= -1;  
    }
    else if (x + ancho > ANCHO_CONSOLA) {
        x = ANCHO_CONSOLA - ancho;
        dx *= -1;  
    }
    empenaje->MoverEmpenaje(velocidad, dx);
    fuselaje->MoverFuselaje(velocidad, dx);
    for (int i = 0; i < numAlas; i++)
    {
        alas[i]->MoverAla(velocidad, dx);
    }
    for (int i = 0; i < numTrenes; i++)
    {
        trenes[i]->MoverTren(velocidad, dx);
    }
    pasoActual += 1;
    if (pasoActual == numPasos)
    {
        dx *= -1;
        pasoActual = 0;
    }
}

void Avion::Dibujar()
{
    Console::ForegroundColor = ConsoleColor(color);
    empenaje->DibujarEmpenaje();
    fuselaje->DibujarFuselaje();
    for (int i = 0; i < numAlas; i++)
    {
        alas[i]->DibujarAla();
    }
    for (int i = 0; i < numTrenes; i++)
    {
        trenes[i]->DibujarTren();
    }
    Console::ResetColor();
}

bool Avion::EstaEstacionado()
{
    return haLlegadoFinal;
}

bool Avion::LlegoFinal()
{
    if (y + alto >= ALTO_CONSOLA)
    {
        haLlegadoFinal = true;
        return true;
    }
    return false;
}