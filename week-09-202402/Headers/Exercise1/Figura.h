#pragma once
#include "iostream"
#include "vector"

using namespace std;
using namespace System::Drawing;

class Figura
{
public:
	Figura();
	virtual double CalcularArea();
	virtual void Dibujar(System::Windows::Forms::PaintEventArgs^ e);
};

Figura::Figura(){}

double Figura::CalcularArea() { return 0.0; }

void Figura::Dibujar(System::Windows::Forms::PaintEventArgs^ e){}