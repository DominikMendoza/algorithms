#pragma once
#include "Figuras.h"

class CElipse : public CFigura
{
private:
    //int ancho, alto;
    double semiejeA, semiejeB;
public:
    CElipse(int _x, int _y, double _semiejeA, double _semiejeB);  // Only declare here
    ~CElipse();                              // Only declare here

    void Dibujar(Graphics^ G) override;
    Rectangle getRectangle();
};


