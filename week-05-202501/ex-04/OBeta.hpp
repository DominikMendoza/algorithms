#pragma once
#include "Ovni.hpp"
class OBeta : public Ovni
{
private:
public:
	OBeta(int x);
	~OBeta();
	void dibujar() override;
};

OBeta::OBeta(int x) : Ovni(x, 2, 4)
{
}

OBeta::~OBeta()
{
}

void OBeta::dibujar()
{
	for (int i = 0; i < ancho; i++)
	{
		for (int j = 0; j < alto; j++)
		{
			Console::SetCursorPosition(x + i, y + j);
			cout << "B";
		}
	}
}
