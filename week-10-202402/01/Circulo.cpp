#include "Circulo.h"

Circulo::Circulo() : Figura(), diametro(rand() % 50 + 10) {}

Circulo::~Circulo() {}

void Circulo::dibujar(Graphics^ g)
{
    SolidBrush^ b = gcnew SolidBrush(Color::FromArgb(rval, gval, bval));
    g->FillEllipse(b, x, y, diametro, diametro);
}

void Circulo::mover(Graphics^ g)
{
    if (x + dx < 0 || x + dx + diametro > g->VisibleClipBounds.Width) {
        dx *= -1;
    }
    if (y + dy < 0 || y + dy + diametro > g->VisibleClipBounds.Height) {
        dy *= -1;
    }

    x += dx;
    y += dy;
}