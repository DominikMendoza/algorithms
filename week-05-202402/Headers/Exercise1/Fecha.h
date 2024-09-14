#pragma once
#include "iostream"
#include "string"

using namespace std;

class Fecha
{
private:
	int day;
	int month;
	int year;

public:
	Fecha(int day, int month, int year);
	int getDay();
	int getMonth();
	int getYear();
	string mostrarFecha();
};

Fecha::Fecha(int day, int month, int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}

int Fecha::getDay()
{
	return day;
}

int Fecha::getMonth()
{
	return month;
}

int Fecha::getYear()
{
	return year;
}

string Fecha::mostrarFecha()
{
	return to_string(day) + "/" + to_string(month) + "/" + to_string(year);
}