#pragma once
#include "Circulo.h"
#include "Cuadrado.h"
#include "Triangulo.h"

ref class Competencia
{
private:
	Cuadrado^ cuadrado;
	Triangulo^ triangulo;
	Circulo^ circulo;
	int meta;
	int totalCarreras;
	int victoriasCuadrado;
	int victoriasCirculo;
	int victoriasTriangulo;

public:
	Competencia();
	void Iniciar(Graphics^ g);
	void MostrarRanking(Graphics^ g);
	Color GenerarColorAleatorio();
	bool TodosEnCarrera(); 
	void DibujarFiguras(Graphics^ g);
	void MoverFiguras();
	void VerificarVictorias();
	int getCantidadCarreras();
	int getMeta();
	void reducirCantidadCarreras();
};

Competencia::Competencia()
{
	meta = 890;
	totalCarreras = 5;
	victoriasCirculo = 0;
	victoriasCuadrado = 0;
	victoriasTriangulo = 0;
}

bool Competencia::TodosEnCarrera()
{
	return cuadrado->getX() < meta && triangulo->getX() < meta && circulo->getX() < meta;
}

Color Competencia::GenerarColorAleatorio()
{
	int r = RandInt(0, 255);
	int g = RandInt(0, 255);
	int b = RandInt(0, 255);
	return Color::FromArgb(r, g, b); 
}

void Competencia::Iniciar(Graphics^ g)
{
	cuadrado = gcnew Cuadrado(0, 40, 1, RandFloat(1.1, 2.5), GenerarColorAleatorio(), 50);
	triangulo = gcnew Triangulo(0, 264, 1, RandFloat(1.1, 2.5), GenerarColorAleatorio(), 50);
	circulo = gcnew Circulo(0, 454, 1, RandFloat(1.1, 2.5), GenerarColorAleatorio(), 50);
}

void Competencia::MostrarRanking(Graphics^ g)
{
	int centroX = 1000 / 2 - 85;
	int centroY = 567 / 2 - 130;
	g->DrawString("Ranking", gcnew Font("Arial", 16), Brushes::Black, Point(centroX + 10, centroY));
	g->DrawString("=========", gcnew Font("Arial", 16), Brushes::Black, Point(centroX, centroY + 30));
	g->DrawString("Cuadrado: " + victoriasCuadrado, gcnew Font("Arial", 16), Brushes::Black, Point(centroX, centroY + 60)); 
	g->DrawString("Triangulo: " + victoriasTriangulo, gcnew Font("Arial", 16), Brushes::Black, Point(centroX, centroY + 90));
	g->DrawString("Circulo: " + victoriasCirculo, gcnew Font("Arial", 16), Brushes::Black, Point(centroX, centroY + 120));
	if (totalCarreras == 0)
	{
		String^ ganador;
		if (victoriasCuadrado > victoriasTriangulo && victoriasCuadrado > victoriasCirculo)
		{
			ganador = "EL CUADRADO ES EL GANADOR!!";
			g->DrawString(ganador, gcnew Font("Arial", 18, FontStyle::Bold), Brushes::Red, Point(centroX - 100, centroY + 170));
		}
		else if (victoriasTriangulo > victoriasCuadrado && victoriasTriangulo > victoriasCirculo)
		{
			ganador = "EL TRIANGULO ES EL GANADOR!!";
			g->DrawString(ganador, gcnew Font("Arial", 18, FontStyle::Bold), Brushes::Red, Point(centroX - 100, centroY + 170));
		}
		else if (victoriasCirculo > victoriasCuadrado && victoriasCirculo > victoriasTriangulo)
		{
			ganador = "EL CIRCULO ES EL GANADOR!!";
			g->DrawString(ganador, gcnew Font("Arial", 18, FontStyle::Bold), Brushes::Red, Point(centroX - 100, centroY + 170));
		}
		else if (victoriasCuadrado >= victoriasTriangulo && victoriasCuadrado > victoriasCirculo)
		{
			ganador = "LOS GANADORES SON EL CUADRADO Y EL TRIANGULO!!";
			g->DrawString(ganador, gcnew Font("Arial", 18, FontStyle::Bold), Brushes::Red, Point(centroX - 215, centroY + 170));
		}
		else if (victoriasCuadrado >= victoriasCirculo && victoriasCuadrado > victoriasTriangulo)
		{
			ganador = "LOS GANADORES SON EL CUADRADO Y EL CIRCULO!!";
			g->DrawString(ganador, gcnew Font("Arial", 18, FontStyle::Bold), Brushes::Red, Point(centroX - 215, centroY + 170));
		}
		else if (victoriasCuadrado >= victoriasTriangulo && victoriasCuadrado > victoriasCirculo)
		{
			ganador = "LOS GANADORES SON EL CUADRADO Y EL TRIANGULO!!";
			g->DrawString(ganador, gcnew Font("Arial", 18, FontStyle::Bold), Brushes::Red, Point(centroX - 215, centroY + 170));
		}
		else if (victoriasCirculo >= victoriasTriangulo && victoriasCirculo > victoriasCuadrado)
		{
			ganador = "LOS GANADORES SON EL CIRCULO Y EL TRIANGULO!!";
			g->DrawString(ganador, gcnew Font("Arial", 18, FontStyle::Bold), Brushes::Red, Point(centroX - 215, centroY + 170));
		}
		else
		{
			ganador = "ES UN EMPATE!!";
			g->DrawString(ganador, gcnew Font("Arial", 18, FontStyle::Bold), Brushes::Red, Point(centroX - 10, centroY + 170));
		}
	}

}

void Competencia::DibujarFiguras(Graphics^ g)
{
	cuadrado->Dibujar(g);
	triangulo->Dibujar(g);
	circulo->Dibujar(g);
}

void Competencia::MoverFiguras()
{
	cuadrado->Mover();
	triangulo->Mover();
	circulo->Mover();
}

void Competencia::VerificarVictorias()
{
	if (cuadrado->getX() >= meta) victoriasCuadrado++;
	else if (triangulo->getX() >= meta) victoriasTriangulo++;
	else if (circulo->getX() >= meta) victoriasCirculo++;
}

int Competencia::getCantidadCarreras()
{
	return totalCarreras;
}

void Competencia::reducirCantidadCarreras()
{
	totalCarreras--;
}

int Competencia::getMeta()
{
	return meta;
}