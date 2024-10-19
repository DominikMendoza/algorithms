#include "Figura.h"

Figura::Figura(int x, int y)
{
	this->x = x;
	this->y = y;
	this->dx = 20;
	this->velocidad = 0.1 + static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * 0.9;
}

Figura::~Figura()
{

}