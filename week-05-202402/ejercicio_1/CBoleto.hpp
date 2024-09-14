#pragma once
class CBoleto
{
private:
	int type;
	long long fecha;
public:
	CBoleto(long long fecha);
	~CBoleto();
	int getType();
	long long getFecha();
};

CBoleto::CBoleto(long long fecha)
{
	this->type = rand() % 5;
	this->fecha = fecha;
}

CBoleto::~CBoleto()
{
}

int CBoleto::getType()
{
	return this->type;
}

long long CBoleto::getFecha()
{
	return this->fecha;
}
