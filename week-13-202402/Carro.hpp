#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include "FileManager.hpp"
using namespace System::Drawing;

class Carro
{
private:
	int x, y, dx;
	int idx, idy;
	int width, height;
	FileManager* fm;
	vector<Rectangle*> obstaculos;
public:
	Carro(int width, int height);
	~Carro();
	void move(Graphics^ g);
	void changeAnimation(int opc);
	void draw(Graphics^ g, Bitmap^ bmp);

};

Carro::Carro(int width, int height)
{
	dx = 5;
	idx = idy = 0;
	this->width = width;
	this->height = height;

	fm = new FileManager();
	string contenido;
	contenido = fm->readFile("Config.txt");
	stringstream ss;
	ss = stringstream(contenido);
	ss >> x;
	ss >> y;

	contenido = fm->readFile("Obstaculos.txt");
	ss = stringstream(contenido);
	int numeroObstaculos, x, y, ancho, alto;
	ss >> numeroObstaculos;
	for (int i = 0; i < numeroObstaculos; i++)
	{
		ss >> x >> y >> ancho >> alto;
		obstaculos.push_back(new Rectangle(x, y, ancho, alto));
	}
}

Carro::~Carro()
{
}

void Carro::move(Graphics^ g)
{
	idx++;
	if (idx >= 5) {
		idx = 0;
		idy = 0;
	}
}

void Carro::changeAnimation(int opc)
{
	idy = opc;
	idx = 0;
}

void Carro::draw(Graphics^ g, Bitmap^ bmp)
{
	Rectangle sectionShow = Rectangle(idx * width, idy * height, width, height);
	Rectangle sectionForm = Rectangle(x, y, width, height);
	g->DrawImage(bmp, sectionForm, sectionShow, GraphicsUnit::Pixel);

	SolidBrush^ brush = gcnew SolidBrush(Color::Red);
	for (int i = 0; i < obstaculos.size(); i++)
	{
		g->FillRectangle(brush, *obstaculos[i]);
	}
}
