#include "Figura.h"

Figura::Figura()
{
	x = rand() % 300 + 10;
	y = rand() % 400 + 10;
	dx = (rand() % 2) ? -20 : 20;
	dy = (rand() % 2) ? -20 : 20;
}

Figura::~Figura()
{

}