#pragma once
#include "Figuras.h"

//EQUILATERO
//ESCALENO
//Isosceles
class CTriangulo : public CFigura
{
private:
    int ancho, alto;
    double lado;

public:
    CTriangulo(int _x, int _y, int _dx, int _dy, int _color, bool _Visible, double _lado);  // Only declare here
    ~CTriangulo();                              // Only declare here

    void Borrar(Graphics^ G)override;
    void Mover(Graphics^ G) override;
    void Dibujar(Graphics^ G) override;
    //Espacio-------------
    double getLado();
    //Espacio-------------
    void setVisible(bool);
    bool isVisible();


    Rectangle getRectangle();
};


