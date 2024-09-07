#pragma once
#include <iostream>
using namespace std;
class CAlas
{
private:

public:
	CAlas();
	~CAlas();
	void borrar();
	void dibujar();
};

CAlas::CAlas()
{
}

CAlas::~CAlas()
{
}

void CAlas::borrar()
{
	cout << "        ";
}

void CAlas::dibujar()
{
	cout << "   __|__";
}
