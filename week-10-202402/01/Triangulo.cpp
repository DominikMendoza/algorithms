#include "Triangulo.h"

Triangulo::Triangulo() : Figura(), lado(rand() % 50 + 10) {}

Triangulo::~Triangulo() {}

void Triangulo::dibujar(Graphics^ g)
{
    cli::array<Point>^ points = {
        Point(x + lado / 2, y),
        Point(x, y + lado),
        Point(x + lado, y + lado)
    };

    SolidBrush^ pen = gcnew SolidBrush(Color::FromArgb(rval, gval, bval));
    g->FillPolygon(pen, points);
}


void Triangulo::mover(Graphics^ g)
{
    if (x + dx < 0 || x + dx+ lado > g->VisibleClipBounds.Width) {
        dx *= -1;
    }
    if (y + dy < 0 || y + dy + lado > g->VisibleClipBounds.Height) {
        dy *= -1;
    }
    x += dx;
    y += dy;
}
