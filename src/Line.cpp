#include "Line.h"

using namespace std;

Line::Line(int x0, int y0, int x1, int y1) {
	this->x0 = x0;
	this->y0 = y0;
	this->x1 = x1;
	this->y1 = y1;
	// ax+by+c=0
	a = (double)y1 - y0;
	b = (double)x0 - x1;
	c = (double)x1 * y0 - (double)x0 * y1;
}

double Line::getA() {
	return a;
}

double Line::getB() {
	return b;
}

double Line::getC() {
	return c;
}

int Line::getX0() {
	return x0;
}

int Line::getY0() {
	return y0;
}

int Line::getX1() {
	return x1;
}

int Line::getY1() {
	return y1;
}

void Line::getLineIntersectPoint(set<Point>& allPoints, const Line& l0, const Line& l1) {
	double d = l0.a * l1.b - l1.a * l0.b;
	if (d == 0) {
		// two lines has no intersecting point
		return;
	}
	else {
		double x = (l0.b * l1.c - l1.b * l0.c) / d;
		double y = (l1.a * l0.c - l0.a * l1.c) / d;
		allPoints.insert(Point(x, y));
	}

}