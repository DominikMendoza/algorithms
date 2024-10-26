#pragma once
#include "CFigure.hpp"
class CCircle: public CFigure {
public:
	CCircle(int x, int y, int radius) : CFigure(x, y) {
		this->radius = radius;
	}
	~CCircle() {}
	void drawFig(Graphics^ graphic) override {
		Pen^ pen = gcnew Pen(Color::FromArgb(rand() % (255), rand() % (255), rand() % (255)));
		graphic->DrawEllipse(pen, x, y, radius * 2, radius * 2);
	}
	void moveFig(Graphics^ graphic) override {
		if (x + dx < 0 || x + dx + (2 * radius) > graphic->VisibleClipBounds.Width) {
			dx *= -1;
			dy = 0;
		}
		if (y + dy < 0 || y + dy + (2 * radius) > graphic->VisibleClipBounds.Height) {
			dx = 0;
			dy *= -1;
		}
		x += dx;
		y += dy;
	}
private:
	int radius;
};