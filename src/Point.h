#pragma once
class Point {
private:
	double x;
	double y;
public:
	Point(double x, double y);
	double getX();
	double getY();
	bool operator < (const Point& p) const;
};