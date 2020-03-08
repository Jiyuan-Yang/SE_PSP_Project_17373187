#pragma once
#ifndef LINE_H
#define LINE_H

#include <set>
#include "Point.h"

using namespace std;

class Line {
private:
	double a;
	double b;
	double c;
	int x0;
	int y0;
	int x1;
	int y1;
public:
	Line(int x0, int y0, int x1, int y1);
	double getA();
	double getB();
	double getC();
	int getX0();
	int getY0();
	int getX1();
	int getY1();
	static void getLineIntersectPoint(set<Point> &allPoints, const Line& l0, const Line& l1);
};

#endif