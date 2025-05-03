#pragma once
#include "Ovni.hpp"
class OGamma : public Ovni
{
private:
public:
	OGamma(int x);
	~OGamma();
	void dibujar() override;
};

OGamma::OGamma(int x) : Ovni(x, 3, 1)
{
}

OGamma::~OGamma()
{
}

void OGamma::dibujar()
{
	for (int i = 0; i < ancho; i++)
	{
		for (int j = 0; j < alto; j++)
		{
			Console::SetCursorPosition(x + i, y + j);
			cout << "G";
		}
	}
}
