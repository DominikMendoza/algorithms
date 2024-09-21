#include "CControladora.hpp"

int main()
{
	CControladora* c = new CControladora();
	while (!c->terminoJuego())
	{
		c->jugar();
		c->generarPausa(50);
	}
	Console::Clear();
	cout << "Ya jalaron";
	system("pause>0");
	return 0;
}