#include <cmath>
#include "Circle.h"

using namespace std;

Circle::Circle(int x, int y, int r) :x(x), y(y), r(r) {}

double Circle::getX() {
	return x;
}

double Circle::getY() {
	return y;
}

double Circle::getR() {
	return r;
}

void Circle::getLineCircleIntersect(set<Point>& allPoints, Line& l, const Circle& c) {
	// find the project point of circle center on the line
	double lineVectorX = (double) l.getX1() - l.getX0();
	double lineVectorY = (double) l.getY1() - l.getY0();
	double lineCircleVectorX = c.x - l.getX0();
	double lineCircleVectorY = c.y - l.getY0();
	double dot = (lineVectorX * lineCircleVectorX + lineVectorY * lineCircleVectorY);
	double modSquare = (lineVectorX * lineVectorX + lineVectorY * lineVectorY);
	double ratio = dot / modSquare;
	// pr for the project point	
	double prX = l.getX0() + ratio * lineVectorX;
	double prY = l.getY0() + ratio * lineVectorY;
	
	double eX = lineVectorX / sqrt(modSquare);
	double eY = lineVectorY / sqrt(modSquare);

	double halfChordLenSquare = c.r * c.r - ((prX - c.x) * (prX - c.x) + (prY - c.y) * (prY - c.y));
	if (halfChordLenSquare < 0) {
		// no intersection
		return;
	}
	double halfChordLen = sqrt(halfChordLenSquare);
	double intersectX0 = prX + halfChordLen * eX;
	double intersectY0 = prY + halfChordLen * eY;
	double intersectX1 = prX - halfChordLen * eX;
	double intersectY1 = prY - halfChordLen * eY;
	allPoints.insert(Point(intersectX0, intersectY0));
	if (halfChordLenSquare > 0) {
		// two different intersections
		allPoints.insert(Point(intersectX1, intersectY1));
	}
}

void Circle::getCircleIntersect(set<Point>& allPoints, const Circle& c0, const Circle& c1) {
	double distance = sqrt((c0.x - c1.x) * (c0.x - c1.x) + (c0.y - c1.y) * (c0.y - c1.y));
	if (distance > c0.r + c1.r || distance < abs(c0.r - c1.r)) {
		// no intersection
		return;
	}
	// use Law of cosines to get the angle `a` between distance vector and radium vector
	double a = acos((c0.r * c0.r + distance * distance - c1.r * c1.r) / (2 * c0.r * distance));
	// get the angle `t` between distance vector and x-axis
	double t = atan2(c1.y - c0.y, c1.x - c0.x);
	double intersectX0 = c0.x + c0.r * cos(t + a);
	double intersectY0 = c0.y + c0.r * sin(t + a);
	double intersectX1 = c0.x + c0.r * cos(t - a);
	double intersectY1 = c0.y + c0.r * sin(t - a);
	allPoints.insert(Point(intersectX0, intersectY0));
	if (distance > abs(c0.r - c1.r) && distance < c0.r + c1.r) {
		// 2 interactions
		allPoints.insert(Point(intersectX1, intersectY1));
	}
}