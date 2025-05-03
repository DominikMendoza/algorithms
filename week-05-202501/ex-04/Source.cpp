#include <conio.h>
#include "Invasion.hpp"

void ejemplo() {
	Ovni* ovni = new OAlfa(1);
	ovni->dibujar();

	ovni = new OBeta(10);
	ovni->dibujar();

	ovni = new OGamma(20);
	ovni->dibujar();
}
int main()
{
	srand(time(nullptr));
	Console::SetWindowSize(WIDTH, HEIGHT);
	Console::CursorVisible = false;
	Invasion* inv = new Invasion();
	while (!inv->terminoInvasion())
	{
		if (kbhit()) {
			char tecla = _getch();
			tecla = toupper(tecla);
			if (tecla == 'A') {
				inv->agregarNaveAlfa();
			}
		}
		inv->animarNaves();
		inv->imprimirCantidadDeNaves();
		_sleep(150);
	}
	Console::Clear();
	cout << "Hemos sido invadidos";
	system("pause>0");
	return 0;
}