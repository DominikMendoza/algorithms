#pragma once
#include "Figuras.h"

class CRectangulo : public CFigura
{
private:
    //int ancho, alto;
    double base, altura;
public:
    CRectangulo(int _x, int _y, double _base, double _altura);  // Only declare here
    ~CRectangulo();                              // Only declare here

    void Dibujar(Graphics^ G) override;
    Rectangle getRectangle();
};


