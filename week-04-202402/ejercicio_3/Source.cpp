#include "CArrAvion.hpp"
int main()
{
	srand(time(nullptr));
	Console::SetWindowSize(WIDTH, HEIGHT);
	Console::CursorVisible = false;
	CArrAvion* aviones = new CArrAvion();
	int numeroAviones = rand() % 4 + 2;
	for (int i = 0; i < numeroAviones; i++)
	{
		aviones->agregarElemento(new CAvion(i * 17, 0));
	}
	
	while (true) {
		aviones->animarElementos();
		_sleep(150);
	}
	system("pause>0");
	return 0;
}