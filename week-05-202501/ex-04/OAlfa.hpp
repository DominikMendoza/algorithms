#pragma once
#include "Ovni.hpp"
class OAlfa : public Ovni
{
private:
public:
	OAlfa(int x);
	~OAlfa();
	void dibujar() override;
};

OAlfa::OAlfa(int x) : Ovni(x, 3, 3)
{
}

OAlfa::~OAlfa()
{
}

void OAlfa::dibujar()
{
	for (int i = 0; i < ancho; i++)
	{
		for (int j = 0; j < alto; j++)
		{
			Console::SetCursorPosition(x + i, y + j);
			cout << "A";
		}
	}
}
