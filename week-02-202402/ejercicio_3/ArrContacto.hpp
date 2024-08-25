#pragma once

#include "Contactos.h"

class ArrContactos
{
private:

	Contacto** Arr;
	int cant;

public:
	 ArrContactos();
	 //Registro
	 void Regedit();
	 //Agregar
	 void Agregar(Contacto *);
	 //Eliminar
	 void Eliminar();
	 //MODIFICAR
	 void Mod();
	 //ReporteMayo
	 void ReporteNacC_May();
	 //ReporteVarones
	 void ReporteC_Varones();
	 //Reporte WhatsApp y Facebook
	 void ReporteContc_W_F();
	 //MOSTRAR CONTACTOS
	 void MOSTRARC();
	 //Agregar Opcion_Contacto
	 void AgregarOP_C();

};


//Crear Contacto

Contacto* CrearContacto() {

	string nombre, facultad, email, RedSocial;
	char  sexo;
	Fecha* fechaNAC;
	long long celular;
	cout << "Ingrese el nombre del contacto: ";
	cin.ignore(); // Para ignorar el buffer restante
	getline(cin, nombre);

	cout << "Ingrese el celular del contacto: ";
	cin >> celular;

	cout << "Ingrese el genero del contacto: ";
	cin >> sexo;

	cout << "Ingrese su facultad: ";
	cin.ignore(); // Ignorar el buffer de entrada antes de getline
	getline(cin, facultad);

	cout << "Ingrese la fecha de nacimiento del contacto (dia/mes/anio): ";
	int d, m, a;
	cin >> d >> m >> a;
	fechaNAC = new Fecha(d, m, a);

	cout << "Ingrese la dirección de correo: ";
	cin.ignore(); // Ignorar el buffer de entrada antes de getline
	getline(cin, email);

	cout << "Ingrese la red social: ";
	getline(cin, RedSocial);
	return new Contacto(nombre, celular, sexo, facultad, fechaNAC, email, RedSocial);

}

//Constructor por Defecto
 ArrContactos:: ArrContactos()
{
	 Arr = nullptr;
	 cant = 0;
}
 //Registro
 void ArrContactos::Regedit() {

	 int N;
	 cout << "Ingrese cantidad de Contactos: ";
	 cin >> N;
	 this->cant = N;
	 
	 Arr = new Contacto *[this->cant];
	 for (int i = 0; i < this->cant; i++) {
		 this->Arr[i] = new Contacto();
	 }

}
 //Agregar
 void ArrContactos::Agregar(Contacto* p) {

	 Contacto** Temp = new Contacto*[this->cant + 1];
	 for (int i = 0; i < this->cant; i++) {
		 Temp[i] = Arr[i];
	 }
	 Temp[cant] = p;

	 delete[] Arr;
	 Arr = Temp;
	 cant++;
 }
 //Eliminar
 void ArrContactos::Eliminar() {
	 int N;
	 do
	 {
		 cout << "Ingrese la posicion del contacto a eliminar: ";
		 cin >> N;
	 } while (N<0 || N>=this->cant);
	 
	 Contacto** Temp = new Contacto * [this->cant - 1];
	 int j = 0;
	 for (int i = 0; i < this->cant; i++) {
		 if (i == N) continue;
		 Temp[j++] = this->Arr[i];
	 }

	 delete[] Arr;
	 Arr = Temp;
	 cant--;
 }
 //Modificar
 void ArrContactos::Mod() {
	 int N;
	 do
	 {
		 cout << "Ingrese la posicion a modificar: ";
		 cin >> N;
	 } while (N<0 || N>=this->cant);
	 
	 Arr[N] = CrearContacto();

 }
 
 //Reporte Mayo
 void ArrContactos::ReporteNacC_May() {
	 cout << "Contactos que cumplen en mayo: ";
	 for (int i = 0; i < this->cant; i++) {
		 if (Arr[i]->getFecNac()->getMes() == 5) {
			 cout << "Contacto N#" << i + 1 << '\n';
			 Arr[i]->MostrarDatos();
			 cout << "\n\n";
		 }
	 }

 }
 //Reporte Varones
 void ArrContactos::ReporteC_Varones(){
	 cout << "Contactos que son varones: ";
	 for (int i = 0; i < this->cant; i++) {
		 if (Arr[i]->getSexo() == 'H') {
			 cout << "Contacto N#" << i + 1 << '\n';
			 Arr[i]->MostrarDatos();
			 cout << "\n\n";
		 }
	 }

 }

 //Reporte WhatsApp y Facebook
  void ArrContactos::ReporteContc_W_F() {
	 cout << "Contactos que usan Facebook y WhatsApp: ";
	 for (int i = 0; i < this->cant; i++) {
		 string RedS = Arr[i]->getRedSocial();

		 bool usaFacebook = RedS.find("Facebook") != string::npos;
		 bool usaWhatsApp = RedS.find("WhatsApp") != string::npos;

		 if (usaFacebook && usaWhatsApp) {
			 cout << "Contacto N#" << i + 1 << '\n';
			 Arr[i]->MostrarDatos();
			 cout << "\n\n";
		 }
	 }
  }
 

 //MOSTRAR CONTACTOS
 void ArrContactos::MOSTRARC() {
	 cout << "Todos los contactos: ";
	 for (int i = 0; i < this->cant; i++) {
		 cout << "Contacto N#"<< i + 1 << '\n';
		 Arr[i]->MostrarDatos();
		 cout << "\n\n";
	 }

 }

 //Agregar Opcion_Contacto
 void ArrContactos::AgregarOP_C() {
	 short opc;
	 do
	 {
		 cout << "1)Ingresaro valores por defecto.\n";
		 cout << "2)Ingresar valores manualmente.\n";
		 cin >> opc;
	 } while (opc<1 || opc >2);

	 switch (opc)
	 {
	 case 1: Agregar(new Contacto()); break;
	 case 2: Agregar(CrearContacto()); break;
	 default:
		 break;
	 }

 }