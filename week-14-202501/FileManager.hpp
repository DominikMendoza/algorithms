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
