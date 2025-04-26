#include "Carrera.hpp"
int main()
{
	Console::SetWindowSize(WIDTH, HEIGHT);
	//Console::BackgroundColor = ConsoleColor::Cyan;
	Console::CursorVisible = false;
	//Console::Clear();
	srand(time(nullptr));
	Carrera* carrera = new Carrera();
	carrera->iniciarCarrera();
	carrera->play();
	carrera->mostrarResultados();
	system("pause>0");
	return 0;
}