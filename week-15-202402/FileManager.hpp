#pragma once
#include <fstream>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class FileManager
{
private:
	ofstream writer;
	ifstream reader;
public:
	FileManager();
	~FileManager();
	void saveInTxt(string route, string text);
	string readFile(string route);

};

FileManager::FileManager()
{
}

FileManager::~FileManager()
{
}

void FileManager::saveInTxt(string route, string text)
{
	writer.open(route);
	if (writer.is_open()) {
		writer << text;
		writer.close();
	}
}

string FileManager::readFile(string route)
{
	string line;
	string content;
	reader.open(route);
	if (reader.is_open()) {
		while (getline(reader, line)) {
			content += line + "\n";
		}
		reader.close();
	}
	return content;
}