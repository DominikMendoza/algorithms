#pragma once
#include "Alfa.h"
#include "Beta.h"
#include "Gamma.h"

class Controladora
{
private:
	vector<Alfa*> alfas;
	vector<Beta*> betas;
	vector<Gamma*> gammas;

public:
	Controladora();
	~Controladora();
	void AgregarNaveAlfa();
	void AgregarNaveBeta();
	void AgregarNaveGamma();
	void IniciarAnimacion();
	bool hemosSidoInvados();
};

Controladora::Controladora() {}

Controladora::~Controladora()
{
	for (int i = 0; i < alfas.size(); i++)
	{
		delete alfas[i];
	}
	for (int i = 0; i < betas.size(); i++)
	{
		delete betas[i];
	}
	for (int i = 0; i < gammas.size(); i++)
	{
		delete gammas[i];
	}
	alfas.clear();
	betas.clear();
	gammas.clear();
}

void Controladora::AgregarNaveAlfa()
{
	alfas.push_back(new Alfa());
}

void Controladora::AgregarNaveBeta()
{
	betas.push_back(new Beta());
}

void Controladora::AgregarNaveGamma()
{
	gammas.push_back(new Gamma());
}

bool Controladora::hemosSidoInvados()
{
	return alfas.size() + betas.size() + gammas.size() >= 20;
}

void Controladora::IniciarAnimacion()
{
	int contadorAlfa = 0;
	int contadorBeta = 0;
	bool invasionComenzada = false;
	string mensaje = "COMIENZA LA INVASION!!!";
	Console::SetCursorPosition(ANCHO_CONSOLA / 2 - mensaje.size() / 2, ALTO_CONSOLA / 2);
	cout << mensaje;
    while (true)
    {
        if (!invasionComenzada)
        {
            if (_kbhit())
            {
                char tecla = toupper(_getch());
                if (tecla == 'A')
                {
                    system("cls");
                    invasionComenzada = true;
                    AgregarNaveAlfa();
                    contadorAlfa++;
                }
            }
        }
        if (invasionComenzada)
        {
            if (_kbhit()) {
                char tecla = toupper(_getch()); 
                // Si presiona 'A', agregar una nave Alfa
                if (tecla == 'A') {
                    AgregarNaveAlfa();
                    contadorAlfa++;
                    // Por cada 2 naves Alfa, agregar una nave Beta
                    if (contadorAlfa % 2 == 0) {
                        AgregarNaveBeta();
                        contadorBeta++;
                        // Por cada 2 naves Beta, agregar una nave Gamma
                        if (contadorBeta % 2 == 0) {
                            AgregarNaveGamma();
                        }
                    }
                }
            }
            for (int i = 0; i < alfas.size();)
            {
                alfas[i]->Borrar();
                if (alfas[i]->Mover()) {
                    delete alfas[i];
                    alfas.erase(alfas.begin() + i);  // Eliminar nave que ha alcanzado el límite
                }
                else {
                    alfas[i]->DibujarAlfa();
                    i++;
                }
            }
            for (int i = 0; i < betas.size();)
            {
                betas[i]->Borrar();
                if (betas[i]->Mover()) {
                    delete betas[i];
                    betas.erase(betas.begin() + i);  // Eliminar nave que ha alcanzado el límite
                }
                else {
                    betas[i]->DibujarBeta();
                    i++;
                }
            }
            for (int i = 0; i < gammas.size();)
            {
                gammas[i]->Borrar();
                if (gammas[i]->Mover()) {
                    delete gammas[i];
                    gammas.erase(gammas.begin() + i);  // Eliminar nave que ha alcanzado el límite
                }
                else {
                    gammas[i]->DibujarGamma();
                    i++;
                }
            }
            if (hemosSidoInvados())
            {
                system("cls");
                string mensaje = "HEMOS SIDO INVADIDOS!!!";
                Console::SetCursorPosition(ANCHO_CONSOLA / 2 - mensaje.size() / 2, ALTO_CONSOLA / 2);
                cout << mensaje;
                break;
            }
            _sleep(50);
        }
    }
}