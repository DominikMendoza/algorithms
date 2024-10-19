#include "Triangulo.h"

Triangulo::Triangulo(int x, int y) : Figura(x,y), lado(50) {}

Triangulo::~Triangulo() {}

void Triangulo::dibujar(Graphics^ g)
{
    cli::array<Point>^ points = {
        Point(x + lado / 2, y),
        Point(x, y + lado),
        Point(x + lado, y + lado)
    };

    SolidBrush^ pen = gcnew SolidBrush(Color::Blue);
    g->FillPolygon(pen, points);
}


void Triangulo::mover(Graphics^ g)
{
    if (x + dx < 0 || x + dx + lado > g->VisibleClipBounds.Width) {
        dx *= -1;
    }
    x += dx * velocidad;
}
