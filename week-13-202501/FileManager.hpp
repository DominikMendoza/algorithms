#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class FileManager
{
private:
	ofstream writer;
	ifstream reader;
public:
	FileManager();
	~FileManager();
	void guardarEnTxt(string route, string txt);
	string leerDeTxt(string route);
	vector<int> lecturaEspecialDeArchivo(string route);
	int getArbolesRojos(string route);
	int getArbolesVerdes(string route);
	pair<int, int> getArboles(string route);
};

FileManager::FileManager()
{
}

FileManager::~FileManager()
{
}

void FileManager::guardarEnTxt(string route, string txt)
{
	writer.open(route);
	if (!writer.is_open()) {
		cout << "Hubo un error al abrir el archivo...";
		return;
	}
	
	writer << txt;
	writer.close();
}

string FileManager::leerDeTxt(string route)
{
	string content, line;
	reader.open(route);
	if (!reader.is_open()) {
		cout << "Hubo un error al leer el archivo...";
		return "";
	}

	while (getline(reader, line))
	{
		content += line + "\n";
	}
	reader.close();
	return content;
}

vector<int> FileManager::lecturaEspecialDeArchivo(string route)
{
	vector<int> resultado;
	string texto = this->leerDeTxt(route);
	if (texto.empty()) {
		return vector<int>();
	}

	int x;
	stringstream ss = stringstream(texto);
	ss >> x;
	resultado.push_back(x);
	ss >> x;
	resultado.push_back(x);
	ss >> x;
	resultado.push_back(x);
	return resultado;
}

int FileManager::getArbolesRojos(string route)
{
	string aux;
	int arboles;
	string texto = this->leerDeTxt(route);
	if (texto.empty()) return 0;
	stringstream ss = stringstream(texto);
	ss >> aux >> aux >> arboles;
	return arboles;
}

int FileManager::getArbolesVerdes(string route)
{
	string aux;
	int arboles;
	string texto = this->leerDeTxt(route);
	if (texto.empty()) return 0;
	stringstream ss = stringstream(texto);
	ss >> aux >> aux >> arboles;
	ss >> aux >> aux >> arboles;
	return arboles;
}

pair<int, int> FileManager::getArboles(string route)
{
	string aux;
	int arbRojos, arbVerdes;
	string texto = this->leerDeTxt(route);
	if (texto.empty()) return make_pair(0, 0);
	stringstream ss = stringstream(texto);
	ss >> aux >> aux >> arbRojos;
	ss >> aux >> aux >> arbVerdes;
	return make_pair(arbRojos, arbVerdes);
}
