#pragma once
#include "CFigure.hpp"
class CTriangle : public CFigure {
public:
	CTriangle(int x, int y, int side) : CFigure(x, y) {
		this->side = side;
	}
	~CTriangle() {}
	void drawFig(Graphics^ graphic) override {
		Pen^ pen = gcnew Pen(Color::FromArgb(rand() % (255), rand() % (255), rand() % (255)));
		cli::array<Point>^ vertices = {
			Point(x + side / 2, y),
			Point(x, y + side),
			Point(x + side, y + side)
		};
		graphic->DrawPolygon(pen, vertices);
	}
	void moveFig(Graphics^ graphic) override {
		if (x + dx < 0 || x + dx + side > graphic->VisibleClipBounds.Width) {
			dx *= -1;
			dy = 0;
		}
		if (y + dy < 0 || y + dy + side > graphic->VisibleClipBounds.Height) {
			dx = 0;
			dy *= -1;
		}
		x += dx;
		y += dy;
	}
private:
	int side;
};