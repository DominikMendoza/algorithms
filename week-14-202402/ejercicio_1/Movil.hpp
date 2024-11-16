#pragma once
#include <iostream>
using namespace std;
using namespace System::Drawing;
class Movil
{
protected:
	Rectangle* rec;
	int dx, dy, color;
	int idx, idy;
	float zoom;
public:
	Movil(int x, int y, int width, int height, float zoom);
	~Movil();
	virtual void mover(Graphics^ g);
	virtual void dibujar(Graphics^ g, Bitmap^ bmp);
	bool intersect(Rectangle* ext);
	Rectangle* getRectangle();
};

Movil::Movil(int x, int y, int width, int height, float zoom)
{
	idx = idy = 0;
	this->zoom = zoom;
	rec = new Rectangle(x, y, width * zoom, height * zoom);
	dx = dy = 10;
	color = rand() % 15 + 1;
}

Movil::~Movil()
{
	delete rec;
}

void Movil::mover(Graphics^ g)
{
	idx++;
	if (idx > 3) {
		idx = 0;
	}
	if (rec->X + dx < 0 || rec->X + dx + rec->Width > g->VisibleClipBounds.Width) {
		dx *= -1;
	}
	if (rec->Y + dy < 0 || rec->Y + dy + rec->Height > g->VisibleClipBounds.Height) {
		dy *= -1;
	}
	rec->X += dx;
	rec->Y += dy;
}

void Movil::dibujar(Graphics^ g, Bitmap^ bmp)
{
	Rectangle sectionShow = Rectangle(idx * rec->Width / zoom, idy * rec->Height / zoom,
		rec->Width / zoom, rec->Height / zoom);
	g->DrawImage(bmp, *rec, sectionShow, GraphicsUnit::Pixel);
}

bool Movil::intersect(Rectangle* ext)
{
	return this->rec->IntersectsWith(*ext);
}

Rectangle* Movil::getRectangle()
{
	return this->rec;
}
