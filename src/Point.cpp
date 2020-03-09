#include "Point.h"
#include <cmath>
#define EPSILON 0.0000001 

Point::Point(double x, double y) :x(x), y(y) {}

double Point::getX() {
	return x;
}

double Point::getY() {
	return y;
}

bool Point::operator < (const Point& p) const {
	if (fabs(x - p.x) <= EPSILON) {
		return y < p.y && fabs(y - p.y) > EPSILON;
	}
	else {
		return x < p.x && fabs(x - p.x) > EPSILON;
	}
}