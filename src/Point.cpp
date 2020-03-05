#include "Point.h"

Point::Point(double x, double y) :x(x), y(y) {}

double Point::getX() {
	return x;
}

double Point::getY() {
	return y;
}

bool Point::operator < (const Point& p) const {
	if (x == p.x) {
		return y < p.y;
	}
	else {
		return x < p.x;
	}
}