#include "Juego.h"
#include "chrono"

Juego::Juego() {
	this->gato = new Gato(25, 25);
	cantidad_ratones = rand() % 9 + 7;
	for (int i = 0; i < cantidad_ratones; i++) {
		listaRatones.push_back(new Raton());
	}
	tiempoAnterior = chrono::steady_clock::now();
}

Juego::~Juego() {
	for (int i = 0; i < cantidad_ratones; i++) {
		delete listaRatones[i];
	}
	listaRatones.clear();
	delete gato;
}

bool Juego::detectarColision() {
	for (int i = 0; i < listaRatones.size(); i++) {
		int ratonX = listaRatones[i]->getX();
		int ratonY = listaRatones[i]->getY();

		int ratonAncho = 8;
		int ratonAlto = 1;

		int gatoAncho = 8;
		int gatoAlto = 3;
		int gatoX = gato->getX();
		int gatoY = gato->getY();

		if (gatoX < ratonX + ratonAncho &&
			gatoX + gatoAncho > ratonX &&
			gatoY < ratonY + ratonAlto &&
			gatoY + gatoAlto > ratonY &&
			listaRatones[i]->getVisible()) {
			listaRatones[i]->borrar();
			delete listaRatones[i];
			listaRatones.erase(listaRatones.begin() + i);
			cantidad_ratones--;
			return true;
		}
	}
	return false;
}

void Juego::visibleRaton() {
	auto tiempoAhora = chrono::steady_clock::now();
	auto duracion = chrono::duration_cast<chrono::seconds>(tiempoAhora - tiempoAnterior);
	if (duracion.count() >= 2) {
		tiempoAnterior = tiempoAhora;
		for (Raton* raton : listaRatones) {
			if (!raton->getVisible()) {
				raton->setVisible(true);
				break;
			}
		}
	}
}


void Juego::play() {
	int ratones_iniciales = cantidad_ratones;
	System::Console::SetWindowSize(80, 45);

	auto tiempoInicio = chrono::steady_clock::now();
	while (true) {
		System::Console::SetCursorPosition(35, 43);
		cout << "Ratones:    ";
		System::Console::SetCursorPosition(44, 43);
		cout << cantidad_ratones;

		for (Raton* raton: listaRatones) {
			raton->borrar();
			raton->mover(gato->getX(), gato->getY());
			raton->dibujar();
		}
		gato->borrar();
		gato->mover();
		gato->dibujar();

		detectarColision();
		visibleRaton();

		if (ratones_iniciales / 2 == cantidad_ratones) {
			break;
		}

		_sleep(50);
	}
	System::Console::Clear();
	System::Console::SetCursorPosition(19, 20);
	cout << "¡Ganaste! Todos los ratones fueron atrapados.";
	_sleep(3500);
}


