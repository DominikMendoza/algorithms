#pragma once
#include "conio.h"
#include "Avion.h"

class Controladora
{
private:
    Avion** aviones;
    int numAviones;
    float posicionesOcupadas[5][2];
    bool PosicionOcupada(float x, float y);

public:
    Controladora();
    ~Controladora();
    void Iniciar();
};

bool Controladora::PosicionOcupada(float x, float y)
{
    for (int i = 0; i < numAviones; i++)
    {
        float xExistente = posicionesOcupadas[i][0];
        float yExistente = posicionesOcupadas[i][1];
        // Verificar si las áreas de los aviones se superponen
        if (x < xExistente + 9 && x + 9 > xExistente && y < yExistente + 2 && y + 2 > yExistente)  
        {
            return true;
        }
    }
    return false;
}

Controladora::Controladora()
{
    numAviones = RandInt(2, 5);
    aviones = new Avion * [numAviones];
    for (int i = 0; i < numAviones; i++)
    {
        float x, y;
        int color;
        do
        {
            x = static_cast<float>(RandInt(0, ANCHO_CONSOLA - 10));
            y = 0;
        } while (PosicionOcupada(x, y));
        posicionesOcupadas[i][0] = x;
        posicionesOcupadas[i][1] = y;
        color = RandInt(1, 15);
        aviones[i] = new Avion(x, y, color);
    }
}

Controladora::~Controladora()
{
    for (int i = 0; i < numAviones; i++)
    {
        delete aviones[i];
    }
    delete[] aviones;
}

void Controladora::Iniciar()
{
    while (true)
    {
        bool todosaterrizaron = true;
        for (int i = 0; i < numAviones; i++)
        {
            if (!aviones[i]->EstaEstacionado())
            {
                aviones[i]->Borrar();
                aviones[i]->Mover();
                aviones[i]->Dibujar();
                if (!aviones[i]->LlegoFinal())
                {
                    todosaterrizaron = false;
                }
            }
        }
        _sleep(100);
        if (todosaterrizaron)
        {
            string mensaje = "TODOS LOS AVIONES LLEGARON A ATERRIZAR!!";
            system("cls");
            Console::SetCursorPosition(ANCHO_CONSOLA / 2 - mensaje.size() / 2, ALTO_CONSOLA / 2);
            cout << mensaje;
            break;
        }
    }
}