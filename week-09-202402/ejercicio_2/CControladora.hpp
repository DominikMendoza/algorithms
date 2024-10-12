#pragma once
#include <vector>
#include "CCirculo.hpp"
#include "CTriangulo.hpp"
using namespace std;
class CControladora
{
private:
	vector<CCirculo*> circles;
	vector<CTriangulo*> triangles;
	int ancho;
	int alto;
public:
	CControladora(Graphics^ g);
	~CControladora();
	void dibujarTodos(Graphics^ g);
	void moverTodos(Graphics^ g);
	void verificarColisiones();
	void agregarCirculo();
	void agregarTriangulo();
};

CControladora::CControladora(Graphics^ g)
{
	this->ancho = g->VisibleClipBounds.Width;
	this->alto = g->VisibleClipBounds.Height;
	for (int i = 0; i < 3; i++)
	{
		circles.push_back(new CCirculo(rand() % ancho - 30, rand() % alto - 30, rand() % 50 + 50));
	}
}

CControladora::~CControladora()
{
}

void CControladora::dibujarTodos(Graphics^ g)
{
	for (int i = 0; i < circles.size(); i++)
	{
		circles[i]->dibujar(g);
	}
	for (int i = 0; i < triangles.size(); i++)
	{
		triangles[i]->dibujar(g);
	}
}

void CControladora::moverTodos(Graphics^ g)
{
	for (int i = 0; i < circles.size(); i++)
	{
		circles[i]->mover(g);
	}
	for (int i = 0; i < triangles.size(); i++)
	{
		triangles[i]->mover(g);
	}
}

void CControladora::verificarColisiones()
{
	for (int i = 0; i < triangles.size(); i++)
	{
		if (!triangles[i]->isVisible()) continue;
		for (int j = 0; j < circles.size(); j++)
		{
			if (!circles[j]->isVisible()) continue;
			if (triangles[i]->getRectangle()->IntersectsWith(*circles[j]->getRectangle())) {
				triangles[i]->setVisible(false);
				circles[j]->setVisible(false);
				break;
			}
		}
	}
}

void CControladora::agregarCirculo()
{
	circles.push_back(new CCirculo(rand() % 300, rand() % 300, rand() % 50 + 50));
}

void CControladora::agregarTriangulo()
{
	triangles.push_back(new CTriangulo(rand() % ancho - 30, rand() % alto - 30, rand() % 50 + 50));
}
