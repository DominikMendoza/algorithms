#include "Rectangulo.h"

Rectangulo::Rectangulo() : Figura(), lado1(rand() % 50 + 50), lado2(rand() % 50) {}

Rectangulo::~Rectangulo() {}

void Rectangulo::dibujar(Graphics^ g)
{
	cli::array<Point>^ points = {
		Point(x,y),
		Point(x + lado1, y),
		Point(x + lado1, y + lado2),
		Point(x, y + lado2)
	};

	SolidBrush^ pen = gcnew SolidBrush(Color::FromArgb(rval, gval, bval));
	g->FillPolygon(pen, points);
}

void Rectangulo::mover(Graphics^ g)
{
	if (x + dx < 0 || x + dx + lado1 > g->VisibleClipBounds.Width) {
		dx *= -1;
	}
	if (y + dy < 0 || y + dy + lado2 > g->VisibleClipBounds.Height) {
		dy *= -1;
	}
	x += dx;
	y += dy;
}