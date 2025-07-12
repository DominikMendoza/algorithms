#pragma once
#include <vector>
#include "Zoombie.hpp"
#include "Bloque.hpp"
#include "Planta.hpp"

class Controladora
{
private:
	Zoombie* zoo;
	vector<Planta*> plantas;
	vector<Bloque*> bloques;
public:
	Controladora(Bitmap^ bmpZoo, Bitmap^ bmpPlanta, Bitmap^ bmpBloque);
	~Controladora();
	void dibujarObjetos(Graphics^ g, Bitmap^ bmpZoo, Bitmap^ bmpPlanta, Bitmap^ bmpBloque, Bitmap^ bmpFondo);
	void moverObjetos(Graphics^ g);
	void moverPersonaje(Graphics^ g, char tecla);
	void evaluarColisiones();
	Zoombie* getZoombie();
};

Controladora::Controladora(Bitmap^ bmpZoo, Bitmap^ bmpPlanta, Bitmap^ bmpBloque)
{
	zoo = new Zoombie(400, 500, bmpZoo->Width / 4, bmpZoo->Height / 4, rand() % 6 + 5);
	for (int i = 0; i < rand() % 4 + 5; i++)
	{
		int x, y;
		x = rand() % 600 + 100;
		y = rand() % 400 + 50;
		plantas.push_back(new Planta(x, y, bmpPlanta->Width / 8, bmpPlanta->Height));
	}
	for (int i = 0; i < 3; i++)
	{
		int x, y;
		x = rand() % 600 + 100;
		y = rand() % 400 + 50;
		bloques.push_back(new Bloque(x, y, bmpBloque->Width, bmpBloque->Height));
	}
}

Controladora::~Controladora()
{
}

void Controladora::dibujarObjetos(Graphics^ g, Bitmap^ bmpZoo, Bitmap^ bmpPlanta, Bitmap^ bmpBloque, Bitmap^ bmpFondo)
{
	// Dibujar Fondo
	Rectangle rec = Rectangle(0, 0, bmpFondo->Width, bmpFondo->Height);
	g->DrawImage(bmpFondo, g->VisibleClipBounds, rec, GraphicsUnit::Pixel);

	zoo->dibujar(g, bmpZoo);
	for (int i = 0; i < plantas.size(); i++)
	{
		plantas[i]->dibujar(g, bmpPlanta);
	}
	for (int i = 0; i < bloques.size(); i++)
	{
		bloques[i]->dibujar(g, bmpBloque);
	}
}

void Controladora::moverObjetos(Graphics^ g)
{
	for (int i = 0; i < plantas.size(); i++)
	{
		plantas[i]->mover(g, 'x');
	}
}

void Controladora::moverPersonaje(Graphics^ g, char tecla)
{
	for (int i = 0; i < bloques.size(); i++)
	{
		if (!zoo->puedeMoverse(tecla, bloques[i])) {
			return;
		}
	}
	zoo->mover(g, tecla);
}

void Controladora::evaluarColisiones()
{
	for (int i = 0; i < plantas.size(); i++)
	{
		if (plantas[i]->estaColisionandoCon(zoo)) {
			zoo->disminuirVidas();
			plantas.erase(plantas.begin() + i);
			return;
		}
	}
}

Zoombie* Controladora::getZoombie()
{
	return this->zoo;
}
