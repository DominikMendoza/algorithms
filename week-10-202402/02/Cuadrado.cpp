#include "Cuadrado.h"

Cuadrado::Cuadrado(int x, int y) : Figura(x,y), lado(50) {}

Cuadrado::~Cuadrado() {}

void Cuadrado::dibujar(Graphics^ g)
{
	cli::array<Point>^ points = {
		Point(x,y),
		Point(x + lado, y),
		Point(x + lado, y + lado),
		Point(x, y + lado)
	};

	SolidBrush^ pen = gcnew SolidBrush(Color::Red);
	g->FillPolygon(pen, points);
}

void Cuadrado::mover(Graphics^ g)
{
	if (x + dx < 0 || x + dx + lado > g->VisibleClipBounds.Width) {
		dx *= -1;
	}
	x += dx * velocidad;
}