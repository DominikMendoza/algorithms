#pragma once
#include  <string>
using namespace System::Drawing;

class Controller
{
private:
	int width, height, idx, idy, type;
	int tacleadasDerecha, tacleadasIzquierda;
public:
	Controller(int width, int height, int type);
	~Controller();
	void move();
	void draw(Graphics^ g, Bitmap^ bmp);
	void setType(int type);
	std::string getResumen();
};

Controller::Controller(int width, int height, int type)
{
	this->width = width;
	this->height = height;
	this->idx = this->idy = 0;
	this->type = type;
	idy = (type - 1) * 3;
	tacleadasDerecha = tacleadasIzquierda = 0;
}

Controller::~Controller()
{
}

void Controller::move()
{
	switch (type)
	{
	case 1: {
		idx++;
		if (idx > 5) {
			idx = 0;
			idy++;
		}
		if (idy > 2) idy = 0; break;
	}
	case 2: {
		idx++;
		if (idx > 5) {
			idx = 0;
			idy++;
		}
		if (idy > 5) {
			idy = 0;
			idx = 0;
			this->type = 1;
		}
		break;
	}
	case 3: {
		idx--;
		if (idx < 0) {
			idx = 4;
			idy++;
		}
		if (idy > 8) {
			idy = 0;
			idx = 0;
			this->type = 1;
		}
		break;
	}
	}
	
}

void Controller::draw(Graphics^ g, Bitmap^ bmp)
{
	Rectangle sectionShow = Rectangle(idx * width, idy * height, width, height);
	Rectangle sectionForm = Rectangle(0, 0, g->VisibleClipBounds.Width, g->VisibleClipBounds.Height);
	g->DrawImage(bmp, sectionForm, sectionShow, GraphicsUnit::Pixel);
}

void Controller::setType(int type)
{
	this->type = type;
	idy = (type - 1) * 3;
	if (type == 2) {
		tacleadasIzquierda++;
	}
	if (type == 3) {
		tacleadasDerecha++;
	}
}

std::string Controller::getResumen()
{
	return "Tacleadas desde la derecha: " + std::to_string(tacleadasDerecha) + "\n" +
		"Tacleadas desde la izquierda: " + std::to_string(tacleadasIzquierda);
}
