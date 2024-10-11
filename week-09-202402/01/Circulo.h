#pragma once
#include "Figuras.h"

class CCirculo : public CFigura
{
private:
    int ancho, alto;
    double radio;
public:
    CCirculo(int _x, int _y, double _radio);  // Only declare here
    ~CCirculo();                              // Only declare here

    void Dibujar(Graphics^ G) override;
    Rectangle getRectangle();
};


