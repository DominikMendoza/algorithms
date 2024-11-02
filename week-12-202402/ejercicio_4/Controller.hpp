#pragma once
using namespace System::Drawing;

class Controller
{
private:
	int x, y;
	int width, height;
	int idx, idy;
	bool animation;
	int cnt;
	float zoom;
public:
	Controller(int x, int y, int width, int height);
	~Controller();
	void draw(Graphics^ g, Bitmap^ bmp);
	void move();
	void restore();
	void setAnimation(bool animation);
	int getCnt();
};

Controller::Controller(int x, int y, int width, int height)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	idx = idy = 0;
	animation = false;
	cnt = 0;
	zoom = 1.6;
}

Controller::~Controller()
{
}

void Controller::draw(Graphics^ g, Bitmap^ bmp)
{
	Rectangle sectionShow = Rectangle(idx * width, idy * height, width, height);
	//Rectangle sectionForm = Rectangle(x, y, width * zoom, height * zoom);
	Rectangle sectionForm = Rectangle(0, 0, g->VisibleClipBounds.Width, g->VisibleClipBounds.Height);
	g->DrawImage(bmp, sectionForm, sectionShow, GraphicsUnit::Pixel);
}

void Controller::move()
{
	if (!animation) return;

	idx++;
	cnt++;
	if (idx > 4) {
		idy++;
		idx = 0;
	}
	if (idy > 3) {
		idx = 1;
		idy = 0;
	}
}

void Controller::restore()
{
	idx = idy = cnt = 0;
}

void Controller::setAnimation(bool animation)
{
	this->animation = animation;
}

int Controller::getCnt()
{
	return this->cnt;
}
