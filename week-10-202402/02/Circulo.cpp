#include "Circulo.h"

Circulo::Circulo(int x, int y) : Figura(x,y), diametro(50) {}

Circulo::~Circulo() {}

void Circulo::dibujar(Graphics^ g)
{
    SolidBrush^ b = gcnew SolidBrush(Color::Black);
    g->FillEllipse(b, x, y, diametro, diametro);
}

void Circulo::mover(Graphics^ g)
{
    if (x + dx < 0 || x + dx + diametro > g->VisibleClipBounds.Width) {
        dx *= -1;
    }

    x += dx * velocidad;
}