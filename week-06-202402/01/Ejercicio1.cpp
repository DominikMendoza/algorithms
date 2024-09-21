#include "Juego.h"

int main() {
	srand(time(nullptr));
	Juego* sis = new Juego();
	sis->jugar();
	return 0;
}