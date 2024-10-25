#include "CFigura.hpp"

class CPastilla : public CFigura
{
private:
public:
	CPastilla(int x, int y);
	~CPastilla();
	void mover() override;
	void dibujar() override;
};

CPastilla::CPastilla(int x, int y) : CFigura(x, y, 2, 2)
{
	this->dx = 0;
	this->dy = 0;
}

CPastilla::~CPastilla()
{
}

void CPastilla::mover()
{
}

void CPastilla::dibujar()
{
	for (int i = 0; i < ancho; i++)
	{
		for (int j = 0; j < alto; j++)
		{
			Console::SetCursorPosition(x + j, y + i);
			cout << '*';
		}
	}
}
