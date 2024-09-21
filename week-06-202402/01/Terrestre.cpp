#include "Terrestre.h"

Terrestre::Terrestre(float x, float y, float maxVel, float minVel) {
	this->x = x;
	this->y = y;
	this->velocidad = velocidad = minVel + static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * (maxVel  - minVel);;
}