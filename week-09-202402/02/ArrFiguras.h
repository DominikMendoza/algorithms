#pragma once
#include "Figuras.h"
#include "Triangulo.h"
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
	void Mover(Graphics^ G);
	void Borrar(Graphics^ G);

	void Animar(Graphics^ G);

	void Eliminar();
	void Colision();

	void agrgars();
	CFigura* getFigura(int indx);

	//vector<CFigura*> getVector();
};

