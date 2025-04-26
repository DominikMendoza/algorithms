#include "ArrAvion.hpp"
int main()
{
	Console::SetWindowSize(WIDTH, HEIGHT);
	Console::CursorVisible = false;
	srand(time(nullptr));
	ArrAvion* aviones = new ArrAvion();
	for (int i = 0; i < rand() % 3 + 2; i++)
	{
		aviones->agregarElemento(new Avion(i * 16 + 4, 0));
	}

	while (true)
	{
		aviones->animarAviones();
		_sleep(150);
	}
	system("pause>0");
	return 0;
}