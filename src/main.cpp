#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <vector>
#include <set>

#include "Point.h"
#include "Line.h"
#include "Circle.h"

using namespace std;

void getIntersectNum(ifstream& in, ofstream& out);
Line* parseLine(ifstream& in);
Circle* parseCircle(ifstream& in);

int main(int argc, char *argv[]) {
	string inFileName, outFileName;
	for (int i = 1; i < argc; ++i) {
		if (strcmp(argv[i], "-i") == 0) {
			inFileName = argv[++i];
		}
		else if (strcmp(argv[i], "-o") == 0) {
			outFileName = argv[++i];
		}
	}
	if (inFileName.empty() || outFileName.empty()) {
		cout << "ERROR: input/output file path is not specified." << endl;
		return 0;
	}
	
	ifstream in(inFileName);
	ofstream out(outFileName);
	if (!in || !out) {
		cout << "ERROR: failed to open files." << endl;
		return 0;
	}

	getIntersectNum(in, out);

	in.close();
	out.close();
	
	return 0;
}

void getIntersectNum(ifstream& in, ofstream& out) {
	int lineNum;
	in >> lineNum;
	vector<Line> allLines;
	vector<Circle> allCircles;
	set<Point> allPoints;
	for (int i = 0; i < lineNum; ++i) {
		char mark;
		in >> mark;
		if (mark == 'L') {
			Line* newLine = parseLine(in);
			for (int j = 0; j < allLines.size(); ++j) {
				Line::getLineIntersectPoint(allPoints, *newLine, allLines[j]);
			}
			for (int j = 0; j < allCircles.size(); ++j) {
				Circle::getLineCircleIntersect(allPoints, *newLine, allCircles[j]);
			}
			allLines.push_back(*newLine);
		}
		else if (mark == 'C') { 
			Circle* newCircle = parseCircle(in);
			for (int j = 0; j < allLines.size(); ++j) {
				Circle::getLineCircleIntersect(allPoints, allLines[j], *newCircle);
			}
			for (int j = 0; j < allCircles.size(); ++j) {
				Circle::getCircleIntersect(allPoints, *newCircle, allCircles[j]);
			}
			allCircles.push_back(*newCircle);
		}
		else {
			cout << "ERROR: invalid mark character " << mark << "." << endl;
		}
	}
	out << allPoints.size() << endl;
	for (Point p : allPoints) {
		cout << p.getX() << ' ' << p.getY() << endl;
	}
}

Line* parseLine(ifstream& in) {
	int x0, y0, x1, y1;
	in >> x0 >> y0 >> x1 >> y1;
	return new Line(x0, y0, x1, y1);
}

Circle* parseCircle(ifstream& in) {
	int x, y, r;
	in >> x >> y >> r;
	return new Circle(x, y, r);
}