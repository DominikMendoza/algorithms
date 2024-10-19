#pragma once
#include "Circulo.h"
#include "Cuadrado.h"
#include "Triangulo.h"

using namespace System::Drawing;

class Controladora
{
private:
    Circulo* circulo;
    Cuadrado* cuadrado;
    Triangulo* triangulo;
    int carreras;
    int ranking[3];

public:
    Controladora();
    ~Controladora();
    void moverTodos(Graphics^ g);
    void dibujarTodos(Graphics^ g);
    bool comprobarGanador();
    void mostrarRanking();
    void reiniciarFiguras();

    int getCarreras() { return carreras; }
};

