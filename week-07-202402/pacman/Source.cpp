#include "CJuego.hpp"
int main()
{
	CJuego* juego = new CJuego();
	while (!juego->juegoTerminado())
	{
		juego->iniciarJuego();
		_sleep(30);
	}
	if (juego->pacmanGano()) {
		cout << "YOU WIN!";
	}
	else {
		cout << "YOU LOSE!";
	}

	system("pause>0");
	return 0;
}