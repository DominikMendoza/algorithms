#pragma once
#include "CCircle.hpp"
#include "CEllipse.hpp"
#include "CRectangle.hpp"
#include "CSquare.hpp"
#include "CTriangle.hpp"
#include "vector"
class CControler {
public:
	CControler(Graphics^ g) {
		srand(time(nullptr));
		x = rand() % int(g->VisibleClipBounds.Width);
		y = rand() % int(g->VisibleClipBounds.Height);
		varA = rand() % (50) + 50;
		varB = rand() % (50) + 50;
	}
	~CControler() {}
	void drawAllFigures(Graphics^ graphic) {
		for (int i = 0; i < figures.size(); i++) figures[i]->drawFig(graphic);
	}
	void moveAllFigures(Graphics^ graphic) {
		for (int i = 0; i < figures.size(); i++) figures[i]->moveFig(graphic);
	}
	void addCircle() {
		figures.push_back(new CCircle(x, y, varA / 2));
	}
	void addEllipse() {
		figures.push_back(new CEllipse(x, y, varA, varB));
	}
	void addRectangle() {
		figures.push_back(new CRectangle(x, y, varA, varB));
	}
	void addSquare() {
		figures.push_back(new CSquare(x, y, varA));
	}
	void addTriangle() {
		figures.push_back(new CTriangle(x, y, varA));
	}

private:
	vector<CFigure*> figures;
	int x, y;
	int varA, varB;
};
