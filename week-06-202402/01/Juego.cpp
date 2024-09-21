#include "Juego.h"

bool Juego::detectarColision() {
	for (int i = 0; i < listaTerrestre.size(); i++) {
		int vehiculoX = listaTerrestre[i]->getX();
		int vehiculoY = listaTerrestre[i]->getY();

		int vehiculoAncho, vehiculoAlto;

		if (dynamic_cast<Bus*>(listaTerrestre[i])) {
			vehiculoAncho = 16;
			vehiculoAlto = 4;
		}
		else if (dynamic_cast<Carro*>(listaTerrestre[i])) {
			vehiculoAncho = 10;
			vehiculoAlto = 3;
		}

		int personajeX = personaje->getX();
		int personajeY = personaje->getY();

		if (personajeX >= vehiculoX && personajeX < vehiculoX + vehiculoAncho &&
			personajeY >= vehiculoY && personajeY < vehiculoY + vehiculoAlto) {
			return true;
		}
	}
	return false;
}

Juego::Juego() {
	for (int i = 0, y = 5; i < 4; i++) {
		int num = rand() % 3 + 1;
		switch (num) {
		case 1:
			listaTerrestre.push_back(new Bus(60, y));
			break;
		case 2:
			listaTerrestre.push_back(new Carro(1, y));
			break;
		case 3:
			listaTerrestre
				.push_back(new Bicicleta(1, y));
			break;
		}
		y += 7;
	}
	personaje = new Persona(40, 39);
}

Juego::~Juego() {
	for (int i = 0; i < listaTerrestre.size(); i++) {
		delete listaTerrestre[i];
	}
	listaTerrestre.clear();
	delete personaje;
}


void Juego::jugar() {
	System::Console::SetWindowSize(80, 40);
	float velocidad[2] = { -0.1, 0.1 };
	while (true) {
		for (int i = 0; i < listaTerrestre.size(); i++) {
			listaTerrestre[i]->borrar();
			listaTerrestre[i]->mover();
			listaTerrestre[i]->dibujar();
			if (Carro* carro = dynamic_cast<Carro*>(listaTerrestre[i])) {
				carro->cambiarVelocidad(velocidad[rand() % 2]);
			}
			else if (Bus* bus = dynamic_cast<Bus*>(listaTerrestre[i])) {
				bus->cambiarVelocidad(velocidad[rand() % 2]);
			}
		}

		personaje->borrar();
		personaje->mover();
		personaje->dibujar();

		if (detectarColision()) {
			break;
		}

		_sleep(50);
	}
	System::Console::Clear();
	System::Console::SetCursorPosition(25, 20);
	cout << "Fuiste atropellado";
	_getch();
}