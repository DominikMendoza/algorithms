#pragma once
#include <vector>
#include "CCuadrado.hpp"
class CArrCuadrado
{
private:
	vector<CCuadrado*> cuadrados;
public:
	CArrCuadrado();
	~CArrCuadrado();
	void agregarCuadradoFinal();
	void eliminarPrimerCuadrado();
	void animarCuadrados();
	void cambiarColores();
};

CArrCuadrado::CArrCuadrado()
{
	cuadrados.push_back(new CCuadrado(0, 0, 1, 0));
}

CArrCuadrado::~CArrCuadrado()
{
}

void CArrCuadrado::agregarCuadradoFinal()
{
	CCuadrado* c = cuadrados[cuadrados.size() - 1];
	cuadrados.push_back(c->obtenerPosicionAnterior());
}

void CArrCuadrado::eliminarPrimerCuadrado()
{
	// .erase(vector.begin() + pos)
	if (cuadrados.size() > 1) {
		cuadrados.erase(cuadrados.begin() + 0);
	}

	/*if (!cuadrados.empty()) {
		cuadrados.erase(cuadrados.begin() + 0);
	}*/
}

void CArrCuadrado::animarCuadrados()
{
	for (int i = 0; i < cuadrados.size(); i++)
	{
		cuadrados[i]->animar();
	}
}

void CArrCuadrado::cambiarColores()
{
	for (int i = 0; i < cuadrados.size(); i++)
	{
		cuadrados[i]->cambiarColor();
	}
}
