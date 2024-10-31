#pragma once
#include "Mario.h"

class Controladora
{
private:
	Mario* mario;
	int scrollX;

public:
	Controladora();
	~Controladora();
	void mostrarEscenario(Graphics^ g, Bitmap^ img, Rectangle clientRect);
	void gameManagement(Graphics^ g, Bitmap^ imgEscenario, Bitmap^ imgMario, Rectangle clientRect);
	void marioManagement(Graphics^ g, Bitmap^ imgMario);
	Mario* getMario();
};

Controladora::Controladora()
{
	mario = new Mario();
	scrollX = 0;
}

Controladora::~Controladora()
{
	delete mario;
}

void Controladora::mostrarEscenario(Graphics^ g, Bitmap^ img, Rectangle clientRect)
{
	int w = img->Width;
	int h = img->Height;
	scrollX = std::max(0, std::min(scrollX, w - clientRect.Width)); //Limita scrollX para que este entre 0 y el maximo desplazamiento permitido
	Rectangle porcion = Rectangle(scrollX, 0, clientRect.Width, h);
	g->DrawImage(img, clientRect, porcion, GraphicsUnit::Pixel);
}

void Controladora::gameManagement(Graphics^ g, Bitmap^ imgEscenario, Bitmap^ imgMario, Rectangle clientRect)
{
	mostrarEscenario(g, imgEscenario, clientRect);
	marioManagement(g, imgMario);
}

void Controladora::marioManagement(Graphics^ g, Bitmap^ imgMario)
{
	mario->MoverMario(scrollX);
	mario->DibujarMario(g, imgMario);
}

Mario* Controladora::getMario()
{
	return mario;
}