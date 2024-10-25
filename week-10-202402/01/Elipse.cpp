#include "Elipse.h"

Elipse::Elipse() : Figura(), ejemayor(rand() % 20 + 50), ejemenor(rand() % 20 + 5) {}

Elipse::~Elipse() {}

void Elipse::dibujar(Graphics^ g)
{
    SolidBrush^ b = gcnew SolidBrush(Color::FromArgb(rval, gval, bval));
    g->FillEllipse(b, x, y, ejemayor, ejemenor);
}

void Elipse::mover(Graphics^ g)
{
    if (x + dx < 0 || x + dx + ejemayor > g->VisibleClipBounds.Width) {
        dx *= -1;
    }
    if (y + dy < 0 || y + dy + ejemenor > g->VisibleClipBounds.Height) {
        dy *= -1;
    }

    x += dx;
    y += dy;
}