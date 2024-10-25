#include "Cuadrado.h"

Cuadrado::Cuadrado() : Figura(), lado(rand() % 50 + 20) {}

Cuadrado::~Cuadrado() {}

void Cuadrado::dibujar(Graphics^ g)
{
	cli::array<Point>^ points = {
		Point(x,y),
		Point(x + lado, y),
		Point(x + lado, y + lado),
		Point(x, y + lado)
	};

	SolidBrush^ pen = gcnew SolidBrush(Color::FromArgb(rval, gval, bval));
	g->FillPolygon(pen, points);
}

void Cuadrado::mover(Graphics^ g)
{
	if (x + dx < 0 || x + dx + lado > g->VisibleClipBounds.Width) {
		dx *= -1;
	}
	if (y + dy < 0 || y + dy + lado > g->VisibleClipBounds.Height) {
		dy *= -1;
	}
	x += dx;
	y += dy;
}