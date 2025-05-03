#pragma once
#include "PlanVacacion.hpp"

class ArrPlanVacacion
{
private:
	PlanVacacion** elementos;
	int cantidad;
public:
	ArrPlanVacacion() {
		elementos = nullptr;
		cantidad = 0;
	}
	~ArrPlanVacacion() {}

	void agregarElemento(PlanVacacion* pntrElemento) {
		PlanVacacion** tpm = new PlanVacacion * [cantidad + 1];
		for (int i = 0; i < cantidad; i++)
		{
			tpm[i] = elementos[i];
		}
		tpm[cantidad] = pntrElemento;

		delete[] elementos;
		elementos = tpm;
		cantidad++;
	}

	void mostrarElementos() {
		for (int i = 0; i < cantidad; i++)
		{
			elementos[i]->mostrarPlan();
		}
	}

	void listarSegunFechaDeBoleto(int fechaInicial, int fechaLimite) {
		for (int i = 0; i < cantidad; i++)
		{
			if (elementos[i]->getFechaBoleto() >= fechaInicial &&
				elementos[i]->getFechaBoleto() <= fechaLimite) {
				elementos[i]->mostrarPlan();
			}
		}
	}

	void listarSegunNombreDeHotel(string nombreHotel) {
		for (int i = 0; i < cantidad; i++)
		{
			if (elementos[i]->getNombreHotel() == nombreHotel) {
				elementos[i]->mostrarPlan();
			}
		}
	}

	void listarUnicamenteBoletos() {
		for (int i = 0; i < cantidad; i++)
		{
			elementos[i]->mostrarBoleto();
			cout << endl;
		}
	}

	int size() {
		return this->cantidad;
	}
};