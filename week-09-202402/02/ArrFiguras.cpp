#include "ArrFiguras.h"

CVCFiguras::CVCFiguras()
{
}

CVCFiguras::~CVCFiguras()
{
	for(int i = 0 ; i<Fgrs.size();i++)
	{
		delete Fgrs[i];
	}
	Fgrs.clear();
}


void CVCFiguras::AgregarFigura(CFigura* F)
{
		
	Random^ r = gcnew Random();
	if(r->Next(1000) % 50 == 0)
		Fgrs.push_back(F);
}

void CVCFiguras::Borrar(Graphics^ G)
{
	if (Fgrs.size() != 0)
	{
		for (int i = 0; i < Fgrs.size(); i++)
		{
			Fgrs.at(i)->Borrar(G);
		}
	}
}

void CVCFiguras::Mover(Graphics^ G)
{
	if (Fgrs.size() != 0)
	{
		for (int i = 0; i < Fgrs.size(); i++)
		{
			Fgrs.at(i)->Mover(G);
		}
	}
}

void CVCFiguras::Dibujar(Graphics^ G)
{
	if (Fgrs.size() != 0)
	{
		for (int i = 0; i < Fgrs.size(); i++)
		{
			Fgrs.at(i)->Dibujar(G);
		}
	}
}

void CVCFiguras::Animar(Graphics^ G)
{
	Borrar(G);
	Mover(G);
	Dibujar(G);
}

void CVCFiguras::Eliminar()
{
}

void CVCFiguras::Colision()
{


}

void CVCFiguras::agrgars()
{
	

	
}

CFigura* CVCFiguras::getFigura(int indx)
{
	if(Fgrs.at(indx) != nullptr && indx >=0)
	return Fgrs[indx];
}


