#pragma once
#include <iostream>
using namespace std;
class CFuselaje
{
private:

public:
	CFuselaje();
	~CFuselaje();
	void borrar();
	void dibujar();
};

CFuselaje::CFuselaje()
{
}

CFuselaje::~CFuselaje()
{
}

void CFuselaje::borrar()
{
	cout << "          ";
}

void CFuselaje::dibujar()
{
	cout << "*---oOo---";
}
