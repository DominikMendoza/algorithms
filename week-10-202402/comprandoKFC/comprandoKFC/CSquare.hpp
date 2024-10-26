#pragma once
#include "CFigure.hpp"
class CSquare : public CFigure {
public:
	CSquare(int x, int y, int side) : CFigure(x, y) {
		this->side = side;
	}
	~CSquare() {}
	void drawFig(Graphics^ graphic) override {
		Pen^ pen = gcnew Pen(Color::FromArgb(rand() % (255), rand() % (255), rand() % (255)));
		graphic->DrawRectangle(pen, x, y, side, side);
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
