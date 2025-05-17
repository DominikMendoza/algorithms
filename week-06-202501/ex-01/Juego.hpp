#pragma once
#include "Carro.hpp"
#include "Moto.hpp"
#include "Persona.hpp"
#include <vector>

class Juego
{
private:
	vector<Terrestre*> transportes;
	Persona* persona;
	bool juegoTerminado;
public:
	Juego();
	~Juego();
	void jugar();
	void mostrarVidasJugador();
	void mostrarMensajeFinal();
	bool llegoALaMeta();
	bool jugadorEstaMuerto();
};

Juego::Juego()
{
	transportes.push_back(new Carro(0, 0));
	transportes.push_back(new Moto(5, 10));
	transportes.push_back(new Moto(10, 15));
	persona = new Persona();
	juegoTerminado = false;
}

Juego::~Juego()
{
	transportes.clear();
	delete persona;
}

void Juego::jugar()
{
	while (!juegoTerminado)
	{
		for (int i = 0; i < transportes.size(); i++)
		{
			transportes[i]->animar();
			if (transportes[i]->intersectar(persona)) {
				transportes[i]->chocarPersona(persona);
				persona->setearCoordenadas(WIDTH / 2, HEIGHT - 1);
				/* Borra un Terrestre
				transportes[i]->borrar();
				transportes.erase(transportes.begin() + i);
				i--; */
			}
		}
		persona->animar();
		if (llegoALaMeta() || jugadorEstaMuerto()) {
			juegoTerminado = true;
		}
		mostrarVidasJugador();
		_sleep(90);
	}
	mostrarMensajeFinal();
}

void Juego::mostrarVidasJugador()
{
	Console::ForegroundColor = ConsoleColor::Red;
	Console::SetCursorPosition(WIDTH - 4, 0);
	cout << "   ";
	Console::SetCursorPosition(WIDTH - 4, 0);
	cout << char(3) << persona->getVidas();
	Console::ResetColor();
}

void Juego::mostrarMensajeFinal()
{
	Console::Clear();
	if (llegoALaMeta()) {
		Console::SetCursorPosition(WIDTH / 2 - 17, HEIGHT / 2 - 1);
		Console::ForegroundColor = ConsoleColor::Green;
		cout << "Felicidades llegaste a la meta!!!";
	}
	if (jugadorEstaMuerto()) {
		Console::SetCursorPosition(WIDTH / 2 - 14, HEIGHT / 2 - 1);
		Console::ForegroundColor = ConsoleColor::Red;
		cout << "El jugador ha fallecido...";
	}	
}

bool Juego::llegoALaMeta()
{
	return persona->getY() == 0;
}

bool Juego::jugadorEstaMuerto()
{
	return persona->getVidas() == 0;
}
