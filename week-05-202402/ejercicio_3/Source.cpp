#include <conio.h>
#include "CControladora.hpp"
int main()
{
	CControladora* c = new CControladora();
	while (!c->llegoInvasion())
	{
		if (_kbhit()) {
			char t = _getch();
			t = toupper(t);
			if (t == 'A')
				c->agregarOvniAlfa();
		}
		c->imprimirNumeroNaves();
		c->animarOvnis();
		_sleep(120);
	}
	c->imprimirMensajeFinal();
	system("pause>0");
	return 0;
}