#include "Juego.h"
#include "chrono"

Juego::Juego() {
	this->gato = new Gato(25, 25);
	int cantidad_ratones = rand() % 9 + 7;
	for (int i = 0; i < cantidad_ratones; i++) {
		listaRatones.push_back(new Raton());
	}
	tiempoAnterior = chrono::steady_clock::now();
}

Juego::~Juego() {
	for (Raton* raton : listaRatones) {
		delete raton;
	}
	listaRatones.clear();
	delete gato;
}

void Juego::detectarColision() {
	for (int i = 0; i < listaRatones.size(); i++) {
		Raton* raton = listaRatones[i];

		float ratonX = raton->getX(), ratonY = raton->getY();
		int ratonAncho = raton->getAncho(), ratonAlto = raton->getAlto();

		float gatoX = gato->getX(), gatoY = gato->getY();
		int gatoAncho = gato->getAncho(), gatoAlto = gato->getAlto();

		if (gatoX < ratonX + ratonAncho &&
			gatoX + gatoAncho > ratonX &&
			gatoY < ratonY + ratonAlto &&
			gatoY + gatoAlto > ratonY &&
			listaRatones[i]->getVisible()) {
			raton->borrar();
			delete raton;
			listaRatones.erase(listaRatones.begin() + i);
		}
	}
}


void Juego::visibleRaton() {
	chrono::steady_clock::time_point tiempoAhora = chrono::steady_clock::now();
	chrono::seconds duracion = chrono::duration_cast<chrono::seconds>(tiempoAhora - tiempoAnterior);
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
	int ratones_iniciales = listaRatones.size();
	System::Console::SetWindowSize(80, 45);

	chrono::steady_clock::time_point tiempoInicio = chrono::steady_clock::now();
	while (true) {
		System::Console::SetCursorPosition(35, 43);
		cout << "Ratones:    ";
		System::Console::SetCursorPosition(44, 43);
		cout << listaRatones.size();

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

		if (ratones_iniciales / 2 == listaRatones.size()) {
			break;
		}

		_sleep(50);
	}
	System::Console::Clear();
	System::Console::SetCursorPosition(19, 20);
	cout << "¡Ganaste! Todos los ratones fueron atrapados.";
	_sleep(3500);
}


