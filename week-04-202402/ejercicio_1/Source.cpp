#include <conio.h>
#include "CArrCuadrado.hpp"
int main()
{
	srand(time(nullptr));
	Console::SetWindowSize(WIDTH, HEIGHT);
	Console::CursorVisible = false;
	CArrCuadrado* cuadrados = new CArrCuadrado();
	while (true)
	{
		if (kbhit()) {
			char tecla = _getch();
			tecla = toupper(tecla);
			switch (tecla)
			{
			case 'A': cuadrados->agregarCuadradoFinal(); break;
			case 'E': cuadrados->eliminarPrimerCuadrado(); break;
			case 'C': cuadrados->cambiarColores(); break;
			default:
				break;
			}
		}
		cuadrados->animarCuadrados();
		_sleep(35);
	}
	system("pause>0");
	return 0;
}