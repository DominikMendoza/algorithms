#pragma once
#include "Figuras.h"

class CCirculo : public CFigura
{
private:
    //int ancho, alto;
    double radio;
public:
    CCirculo(int _x, int _y, int _dx, int _dy, int _color, bool _Visible, double _radio);  // Only declare here
    ~CCirculo();                              // Only declare here

    void Borrar(Graphics^ G)override;
    void Mover(Graphics^ G) override;
    void Dibujar(Graphics^ G) override;
    //Espacio-------------
    double getDiametro();
    //Espacio-------------
    void setVisible(bool);
    bool isVisible();

    Rectangle getRectangle();
};


