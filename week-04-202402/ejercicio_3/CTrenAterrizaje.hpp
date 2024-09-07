#pragma once
#include <iostream>
using namespace std;
class CTrenAterrizaje
{
private:

public:
	CTrenAterrizaje();
	~CTrenAterrizaje();
	void borrar();
	void dibujar();
};

CTrenAterrizaje::CTrenAterrizaje()
{
}

CTrenAterrizaje::~CTrenAterrizaje()
{
}

void CTrenAterrizaje::borrar()
{
	cout << " ";
}

void CTrenAterrizaje::dibujar()
{
	cout << "*";
}
