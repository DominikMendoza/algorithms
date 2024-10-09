#pragma once
#include "Figuras.h"
#include "Elipse.h"
#include "Rectangulo.h"
#include "Cuadrado.h"
#include "Circulo.h"
#include <vector>
class CVCFiguras
{
private:
	vector<CFigura*> Fgrs;
public:
	CVCFiguras();
	~CVCFiguras();

	void AgregarFigura(CFigura*);
	void Dibujar(Graphics^ G);

	void Eliminar();
	CFigura* getFigura(int indx);

};

