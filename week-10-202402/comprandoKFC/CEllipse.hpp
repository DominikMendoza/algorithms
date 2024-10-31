#pragma once
#include "CFigure.hpp"
class CEllipse : public CFigure{
public:
	CEllipse(int x, int y, int minorDiagonal, int mayorDiagonal) : CFigure(x, y) {
		this->minorDiagonal = minorDiagonal;
		this->mayorDiagonal = mayorDiagonal;
	}
	~CEllipse() {}
	void drawFig(Graphics^ graphic) override {
		Pen^ pen = gcnew Pen(Color::FromArgb(rand() % (255), rand() % (255), rand() % (255)));
		graphic->DrawEllipse(pen, x, y, minorDiagonal, mayorDiagonal);
	}
	void moveFig(Graphics^ graphic) override {
		if (x + dx < 0 || x + dx + minorDiagonal > graphic->VisibleClipBounds.Width) {
			dx *= -1;
			dy = 0;
		}
		if (y + dy < 0 || y + dy + mayorDiagonal > graphic->VisibleClipBounds.Height) {
			dx = 0;
			dy *= -1;
		}
		x += dx;
		y += dy;
	}
private:
	int minorDiagonal;
	int mayorDiagonal;
};
