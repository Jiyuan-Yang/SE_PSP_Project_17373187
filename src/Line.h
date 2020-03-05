#pragma once
#ifndef LINE_H
#define LINE_H

#include "Point.h"

class Line {
private:
	double a;
	double b;
	double c;
public:
	Line(int x0, int y0, int x1, int y1);
	double getA();
	double getB();
	double getC();
	static Point* getIntersectPoint(const Line& l0, const Line& l1);
};

#endif