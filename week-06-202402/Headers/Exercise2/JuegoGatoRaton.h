#pragma once
#include "VectorRatones.h"
#include "Gato.h"

class Juego
{
private:
    Gato* gato;
    VectorRatones* vectorRatones;
    chrono::steady_clock::time_point tiempoAnterior;
    void Colision();
    void visibleRaton();

public:
    Juego();
    ~Juego();
    void Iniciar();
};

Juego::Juego()
{
    gato = new Gato((ANCHO_CONSOLA - 8) / 2, ALTO_CONSOLA - 20);
    vectorRatones = new VectorRatones();

    int cantidadRatones = RandInt(7, 15);
    for (int i = 0; i < cantidadRatones; i++)
    {
        vectorRatones->AgregarRaton(new Raton());
    }
    tiempoAnterior = chrono::steady_clock::now();
}

Juego::~Juego()
{
    delete gato;
    delete vectorRatones;
}

void Juego::Colision() {
    for (int i = 0; i < vectorRatones->getCantidadRatones(); i++) {
        Raton* raton = vectorRatones->obtenerRaton(i);

        float ratonX = raton->getX(), ratonY = raton->getY();
        int ratonAncho = raton->getAncho(), ratonAlto = raton->getAlto();

        float gatoX = gato->getX(), gatoY = gato->getY();
        int gatoAncho = gato->getAncho(), gatoAlto = gato->getAlto();

        if (gatoX < ratonX + ratonAncho &&
            gatoX + gatoAncho > ratonX &&
            gatoY < ratonY + ratonAlto &&
            gatoY + gatoAlto > ratonY &&
            raton->getVisible()) {
            raton->Borrar();
            vectorRatones->EliminarRaton(i);
        }
    }
}

void Juego::visibleRaton()
{
    std::chrono::steady_clock::time_point tiempoAhora = std::chrono::steady_clock::now();
    std::chrono::seconds duracion = std::chrono::duration_cast<std::chrono::seconds>(tiempoAhora - tiempoAnterior);
    if (duracion.count() >= 2)
    {
        tiempoAnterior = tiempoAhora;
        for (int i = 0; i < vectorRatones->getCantidadRatones(); i++)
        {
            Raton* raton = vectorRatones->obtenerRaton(i);
            if (!raton->getVisible())
            {
                raton->setVisible(true);
                break;
            }
        }
    }
}

void Juego::Iniciar()
{
    int ratonesIniciales = vectorRatones->getCantidadRatones();
    chrono::steady_clock::time_point tiempoInicio = std::chrono::steady_clock::now();
    while (true)
    {
        string mensaje = "Ratones:    ";
        Console::SetCursorPosition(ANCHO_CONSOLA / 2 - mensaje.size() / 2, ALTO_CONSOLA - 7);
        cout << mensaje;
        Console::SetCursorPosition((ANCHO_CONSOLA / 2 - mensaje.size() / 2) + 9, ALTO_CONSOLA - 7);
        cout << vectorRatones->getCantidadRatones();
        for (int i = 0; i < vectorRatones->getCantidadRatones(); i++)
        {
            Raton* raton = vectorRatones->obtenerRaton(i);
            raton->Borrar();
            raton->MoverRaton(gato->getX(), gato->getY());
            raton->Dibujar();
        }
        gato->Borrar();
        gato->Mover();
        gato->Dibujar();
        Colision();
        visibleRaton();
        if (ratonesIniciales / 2 == vectorRatones->getCantidadRatones())
        {
            break;
        }
        _sleep(50);
    }
    system("cls");
    string mensaje = "GANASTE!!!. ATRAPASTE A LA MITAD DE LOS RATONES!!!";
    Console::SetCursorPosition(ANCHO_CONSOLA / 2 - mensaje.size() / 2, ALTO_CONSOLA / 2);
    cout << mensaje;
}