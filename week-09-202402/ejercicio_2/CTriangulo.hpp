#pragma once
#include "CFigura.hpp"
class CTriangulo : public CFigura
{
private:
	int lado;
public:

	CTriangulo(int x, int y, int lado);
	~CTriangulo();
	void dibujar(Graphics^ g) override;
	void mover(Graphics^ g) override;
	Rectangle* getRectangle() override;
};

CTriangulo::CTriangulo(int x, int y, int lado) : CFigura(x, y, 12, 20)
{
	this->lado = lado;
}

CTriangulo::~CTriangulo()
{
}

void CTriangulo::dibujar(Graphics^ g)
{
	if (!visible) return;
	SolidBrush^ b = gcnew SolidBrush(Color::Blue);
	cli::array<Point>^ points = {
		Point(x + lado / 2, y),
		Point(x, y + lado),
		Point(x + lado, y + lado)
	};
	g->FillPolygon(b, points);
}

void CTriangulo::mover(Graphics^ g)
{
	if (!visible) return;
	if (y + desplazamiento < 0 || y + desplazamiento + lado > g->VisibleClipBounds.Height) {
		desplazamiento *= -1;
	}
	y += desplazamiento;
}

Rectangle* CTriangulo::getRectangle()
{
	return new Rectangle(x, y, lado, lado);
}
