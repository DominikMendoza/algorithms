#pragma once
#include "Bicicleta.h"
#include "Bus.h"
#include "Carro.h"
#include "Persona.h"

class Juego
{
private:
	vector<Terrestre*> vehiculos;
	Persona* personaje;
	bool Colision();
	void agregarVehiculo(int y);

public:
	Juego();
	~Juego();
	void Iniciar();
};

Juego::Juego() 
{
	int y = 5;  
	for (int i = 0; i < 4; i++) 
	{
		agregarVehiculo(y);  
		y += 7;  
	}
	personaje = new Persona(ANCHO_CONSOLA / 2, ALTO_CONSOLA - 1);
}

Juego::~Juego()
{
	delete personaje;
	for (int i = 0; i < vehiculos.size(); i++) 
	{
		delete vehiculos[i];
	}
	vehiculos.clear();
}

void Juego::agregarVehiculo(int y) 
{
	int tipo = rand() % 3;
	Terrestre* nuevoVehiculo = nullptr;
	switch (tipo)
	{
	case 0:
		nuevoVehiculo = new Bus(ANCHO_CONSOLA - 20, y);
		break;
	case 1:
		nuevoVehiculo = new Carro(1, y);
		break;
	case 2:
		nuevoVehiculo = new Bicicleta(1, y);
		break;
	}
	vehiculos.push_back(nuevoVehiculo);
}

bool Juego::Colision()
{
	for (int i = 0; i < vehiculos.size(); i++) 
	{
		if (personaje->getX() < vehiculos[i]->getX() + vehiculos[i]->getAncho() && personaje->getX() + personaje->getAncho() > vehiculos[i]->getX() && personaje->getY() < vehiculos[i]->getY() + vehiculos[i]->getAlto() && personaje->getY() + personaje->getAlto() > vehiculos[i]->getY())
		{
			return true;
		}
	}
	return false;
}

void Juego::Iniciar()
{
	while (true) {
		for (int i = 0; i < vehiculos.size(); i++)
		{
			vehiculos[i]->Borrar();
			vehiculos[i]->Mover();
			vehiculos[i]->Dibujar();
		}
		personaje->Borrar();
		personaje->Mover();
		personaje->Dibujar();
		_sleep(50);
		if (personaje->getY() == 0)
		{
			system("cls");
			string mensaje = "GANASTE!!!";
			Console::SetCursorPosition(ANCHO_CONSOLA / 2 - mensaje.size() / 2, ALTO_CONSOLA / 2);
			cout << mensaje;
			break;
		}
		if (Colision()) 
		{
			system("cls");
			string mensaje = "PERDISTE!!!";
			Console::SetCursorPosition(ANCHO_CONSOLA / 2 - mensaje.size() / 2, ALTO_CONSOLA / 2);
			cout << mensaje;
			break;
		}
	}
}