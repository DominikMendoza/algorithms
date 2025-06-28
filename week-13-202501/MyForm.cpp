#include "MyForm.h"
#include "FileManager.hpp"

using namespace Project54;

void ejemplo() {
	FileManager* fm = new FileManager();
	// fm->guardarEnTxt("resultado.txt", "HolaMundo\nEjemplo\nNuevaLinea\ttabulado\ttabulado");
	// cout << fm->leerDeTxt("ejemplo.txt");

	vector<int> ejemplo = fm->lecturaEspecialDeArchivo("numeros.txt");
	cout << "Size del vector: " << ejemplo.size() << endl;
	for (int i = 0; i < ejemplo.size(); i++)
	{
		cout << ejemplo[i] << endl;
	}
}
int main()
{
	Application::Run(gcnew MyForm);
	return 0;
}