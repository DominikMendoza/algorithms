#pragma once
#include <iostream>
#include <conio.h>
#define WIDTH 80
#define HEIGHT 40
#define UP 72
#define DOWN 80
#define RIGHT 77
#define LEFT 75
#define DIST 10
using namespace System;
using namespace std;

class CMovil
{
protected:
	float x, y, dx, dy;
	char forma;
	float distancia(CMovil* ext);
public:
	CMovil(float x, float y, char forma);
	~CMovil();
	void borrar();
	virtual void mover(CMovil* ext);
	void dibujar();
	void animar(CMovil* ext);
	bool intersectar(CMovil* ext);
	float getX();
	float getY();
};

float CMovil::distancia(CMovil* ext)
{
	return sqrt(pow(x - ext->x, 2) + pow(y - ext->y, 2));
}

CMovil::CMovil(float x, float y, char forma)
{
	this->x = x;
	this->y = y;
	this->forma = forma;
	this->dx = 0;
	this->dy = 0;
}

CMovil::~CMovil()
{
}

void CMovil::borrar()
{
	Console::SetCursorPosition(x, y);
	cout << " ";
}

void CMovil::mover(CMovil* ext)
{
}

void CMovil::dibujar()
{
	Console::SetCursorPosition(x, y);
	cout << this->forma;
}

void CMovil::animar(CMovil* ext)
{
	borrar();
	mover(ext);
	dibujar();
}

bool CMovil::intersectar(CMovil* ext)
{
	return (x == ext->x && y == ext->y);
}

float CMovil::getX()
{
	return this->x;
}

float CMovil::getY()
{
	return this->y;
}
