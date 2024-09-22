#include "Juego.h"

int main() {
	srand(time(nullptr));
	Juego* juego = new Juego();
	juego->play();
	return 0;
}