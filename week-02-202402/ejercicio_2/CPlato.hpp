#pragma once
#include <iostream>
#include <string>
using namespace std;
class CPlato
{
private:
	string nombrePlato;
	bool esFrio, esPicante;
	float cantidadCalorias, precioPromedio;
public:
	CPlato() {
		this->nombrePlato = "std";
        this->esFrio = rand() % 2;
        this->esPicante = rand() % 2;
		this->cantidadCalorias = (rand() % 10000) / 10.0;
		this->precioPromedio = (rand() % 3000) / 10.0;
	}

	CPlato(string nombrePlato, bool esFrio, bool esPicante, float cantidadCalorias, float precioPromedio) {
		this->nombrePlato = nombrePlato;
		this->esFrio = esFrio;
		this->esPicante = esPicante;
		this->cantidadCalorias = cantidadCalorias;
		this->precioPromedio = precioPromedio;
	}
	~CPlato() { }

    void mostrarDatos() {
        cout << "Nombre del Plato: " << nombrePlato << endl;
        cout << "Es Frio: " << (esFrio ? "Si" : "No") << endl;
        cout << "Es Picante: " << (esPicante ? "Si" : "No") << endl;
        cout << "Cantidad de Calorias: " << cantidadCalorias << endl;
        cout << "Precio Promedio: " << precioPromedio << endl;
    }

    void setNombrePlato(string nombrePlato) {
        this->nombrePlato = nombrePlato;
    }

    void setEsFrio(bool esFrio) {
        this->esFrio = esFrio;
    }

    void setEsPicante(bool esPicante) {
        this->esPicante = esPicante;
    }

    void setCantidadCalorias(float cantidadCalorias) {
        this->cantidadCalorias = cantidadCalorias;
    }

    void setPrecioPromedio(float precioPromedio) {
        this->precioPromedio = precioPromedio;
    }

    bool getEsPicante() {
        return this->esPicante;
    }

    float getPrecioPromedio() {
        return this->precioPromedio;
    } 
};