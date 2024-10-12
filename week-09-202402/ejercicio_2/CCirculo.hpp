#pragma once
#include "CFigura.hpp"
class CCirculo: public CFigura
{
private:
	double diametro;
public:

	CCirculo(int x, int y, double diametro);
	~CCirculo();
	void dibujar(Graphics^ g) override;
	void mover(Graphics^ g) override;
	Rectangle* getRectangle() override;
};

CCirculo::CCirculo(int x, int y, double diametro) : CFigura(x, y, 12, 20)
{
	this->diametro = diametro;
}

CCirculo::~CCirculo()
{
}

void CCirculo::dibujar(Graphics^ g)
{
	if (!visible) return;
	SolidBrush^ b = gcnew SolidBrush(Color::Red);
	g->FillEllipse(b, x, y, diametro, diametro);
}

void CCirculo::mover(Graphics^ g)
{
	if (!visible) return;
	if (x + desplazamiento < 0 || x + desplazamiento + diametro > g->VisibleClipBounds.Width) {
		desplazamiento *= -1;
	}
	x += desplazamiento;
}

Rectangle* CCirculo::getRectangle()
{
	return new Rectangle(x, y, diametro, diametro);
}
