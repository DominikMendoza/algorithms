#pragma once
#include "conio.h"
#include "string"
#include "Carro.h"

class Competencia
{
private:
	Carro** carros;
	int numcarros;
	void MostrarCarros();

public:
	Competencia();
	~Competencia();
	void Iniciar();
};

Competencia::Competencia()
{
	numcarros = 3;
	carros = new Carro * [numcarros];
	carros[0] = new Carro(1, 3, 12);
	carros[1] = new Carro(1, 17, 3);
	carros[2] = new Carro(1, 32, 10);
}

Competencia::~Competencia()
{
	for (int i = 0; i < numcarros; i++)
	{
		delete carros[i];
	}
	delete[] carros;
}

void Competencia::MostrarCarros()
{
	for (int i = 0; i < numcarros; i++)
	{
		carros[i]->Dibujar();
	}
}

void Competencia::Iniciar()
{
	bool iniciarcarrera = false;
	char tecla;
	int x = ANCHO_CONSOLA;
	int y = 0;
	int color = 7;
	MostrarCarros();
	for (int i = 0; i < ALTO_CONSOLA; i++)
	{
		Console::ForegroundColor = ConsoleColor(color);
		Console::SetCursorPosition(x, y + i); cout << char(219);
		Console::ResetColor();
	}
	while (!iniciarcarrera)
	{
		if (_kbhit())
		{
			tecla = toupper(_getch());
			if (tecla == 'G')
			{
				iniciarcarrera = true;
			}
		}
	}
	while (!(carros[0]->LlegoMeta() || carros[1]->LlegoMeta() || carros[2]->LlegoMeta()))
	{
		for (int i = 0; i < numcarros; i++)
		{
			carros[i]->Borrar();
			carros[i]->Mover();
			if (carros[i]->LlegoMeta()) 
			{
				string mensaje = "EL COCHE " + to_string(i + 1) + " GANA!!";
				system("cls");
				Console::SetCursorPosition(ANCHO_CONSOLA / 2 - mensaje.size() / 2, ALTO_CONSOLA / 2);
				cout << mensaje;
				break;
			}
			carros[i]->Dibujar();
		}
		_sleep(50);
	}
}