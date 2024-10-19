#include "Controladora.h"

Controladora::Controladora() {
    circulo = new Circulo(30, 40);
    cuadrado = new Cuadrado(30, 190);
    triangulo = new Triangulo(30, 340);
    carreras = 0;
    ranking[0] = ranking[1] = ranking[2] = 0;
}

Controladora::~Controladora() {
    delete circulo;
    delete triangulo;
    delete cuadrado;
}

void Controladora::moverTodos(Graphics^ g) {
    circulo->mover(g);
    cuadrado->mover(g);
    triangulo->mover(g);
}

void Controladora::dibujarTodos(Graphics^ g) {
    cli::array<Point>^ points = {
        Point(450, 0),
        Point(500, 0),
        Point(500, g->VisibleClipBounds.Height),
        Point(450, g->VisibleClipBounds.Height)
    };

    SolidBrush^ pen = gcnew SolidBrush(Color::White);
    g->FillPolygon(pen, points);

    circulo->dibujar(g);
    cuadrado->dibujar(g);
    triangulo->dibujar(g);
}

bool Controladora::comprobarGanador() {
    int meta = 540;

    if (circulo->getX() + circulo->getDiametro() >= meta) {
        ranking[0]++;
        carreras++;
        return true;
    }
    if (cuadrado->getX() + cuadrado->getLado() >= meta) {
        ranking[1]++;
        carreras++;
        return true;
    }
    if (triangulo->getX() + triangulo->getLado() >= meta) {
        ranking[2]++;
        carreras++;
        return true;
    }

    return false;
}

void Controladora::mostrarRanking() {
    System::String^ mensaje = "Ranking Final:\n";
    mensaje += "1. Circulo: " + ranking[0] + " puntos\n";
    mensaje += "2. Cuadrado: " + ranking[1] + " puntos\n";
    mensaje += "3. Triangulo: " + ranking[2] + " puntos";

    System::Windows::Forms::DialogResult result = System::Windows::Forms::MessageBox::Show(
        mensaje,
        "Ranking Final",
        System::Windows::Forms::MessageBoxButtons::OK,
        System::Windows::Forms::MessageBoxIcon::Information
    );

    if (result == System::Windows::Forms::DialogResult::OK) {
        System::Windows::Forms::Application::Exit();
    }
}


void Controladora::reiniciarFiguras() {
    circulo = new Circulo(30, 40);
    cuadrado = new Cuadrado(30, 190);
    triangulo = new Triangulo(30, 340);
}