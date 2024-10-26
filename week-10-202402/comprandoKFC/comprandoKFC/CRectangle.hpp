#pragma once
#include "CFigure.hpp"
class CRectangle : public CFigure {
public:
	CRectangle(int x, int y, int height, int width) : CFigure(x, y) {
		this->height = height;
		this->width = width;
	}
	~CRectangle() {}
	void drawFig(Graphics^ graphic) override {
		Pen^ pen = gcnew Pen(Color::FromArgb(rand() % (255), rand() % (255), rand() % (255)));
		graphic->DrawRectangle(pen, x, y, width, height);
	}
	void moveFig(Graphics^ graphic) override {
		if (x + dx < 0 || x + dx + width > graphic->VisibleClipBounds.Width) {
			dx *= -1;
			dy = 0;
		}
		if (y + dy < 0 || y + dy + height > graphic->VisibleClipBounds.Height) {
			dx = 0;
			dy *= -1;
		}
		x += dx;
		y += dy;
	}
private:
	int height;
	int width;
};
