#pragma once
#include <string>
using namespace std;
class CHotel
{
private:
	string name;
public:
	CHotel(string name);
	~CHotel();
	string getName();
};

CHotel::CHotel(string name)
{
	this->name = name;
}

CHotel::~CHotel()
{
}

string CHotel::getName()
{
	return this->name;
}
