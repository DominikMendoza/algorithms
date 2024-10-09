#include "JuegoGatoRaton.h"

int main()
{
	Ventana();
	srand(time(nullptr));
	Juego* juego = new Juego();
	juego->Iniciar();

	delete juego;

	system("pause>0");
	return 0;
}