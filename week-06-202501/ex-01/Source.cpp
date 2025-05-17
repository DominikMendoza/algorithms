#include "Juego.hpp"
int main()
{
	Console::SetWindowSize(WIDTH, HEIGHT);
	Console::CursorVisible = false;
	srand(time(nullptr));
	Juego* juego = new Juego();
	juego->jugar();
	delete juego;
	system("pause>0");
	return 0;
}