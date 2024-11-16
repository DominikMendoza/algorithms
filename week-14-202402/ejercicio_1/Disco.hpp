#pragma once
#include "Movil.hpp"
class Disco : public Movil
{
private:
	int type;
public:
	Disco(int x, int y, int width, int height);
	~Disco();
	void transformar();
	int getType();
};

Disco::Disco(int x, int y, int width, int height) : Movil(x, y, width, height, 0.6)
{
	type = rand() % 2 + 1;
	if (type == 1) {
		dx = 10;
		dy = 0;
	}
	else {
		dy = 10;
		dx = 0;
	}
	idy = type - 1;
}

Disco::~Disco()
{
}

void Disco::transformar()
{
	this->type = 3;
	idy = type - 1;
	this->dx = this->dy = 10;
	//this->rec->Width *= 1.2;
	//this->rec->Height *= 1.2;
}

int Disco::getType()
{
	return this->type;
}
