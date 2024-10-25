#pragma once

using namespace System::Drawing;

class Hulk
{
private:
	int x, y, dx, dy;
	int width, height;
	int idx, idy;
	float zoomFig;
public:
	Hulk(int width, int height);
	~Hulk();
	void draw(Graphics^ g, Bitmap^ bmp);
	void move(Graphics^ g, char tecla);
	int getXMasAncho();
	int getYMasAlto();
};

Hulk::Hulk(int width, int height)
{
	x = y = 100;
	dx = dy = 5;
	//idx = idy = 2;
	idx = 0;
	idy = 2;
	zoomFig = 0.8;
	this->width = width;
	this->height = height;
}

Hulk::~Hulk()
{
}

void Hulk::draw(Graphics^ g, Bitmap^ bmp)
{
	// este ancho y alto es de cada frame
	Rectangle section = Rectangle(idx * width, idy * height, width, height);
	Rectangle zoom = Rectangle(x, y, width * zoomFig, height * zoomFig);
	g->DrawImage(bmp, zoom, section, GraphicsUnit::Pixel);
}

void Hulk::move(Graphics^ g, char tecla)
{
	switch (tecla)
	{
		case 'W': {
			if (y + dy < 0) return;
			y -= dy;
			idy = 3; break;
		}
		case 'S': {
			if (y + dy + height * zoomFig > g->VisibleClipBounds.Height) return;
			y += dy;
			idy = 0; break;
		}
		case 'A': {
			if (x + dx < 0) return;
			x -= dx;
			idy = 1; break;
		}
		case 'D': {
			if (x + dx + width * zoomFig > g->VisibleClipBounds.Width) return;
			x += dx;
			idy = 2; break;
		}
	}
	idx++;
	if (idx > 3) {
		idx = 0;
	}
}

int Hulk::getXMasAncho()
{
	return this->x + this->width * this->zoomFig;
}

int Hulk::getYMasAlto()
{
	return this->y + this->height * this->zoomFig;
}
