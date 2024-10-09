#pragma once

#include <iostream>
using namespace std;
using namespace System;
using namespace System::Drawing;

class CFigura
{
protected:
	int x, y;
	//int ancho, alto;

	double Area;
public:
	CFigura(int , int );
	~CFigura();

	virtual void Dibujar(Graphics^ G) {};

	//double getArea();
};

inline CFigura::CFigura(int _x, int _y) : x(_x), y(_y){}

inline CFigura::~CFigura(){}
/*inline double CFigura::getArea()
{
	return Area;
}*/

