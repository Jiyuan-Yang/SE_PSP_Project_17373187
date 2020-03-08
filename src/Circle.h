#pragma once

#ifndef CIRCLE_H
#define CIRCLE_H

#include <set>
#include "Point.h"
#include "Line.h"

class Circle {
private:
	double x;
	double y;
	double r;
public:
	Circle(int x, int y, int r);
	double getX();
	double getY();
	double getR();
	static void getLineCircleIntersect(set<Point>& allPoints, Line& l, const Circle& c);
	static void getCircleIntersect(set<Point>& allPoints, const Circle& c0, const Circle& c1);
};

#endif

