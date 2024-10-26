#pragma once
#include "iostream"
using namespace std;
using namespace System;
using namespace System::Drawing;
class CFigure {
protected:
	int x;
	int y;
	int dx;
	int dy;
public:
	CFigure(int x, int y) {
		srand(time(nullptr));
		this->x = x;
		this->y = y;
		this->dx = rand() % (100) + 5;
		this->dy = rand() % (100) + 5;
	}
	~CFigure() {}
	virtual void drawFig(Graphics^ graphic) {}
	virtual void moveFig(Graphics^ graphic) {}
};