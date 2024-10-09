#pragma once

#include <iostream>
using namespace std;
using namespace System;
using namespace System::Drawing;

class CFigura
{
protected:
	int x, y;
	int color;
	int dX, dY;
	bool Visible;
	//int ancho, alto;

	double Area;
public:
	CFigura(int, int,int,int,int,bool);
	~CFigura();

	virtual void Borrar(Graphics^ G) = 0;
	virtual void Mover(Graphics^ G) = 0;
	virtual void Dibujar(Graphics^ G) = 0;

	int getX();
	int getY();
	//double getArea();
};

inline CFigura::CFigura(int _x, int _y , int _dx, int _dy , int _color , bool _Visible ) : x(_x), y(_y), dX(_dx),dY(_dy),color(_color),Visible(_Visible) {}

inline CFigura::~CFigura() {}
inline int CFigura::getX()
{
	return this->x;
}
inline int CFigura::getY()
{
	return this->y;
}
/*inline double CFigura::getArea()
{
	return Area;
}*/

